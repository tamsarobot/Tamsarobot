# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "odometry4: 1 messages, 0 services")

set(MSG_I_FLAGS "-Iodometry4:/home/hindigo/catkin_ws/src/odometry4/msg;-Igeometry_msgs:/opt/ros/indigo/share/geometry_msgs/cmake/../msg;-Inav_msgs:/opt/ros/indigo/share/nav_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/indigo/share/sensor_msgs/cmake/../msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg;-Irosserial_arduino:/opt/ros/indigo/share/rosserial_arduino/cmake/../msg;-Itf:/opt/ros/indigo/share/tf/cmake/../msg;-Iodometry4:/home/hindigo/catkin_ws/src/odometry4/msg;-Iactionlib_msgs:/opt/ros/indigo/share/actionlib_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(odometry4_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/hindigo/catkin_ws/src/odometry4/msg/MyOdometry4.msg" NAME_WE)
add_custom_target(_odometry4_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "odometry4" "/home/hindigo/catkin_ws/src/odometry4/msg/MyOdometry4.msg" "std_msgs/Header"
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(odometry4
  "/home/hindigo/catkin_ws/src/odometry4/msg/MyOdometry4.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/odometry4
)

### Generating Services

### Generating Module File
_generate_module_cpp(odometry4
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/odometry4
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(odometry4_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(odometry4_generate_messages odometry4_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/hindigo/catkin_ws/src/odometry4/msg/MyOdometry4.msg" NAME_WE)
add_dependencies(odometry4_generate_messages_cpp _odometry4_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(odometry4_gencpp)
add_dependencies(odometry4_gencpp odometry4_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS odometry4_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(odometry4
  "/home/hindigo/catkin_ws/src/odometry4/msg/MyOdometry4.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/odometry4
)

### Generating Services

### Generating Module File
_generate_module_lisp(odometry4
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/odometry4
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(odometry4_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(odometry4_generate_messages odometry4_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/hindigo/catkin_ws/src/odometry4/msg/MyOdometry4.msg" NAME_WE)
add_dependencies(odometry4_generate_messages_lisp _odometry4_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(odometry4_genlisp)
add_dependencies(odometry4_genlisp odometry4_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS odometry4_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(odometry4
  "/home/hindigo/catkin_ws/src/odometry4/msg/MyOdometry4.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/odometry4
)

### Generating Services

### Generating Module File
_generate_module_py(odometry4
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/odometry4
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(odometry4_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(odometry4_generate_messages odometry4_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/hindigo/catkin_ws/src/odometry4/msg/MyOdometry4.msg" NAME_WE)
add_dependencies(odometry4_generate_messages_py _odometry4_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(odometry4_genpy)
add_dependencies(odometry4_genpy odometry4_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS odometry4_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/odometry4)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/odometry4
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(odometry4_generate_messages_cpp geometry_msgs_generate_messages_cpp)
add_dependencies(odometry4_generate_messages_cpp nav_msgs_generate_messages_cpp)
add_dependencies(odometry4_generate_messages_cpp sensor_msgs_generate_messages_cpp)
add_dependencies(odometry4_generate_messages_cpp std_msgs_generate_messages_cpp)
add_dependencies(odometry4_generate_messages_cpp rosserial_arduino_generate_messages_cpp)
add_dependencies(odometry4_generate_messages_cpp tf_generate_messages_cpp)
add_dependencies(odometry4_generate_messages_cpp odometry4_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/odometry4)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/odometry4
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(odometry4_generate_messages_lisp geometry_msgs_generate_messages_lisp)
add_dependencies(odometry4_generate_messages_lisp nav_msgs_generate_messages_lisp)
add_dependencies(odometry4_generate_messages_lisp sensor_msgs_generate_messages_lisp)
add_dependencies(odometry4_generate_messages_lisp std_msgs_generate_messages_lisp)
add_dependencies(odometry4_generate_messages_lisp rosserial_arduino_generate_messages_lisp)
add_dependencies(odometry4_generate_messages_lisp tf_generate_messages_lisp)
add_dependencies(odometry4_generate_messages_lisp odometry4_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/odometry4)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/odometry4\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/odometry4
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(odometry4_generate_messages_py geometry_msgs_generate_messages_py)
add_dependencies(odometry4_generate_messages_py nav_msgs_generate_messages_py)
add_dependencies(odometry4_generate_messages_py sensor_msgs_generate_messages_py)
add_dependencies(odometry4_generate_messages_py std_msgs_generate_messages_py)
add_dependencies(odometry4_generate_messages_py rosserial_arduino_generate_messages_py)
add_dependencies(odometry4_generate_messages_py tf_generate_messages_py)
add_dependencies(odometry4_generate_messages_py odometry4_generate_messages_py)
