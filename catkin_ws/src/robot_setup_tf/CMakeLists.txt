cmake_minimum_required(VERSION 2.8.3)
project(robot_setup_tf)


find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  tf
)

catkin_package(

)

# include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
)

## Declare a cpp executable
 add_executable(robot_setup_tf src/tf_broadcaster.cpp)

## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
add_dependencies(robot_setup_tf robot_setup_tf_generate_messages_cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(robot_setup_tf
   ${catkin_LIBRARIES}
 )

