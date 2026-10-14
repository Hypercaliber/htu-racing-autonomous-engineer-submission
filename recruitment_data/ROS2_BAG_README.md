# ROS 2 Bag Quick Guide

This repository includes a recorded ROS 2 bag containing sensor data for the recruitment task.

## Inspect the Bag

From the project root:

```bash
ros2 bag info recruitment_data/recorded_run
```

This shows the bag duration, message count, topics, message types, and recording information.

## Play the Bag

```bash
cd recruitment_data

ros2 bag play recorded_run \
  --qos-profile-overrides-path qos_override.yaml
```

Always use the provided QoS configuration when replaying the bag.

## Useful Playback Options

Play continuously in a loop:

```bash
ros2 bag play recorded_run \
  --qos-profile-overrides-path qos_override.yaml \
  --loop
```

Play at a different speed:

```bash
ros2 bag play recorded_run \
  --qos-profile-overrides-path qos_override.yaml \
  --rate 0.5
```

`0.5` plays at half speed, while `2.0` plays at twice the normal speed.

While the bag is playing, press **Space** in the playback terminal to pause/resume.

## Inspect the Published Data

List active topics:

```bash
ros2 topic list
```

Check a topic's message type and publisher/subscriber information:

```bash
ros2 topic info /velodyne_points
```

Inspect individual messages:

```bash
ros2 topic echo /imu/data
```

Check the publishing frequency:

```bash
ros2 topic hz /velodyne_points
```

## Provided Topics

```text
/zed/left/image_rect_color
/velodyne_points
/imu/data
/ground_truth/odom
/clock
```

For additional commands and options:

```bash
ros2 bag play --help
ros2 bag info --help
```
