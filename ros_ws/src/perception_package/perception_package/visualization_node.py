import cv2
import math
import message_filters
import rclpy
from rclpy.node import Node
from cv_bridge import CvBridge
from nav_msgs.msg import Odometry
from sensor_msgs.msg import Image, Imu
from custom_interfaces.msg import BoundingBoxArray

# Yaw calculation function (Orientation)
def quaternion_to_yaw(q):
    siny_cosp = 2 * (q.w * q.z + q.x * q.y)
    cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z)
    return math.atan2(siny_cosp, cosy_cosp)

"""
Node: Visualization

Inputs:
    /zed/left/image_rect_color
    /perception/yolo_bboxes
    /ground_truth/odom
    /imu/data

Output:
    /perception/debug_image
"""

class VisualizationNode(Node):
    def __init__(self):
        super().__init__('visualization_node')

        # Conversion back and forth between OpenCV and ROS
        self.bridge = CvBridge()

        # presistent last instance of odometery and IMU data
        self.latest_odom = None
        self.latest_imu = None

        # matching class names to color
        self.class_names = {0: 'blue_cone', 1: 'yellow_cone', 2: 'orange_cone', 3: 'orange_cone'}  
 
        self.odom_sub = self.create_subscription(
            Odometry,
            '/ground_truth/odom',
            self.odom_callback,
            10
        )

        self.imu_sub = self.create_subscription(
            Imu,
            '/imu/data',
            self.imu_callback,
            10
        )


        # message filters let's us combine multiple topics into one callback
        # Synchronizing bbox and camera streams
        self.image_sub = message_filters.Subscriber(self, Image, '/zed/left/image_rect_color')
        self.bbox_sub = message_filters.Subscriber(self, BoundingBoxArray, '/perception/yolo_bboxes')

        # ApproximateTimeSync is what actually syncs the streams
        self.time_sync = message_filters.ApproximateTimeSynchronizer(
            [self.image_sub, self.bbox_sub], queue_size=10, slop=0.1
        ) # If the timestamps match within 0.1 seconds then the callback gets activated
        self.time_sync.registerCallback(self.synced_callback)
        # publishes to the debug_image topic
        self.debug_image_publisher_ = self.create_publisher(Image, '/perception/debug_image', 10)

    # Just updates the last value of odom accordingly with the stream
    def odom_callback(self, msg):
        self.latest_odom = msg   
    # Just updatess the last value of IMU accordingly with the stream
    def imu_callback(self, msg):
        self.latest_imu = msg
    # Callback for both streams, needs to pass the datatype of each topic inside the argument
    def synced_callback(self, image_msg, bbox_msg):
        cv_image = self.bridge.imgmsg_to_cv2(image_msg, desired_encoding = 'bgr8')

        # for each loop to draw boxes
        for box in bbox_msg.boxes:
            cv2.rectangle(
                cv_image,
                (int (box.x1), int(box.y1)),
                (int (box.x2), int(box.y2)),
                (0, 255, 0), #green 
                2
            )

            class_name = self.class_names.get(box.class_id, f'UNMAPPED_{box.class_id}')
            label = f'{class_name}: {box.confidence:.2f}'

            # Puts the label above the boxes
            cv2.putText(
                cv_image,
                label,
                (int(box.x1), int(box.y1) - 10),
                cv2.FONT_HERSHEY_COMPLEX,
                0.5,
                (0, 255, 0),
                2
            )

        # Puts Postion and Velocity on the top left corner of the screen 
        if self.latest_odom is not None:
            pos = self.latest_odom.pose.pose.position
            vel = self.latest_odom.twist.twist.linear
            orientation = self.latest_odom.pose.pose.orientation
            yaw_rad = quaternion_to_yaw(orientation)
            yaw_deg = math.degrees(yaw_rad)

            cv2.putText(
                cv_image, 
                f'Position: ({pos.x:.2f}, {pos.y:.2f})',
                (10, 30), 
                cv2.FONT_HERSHEY_SIMPLEX, 
                0.6, 
                (0, 0, 255), 
                2
            )

            cv2.putText(
                cv_image,
                f'Velocity aka vroooom: {vel.x:.2f}',
                (10, 55), 
                cv2.FONT_HERSHEY_SIMPLEX, 
                0.6, 
                (0, 0, 255), 
                2
            )

            cv2.putText(
                cv_image,
                f'Orientation: {yaw_deg:.1f} deg', (10, 105),
                cv2.FONT_HERSHEY_SIMPLEX, 
                0.6, 
                (0, 0, 255), 
                2
            )

        # Puts acceleration on the top left corner of the screen
        if self.latest_imu is not None:
            accel = self.latest_imu.linear_acceleration
            cv2.putText(
                cv_image,
                f'Acceleration: {accel.x:.2f}',
                (10, 80), 
                cv2.FONT_HERSHEY_SIMPLEX, 
                0.6, 
                (0, 0, 255), 
                2
            )

        # Reconverts the CV2 to ROS IMAGE, sticks the header, and publishes it
        debug_image = self.bridge.cv2_to_imgmsg(cv_image, encoding = 'bgr8')
        debug_image.header = image_msg.header
        self.debug_image_publisher_.publish(debug_image)


def main(args = None):

    #Initialize the lidar Node
    rclpy.init(args = args)
    node = VisualizationNode()

    # Run it in a loop
    rclpy.spin(node)

    # If the loop ends (Ctrl + C) then destroy the node
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()