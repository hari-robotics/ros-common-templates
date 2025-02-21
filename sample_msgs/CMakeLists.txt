cmake_minimum_required(VERSION 3.0.2)
project(sample_msgs)

find_package(catkin REQUIRED)
find_package(catkin REQUIRED COMPONENTS 
  roscpp 
  rospy 
  std_msgs 
  message_generation
)

add_message_files(
  FILES
  Point.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs  # Or other packages containing msgs
)

catkin_package(
 CATKIN_DEPENDS message_runtime
)