cmake_minimum_required(VERSION 2.8.3)
project(odometry4)


find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  nav_msgs
  roscpp
  rospy
  rosserial_arduino
  sensor_msgs
  std_msgs
  tf
  message_generation 
)


## Generate messages in the 'msg' folder
 add_message_files(
   FILES
   MyOdometry4.msg
 )

## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   geometry_msgs   nav_msgs   sensor_msgs   std_msgs rosserial_arduino tf odometry4
 )


catkin_package(
  #/INCLUDE_DIRS include
  #LIBRARIES   ~/sketchbook/libraries/roslib/odometry4
  CATKIN_DEPENDS message_runtime geometry_msgs nav_msgs roscpp rospy rosserial_arduino sensor_msgs  std_msgs tf 
  #DEPENDS ~/sketchbook/libraries/roslib/odometry4
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
)

## Declare a cpp library
# add_library(odometry4
#   src/${PROJECT_NAME}/odometry_publisher.cpp
# )

## Declare a cpp executable
add_executable(odometry4 src/odometry_publisher.cpp)

## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
add_dependencies(odometry4 odometry_publisher_generate_message_cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(odometry4
   ${catkin_LIBRARIES}
 )


