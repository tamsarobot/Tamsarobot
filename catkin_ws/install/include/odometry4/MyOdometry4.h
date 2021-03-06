/* Software License Agreement (BSD License)
 *
 * Copyright (c) 2011, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of Willow Garage, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Auto-generated by genmsg_cpp from file /home/hindigo/catkin_ws/src/odometry4/msg/MyOdometry4.msg
 *
 */


#ifndef ODOMETRY4_MESSAGE_MYODOMETRY4_H
#define ODOMETRY4_MESSAGE_MYODOMETRY4_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace odometry4
{
template <class ContainerAllocator>
struct MyOdometry4_
{
  typedef MyOdometry4_<ContainerAllocator> Type;

  MyOdometry4_()
    : header()
    , Rt_pulse(0.0)
    , Lt_pulse(0.0)  {
    }
  MyOdometry4_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , Rt_pulse(0.0)
    , Lt_pulse(0.0)  {
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef double _Rt_pulse_type;
  _Rt_pulse_type Rt_pulse;

   typedef double _Lt_pulse_type;
  _Lt_pulse_type Lt_pulse;




  typedef boost::shared_ptr< ::odometry4::MyOdometry4_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::odometry4::MyOdometry4_<ContainerAllocator> const> ConstPtr;

}; // struct MyOdometry4_

typedef ::odometry4::MyOdometry4_<std::allocator<void> > MyOdometry4;

typedef boost::shared_ptr< ::odometry4::MyOdometry4 > MyOdometry4Ptr;
typedef boost::shared_ptr< ::odometry4::MyOdometry4 const> MyOdometry4ConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::odometry4::MyOdometry4_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::odometry4::MyOdometry4_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace odometry4

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'nav_msgs': ['/opt/ros/indigo/share/nav_msgs/cmake/../msg'], 'odometry4': ['/home/hindigo/catkin_ws/src/odometry4/msg', '/home/hindigo/catkin_ws/src/odometry4/msg'], 'rosserial_arduino': ['/opt/ros/indigo/share/rosserial_arduino/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'tf': ['/opt/ros/indigo/share/tf/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::odometry4::MyOdometry4_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::odometry4::MyOdometry4_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::odometry4::MyOdometry4_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::odometry4::MyOdometry4_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::odometry4::MyOdometry4_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::odometry4::MyOdometry4_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::odometry4::MyOdometry4_<ContainerAllocator> >
{
  static const char* value()
  {
    return "207d0e59e086a2e869b58bd38f957849";
  }

  static const char* value(const ::odometry4::MyOdometry4_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x207d0e59e086a2e8ULL;
  static const uint64_t static_value2 = 0x69b58bd38f957849ULL;
};

template<class ContainerAllocator>
struct DataType< ::odometry4::MyOdometry4_<ContainerAllocator> >
{
  static const char* value()
  {
    return "odometry4/MyOdometry4";
  }

  static const char* value(const ::odometry4::MyOdometry4_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::odometry4::MyOdometry4_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
float64 Rt_pulse\n\
float64 Lt_pulse\n\
\n\
 \n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::odometry4::MyOdometry4_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::odometry4::MyOdometry4_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.Rt_pulse);
      stream.next(m.Lt_pulse);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct MyOdometry4_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::odometry4::MyOdometry4_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::odometry4::MyOdometry4_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "Rt_pulse: ";
    Printer<double>::stream(s, indent + "  ", v.Rt_pulse);
    s << indent << "Lt_pulse: ";
    Printer<double>::stream(s, indent + "  ", v.Lt_pulse);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ODOMETRY4_MESSAGE_MYODOMETRY4_H
