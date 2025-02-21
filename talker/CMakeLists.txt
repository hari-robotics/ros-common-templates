cmake_minimum_required(VERSION 3.0.2)
project(talker)

find_package(catkin REQUIRED)
find_package(catkin REQUIRED COMPONENTS 
  roscpp 
  std_msgs 
  sample_msgs
)

catkin_package()

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_node src/talker.cpp)
target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
)

install(TARGETS ${PROJECT_NAME}_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)