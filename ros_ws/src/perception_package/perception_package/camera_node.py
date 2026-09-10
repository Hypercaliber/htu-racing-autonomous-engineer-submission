import os
import rclpy
from ament_index_python.packages import get_package_share_directory
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from ultralytics import YOLO

from custom_interfaces.msg import BoundingBox, BoundingBoxArray

"""
Node: Camera Perception

Input:
    /zed/left/image_rect_color

Output:
    /perception/yolo_bboxes
"""

class CameraNode(Node):

    def __init__(self):
        super().__init__('camera_node')

        model_path = os.path.join( 
            get_package_share_directory('perception_package'),
            'models',
            'yolov26.pt'
        )

        self.model =  YOLO(model_path)

        self.bridge = CvBridge()

        self.subscription = self.create_subscription(
            Image,
            '/zed/left/image_rect_color',
            self.image_callback,
            10)

        self.publisher_ = self.create_publisher(
            BoundingBoxArray,
            '/perception/yolo_bboxes',
            10)

    def image_callback(self, msg):

        # Covert the images into something that YOLO can use
        cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')

        # Actually run the detection
        results = self.model(cv_image)

        # Building the message, msg.header resuses the camera frame's timestamp/frame_id
        bbox_array = BoundingBoxArray()
        bbox_array.header = msg.header

        for box in results[0].boxes:
            bbox = BoundingBox()
            bbox.class_id = int(box.cls[0])
            bbox.confidence = float(box.conf[0])
            x1, y1, x2, y2 = box.xyxy[0]
            bbox.x1 = float(x1)
            bbox.y1 = float(y1)
            bbox.x2 = float(x2)
            bbox.y2 = float(y2)
            bbox_array.boxes.append(bbox)

        self.publisher_.publish(bbox_array)

def main(args = None):

    #Initialize the Camera Node
    rclpy.init(args = args)
    node = CameraNode()

    #Run it in a loop
    rclpy.spin(node)

    # If the loop ends (Ctrl + C) then destroy the node
    node.destroy_node()
    rclpy.shutdown()
                         

if __name__ == '__main__':
    main()