# ROS Common Templates
This project intends to provide some basic templates for ROS beginners, all the package were tested with ROS noetic on ubuntu20.04

## Contents
* `bringup`: contains all the launch file for this project
* `talker`: contains a simple publisher written in c++
* `listener`: contains a simple subscriber written in c++

## Pre-requirements
~~For `bringup`, `talker`, and `listener` package, you do not need anything aside from ROS.~~

Now `sample_msgs` is required by `talker` and `listener`.

## How to install
```bash
cd {Your-Workspace-Name}
mkdir src
cd src
git clone git@github.com:hari-robotics/ros-common-templates.git
```
Then go back to the primary folder, and you can compile this project.

## TODOs
- [x] ROS msgs
- [ ] Service
- [ ] ROS param
- [ ] timers
- [ ] TF
- [ ] python integration
- [ ] some simulation and more stuff that can introduce rosbag, SLAM, navigation, mapping and more