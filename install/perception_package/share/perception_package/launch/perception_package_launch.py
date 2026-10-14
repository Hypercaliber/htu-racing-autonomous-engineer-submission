from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='perception_package',
            executable='camera_node',
            name='camera_node',
            output='screen'
        ),
        Node(
            package='perception_package',
            executable='lidar_node',
            name='lidar_node',
            output='screen'
        ),
        Node(
            package='perception_package',
            executable='visualization_node',
            name='visualization_node',
            output='screen'
        ),
    ])