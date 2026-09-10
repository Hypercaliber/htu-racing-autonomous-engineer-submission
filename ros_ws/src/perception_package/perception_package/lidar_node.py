import tf2_sensor_msgs
import rclpy
import numpy as np
import sensor_msgs_py.point_cloud2 as pc2
from tf2_ros import Buffer, TransformListener
from sensor_msgs.msg import PointCloud2, PointField
from sklearn.cluster import DBSCAN
from rclpy.node import Node

"""
Node: LiDAR Perception

Input:
    /velodyne_points

Outputs:
    /perception/roi_points
    /perception/non_ground_points
    /perception/clustered_points

Thanks for the hint
Coordinate Frames:
    Source:
        The frame provided by the incoming PointCloud2 message
        (msg.header.frame_id)

    Target:
        base_footprint

The LiDAR points should be transformed from the sensor frame into
base_footprint before processing so that the coordinates are aligned
with the vehicle.

If this is unfamiliar, briefly read about ROS 2 TF2 and coordinate
frame transformations.
"""


class LidarNode(Node):

    def __init__(self):
        super().__init__('lidar_node')

        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        self.subscription = self.create_subscription(
            PointCloud2, '/velodyne_points', self.pointcloud2_callback, 10)

        self.roi_publisher_ = self.create_publisher(PointCloud2, '/perception/roi_points', 10)
        self.non_ground_publisher_ = self.create_publisher(PointCloud2, '/perception/non_ground_points', 10)
        self.clustered_publisher_ = self.create_publisher(PointCloud2, '/perception/clustered_points', 10)

        # defines the field type that will be used later inside of the pc2.create_cloud() fucntion
        # it's inside the init function so that it will presist across calls and saves resources
        self.clustered_fields = [
            PointField(name='x', offset=0, datatype=PointField.FLOAT32, count=1),
            PointField(name='y', offset=4, datatype=PointField.FLOAT32, count=1),
            PointField(name='z', offset=8, datatype=PointField.FLOAT32, count=1),
            PointField(name='intensity', offset=12, datatype=PointField.FLOAT32, count=1),
        ]


    def pointcloud2_callback(self, msg):

        # if the look_up is called before any messages get sent (which usually happens at start up)
        # then there is an exception thrown. Try/except has been implemented to account for that
        
        try:
            transform = self.tf_buffer.lookup_transform(
                'base_footprint', # target
                msg.header.frame_id, #source
                msg.header.stamp #time
            )

        except Exception as e:
            self.get_logger().warn(f"Couldn't get the tranform: {e}")
            return
        
        transformed_cloud = tf2_sensor_msgs.do_transform_cloud(msg, transform)

        # focusing on one area and discarding other coordinates (region of interest aka ROI)
        points = pc2.read_points(transformed_cloud, skip_nans=True)

        mask=(
            (points['x'] > 0.0) & (points['x'] < 15.0) &
            (np.abs(points['y']) < 8.0) &
            (points['z'] > -0.5) & (points['z'] < 1.5)
        )

        roi_points = points[mask]
        roi_cloud = pc2.create_cloud(transformed_cloud.header, transformed_cloud.fields, roi_points)
        self.roi_publisher_.publish(roi_cloud)

        # removing the ground
        non_ground_mask = roi_points['z'] > 0.04
        non_ground_points = roi_points[non_ground_mask]
        non_ground_cloud = pc2.create_cloud(transformed_cloud.header, transformed_cloud.fields, non_ground_points)
        self.non_ground_publisher_.publish(non_ground_cloud)

        # clustering the points together
        xyz = np.stack([non_ground_points['x'], non_ground_points['y'], non_ground_points['z']], axis = 1)
        clustering = DBSCAN(eps = 0.5, min_samples = 1).fit(xyz)
        labels = clustering.labels_

        # discarding any points that don't map to a cluster (labels assigns them the value -1)
        valid_mask = labels != -1
        clustered_points_only = non_ground_points[valid_mask]
        clustering_labels = labels[valid_mask]

        # defining the new array length and data type 
        clustered_points_with_labels = np.zeros(len(clustered_points_only), dtype=[
            ('x', np.float32), ('y', np.float32), ('z', np.float32), ('intensity', np.float32)
        ])

        # matching the clustered points to the labels (intensity is just the label int converted to a 32float)
        clustered_points_with_labels['x'] = clustered_points_only['x']
        clustered_points_with_labels['y'] = clustered_points_only['y']
        clustered_points_with_labels['z'] = clustered_points_only['z']
        clustered_points_with_labels['intensity'] = clustering_labels.astype(np.float32)

        clustered_cloud = pc2.create_cloud(
            transformed_cloud.header,
            self.clustered_fields,
            clustered_points_with_labels
        )

        self.clustered_publisher_.publish(clustered_cloud)




def main(args = None):

    #Initialize the lidar Node
    rclpy.init(args = args)
    node = LidarNode()

    # Run it in a loop
    rclpy.spin(node)

    # If the loop ends (Ctrl + C) then destroy the node
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()