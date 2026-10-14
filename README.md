# HTU Racing — Autonomous Recruitment Task (Task 2)

ROS 2 Jazzy perception system built for the HTU Racing Autonomous Engineer recruitment task. It processes a recorded Formula Student sensor run (camera, LiDAR, IMU, odometry) and produces cone detection, a four-stage LiDAR pipeline, and a combined debug visualization.

Full write-up (algorithms, design decisions, parameters, limitations) is in `Task2_Documentation.docx`. This README just covers what's here and how to run it.

## What's included

- `ros_ws/src/perception_package/` — the three developed nodes:
  - `camera_node.py` — runs a pretrained YOLO model on the camera stream, publishes detections.
  - `lidar_node.py` — transforms LiDAR data into the vehicle frame, then crops (ROI), removes the ground, and clusters the remaining points into cones.
  - `visualization_node.py` — combines the camera feed, detections, odometry, and IMU into one annotated debug image.
- `ros_ws/src/custom_interfaces/` — custom message definitions (`BoundingBox`, `BoundingBoxArray`) used to publish detection results.
- `ros_ws/src/perception_package/launch/perception.launch.py` — starts all three nodes together.
- `recruitment_data/` — the provided ROS 2 bag, QoS override config, and reference demo video (bag/video excluded from git, see `.gitignore` — download separately if needed).
- `tools/visualize.sh` — launches RViz2 and rqt_image_view pre-configured for this system's topics.
- `recruitment_data/recorded_run/recorded_run_0.db3` is too large to include inside of the repo, it will be provided in this link: 
https://drive.google.com/drive/folders/1NpPVHW_kUiBIHy2ukb5eCYurYTxiEyrp?usp=sharing
Also here is the Youtube video that has a working video demo:
https://youtu.be/rhkTYR_Uud0?si=cAmxRDqcULVeyixm
## Requirements

- Ubuntu 24.04 (Noble)
- ROS 2 Jazzy
- Python 3.12, with a virtual environment (`--system-site-packages`) for pip dependencies

## Setup

```bash
source /opt/ros/jazzy/setup.bash

sudo apt update
grep -vE '^\s*(#|$)' apt-packages.txt | xargs sudo apt install -y

python3 -m venv --system-site-packages .venv
source .venv/bin/activate
python -m pip install --upgrade pip
python -m pip install -r requirements.txt
```

Download the bag from the provided Drive link and extract it into `recruitment_data/recorded_run/` if it isn't already there.

## Build

```bash
cd ros_ws
python3 -m colcon build
source install/setup.bash
```

**Important:** always run `python3 -m colcon build` (not plain `colcon build`) with the virtual environment active. Otherwise the generated node executables link against the system Python instead of the venv, and fail to import `ultralytics`/`scikit-learn` at runtime.

## Running the system

Three terminals, each needs `source /opt/ros/jazzy/setup.bash` (and the venv + `ros_ws/install/setup.bash` for the launch terminal):

**Terminal 1 — play the recording**
```bash
cd recruitment_data
ros2 bag play recorded_run --qos-profile-overrides-path qos_override.yaml --loop
```

**Terminal 2 — run the perception system**
```bash
source .venv/bin/activate
source ros_ws/install/setup.bash
ros2 launch perception_package perception.launch.py
```

**Terminal 3 — visualize**
```bash
./tools/visualize.sh base_footprint
```

In RViz, check the ROI / Non-Ground / Clustered Points displays to see each LiDAR stage, and set Clustered Points' Color Transformer to **Intensity** to see individual cones in distinct colors. In rqt_image_view, select `/perception/debug_image` for the annotated camera output.

## Topics published

| Node | Publishes | Type |
|---|---|---|
| camera_node | `/perception/yolo_bboxes` | `custom_interfaces/BoundingBoxArray` |
| lidar_node | `/perception/roi_points` | `sensor_msgs/PointCloud2` |
| lidar_node | `/perception/non_ground_points` | `sensor_msgs/PointCloud2` |
| lidar_node | `/perception/clustered_points` | `sensor_msgs/PointCloud2` |
| visualization_node | `/perception/debug_image` | `sensor_msgs/Image` |

## Known limitations

Ground removal uses a fixed height threshold tuned visually for this specific flat track (wouldn't generalize to sloped terrain), and the LiDAR/DBSCAN/synchronizer parameters were tuned by eye against this one recording rather than validated analytically. See `Task2_Documentation.docx`, Section 7, for the complete list.
