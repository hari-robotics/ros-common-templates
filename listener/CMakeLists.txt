cmake_minimum_required(VERSION 3.0.2)
project(listener)

add_compile_options(-std=c++17)

find_package(catkin REQUIRED)
find_package(catkin REQUIRED COMPONENTS 
    roscpp
    std_msgs
)

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

catkin_package()

add_executable(${PROJECT_NAME}_node src/listener.cpp)

target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
)

install(TARGETS ${PROJECT_NAME}_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)