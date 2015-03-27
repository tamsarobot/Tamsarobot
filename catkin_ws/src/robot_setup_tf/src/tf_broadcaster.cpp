/*CATKIN 패키지 만들기
  catkin-create-pkg robot_setup_tf roscpp tf geometry_msgs
  rospack profile
  copy tf_boroadcaster.cpp to src
  edit CmakeList.txt/package.xml
 -->파일참조
  catkin_make 
*/
/*실행
  roscore
  rosrun robot_setup_tf robot_setup_tf
  rosrun rviz rviz -->TF 로 확인*/
#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "robot_tf_publisher");
  ros::NodeHandle n;

  ros::Rate r(100);

  tf::TransformBroadcaster broadcaster;

  while(n.ok()){
    broadcaster.sendTransform(
      tf::StampedTransform(
        tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.158, 0.0, 0.089)),
        ros::Time::now(),"base_link", "laser"));
broadcaster.sendTransform(
      tf::StampedTransform(
        tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.0, 0.25, 0.074)),
        ros::Time::now(),"base_link", "leftwheel"));
 broadcaster.sendTransform(
      tf::StampedTransform(
        tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.0, -0.25, 0.074)),
        ros::Time::now(),"base_link", "rightwheel"));
    r.sleep();
  
  }
}

