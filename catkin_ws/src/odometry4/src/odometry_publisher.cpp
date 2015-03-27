/*PC side ROS :////////// odometry_publisher/////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
2014.6.15		

아두이노에서 크루즈코아 및 스텝 펄스를 받아 풀오도메트리 데이터로 뿌려주는 프로그램

ODOMETRY_PUBLISHER PACKAGE CATKIN_MAKE 하기 
-----------------------------------------------------------
1.create odometry4 package
$catkin-create-pkg odometr4 std_msgs rospy roscpp rosserial_arduino nav_msgs geometry_msgs sensor_msgs tf
$rosmake odometry4
copy odometry_publisher.cpp to /src

2.
Create ros_lib in sketchbook/library folder
$source ~/ros_workspace/install/setup.bash
$rosrun rosserial_arduino make_libraries.py ~/sketchbook/libraries odometry4
실행하기

3.
Create Header MyOdometry4.h in ros_lib
$cd  ~/ros_workspace
$catkin_make
-->sketchbook/libraries/odometry4/Myodometry4.h 생성

4.
$roscore
$rosrun rosserial_python serial_node.py /dev/ttyACM0
$rosrun odometry4 odometry4
-->그냥 깜빡일뿐
확인하기 위해서는
$rostopic echo /odom
*/
#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include "std_msgs/String.h"
//#include "std_msgs/Float64.h"
#include "odometry4/MyOdometry4.h"
//----------------------------------------------------------
#include <iostream>
#include <fcntl.h>
#include <string.h>
//#include <stdio.h>
using namespace std;

//Define constants
const char COMM_PORT[] = "/dev/ttyUSB0";
const int PACKET_SIZE = 8;
//const int SAMPLES = 2;


//Define global variables
int file_descriptor;
//short angle_int;
//float rate_float;
//float angle_float;
double pulsePerMeter=5527.965;
double Rt_pulse;
double Lt_pulse;
double Rt_pulse_now;
double Rt_pulse_before;
double Lt_pulse_now;
double Lt_pulse_before;
double d_cruze;
double gAngle_before=0;
double gAngle_now=0;
double gAngle;
double gRate;
double gRate_rad;
double gRate_rad_before;
double pi=3.141592;
double duration;
//-----------------------------------------------------------
//----------------함수----------------------------------------

void chatterCallback(const odometry4::MyOdometry4::ConstPtr& msg)
{

  
  Rt_pulse=msg->Rt_pulse;
  Lt_pulse=msg->Lt_pulse;

  }

// Open serial port
bool ccr1050_init()
{
	if(-1 == (file_descriptor = open(COMM_PORT,O_RDONLY)))
	{
		cout << "Error opening port \n";
		cout << "Set port parameters using the following Linux command:\n stty -F /dev/ttyUSB0 115200 raw\n";
		cout << "You may need to have ROOT access\n";
		return false;
	}
	cout << "CruizCoreR1050 communication port is ready\n";
       // file_descriptor = open(COMM_PORT,O_RDONLY))
	return true;
}

// Close serial port
void ccr1050_close()
{
	close(file_descriptor);
	cout << "Closing communication port\n";
}

// Get a data packet and parse it
bool ccr1050_getvalue()
{
	short header;
	short rate_int;
	short angle_int;
	float rate_float;
	float angle_float;
	short check_sum;
	unsigned char data_packet[PACKET_SIZE];
	
	if(PACKET_SIZE != read(file_descriptor,data_packet,PACKET_SIZE))
		return false;

	// Verify data packet header 
	memcpy(&header,data_packet,sizeof(short));
	if(header != (short)0xFFFF)
	{
		//cout << "Header error !!!\n";
		return false;
	}

	// Copy values from data string 
	memcpy(&rate_int,data_packet+2,sizeof(short));
	memcpy(&angle_int,data_packet+4,sizeof(short));
	memcpy(&check_sum,data_packet+6,sizeof(short));

	// Verify checksum
	if(check_sum != (short)(0xFFFF + rate_int + angle_int))
	{
		//cout<< "Checksum error!!\n";
		return false;
	}

	// Apply scale factors
	rate_float = rate_int/100;
 	angle_float = angle_int/100;
	gAngle=angle_float;
        gRate=rate_float;
      
	return true;
}




//-------------------------------------------------------------
int main(int argc, char** argv){
  system("stty -F /dev/ttyUSB0 115200 raw"); //calling shell command within program console
  ros::init(argc, argv, "odometry4");

  ros::NodeHandle n;
  ros::Publisher odom_pub = n.advertise<nav_msgs::Odometry>("odom",100);
  tf::TransformBroadcaster odom_broadcaster;
  ros::Subscriber odom_sub = n.subscribe("chatter", 100.0, chatterCallback);
  double x = 0.0;
  double y = 0.0;
  double th = 0.0;

  //double vx = 0.1;
  //double vy = -0.1;
  //double vth = 0.1;

  ros::Time current_time, last_time;
  current_time = ros::Time::now();
  last_time = ros::Time::now();

  ros::Rate r(100.0);//cruzecore rate 50

 //tf::TransformBroadcaster broadcaster;
//-------------------------------------------------------------
// Open communication channel
	if(!ccr1050_init())
		return 0;
//------------------------------------------------------------
 double dt,dleft,dright,dxy_ave,vxy,vth,dx,dy,dth,axy;
 double vxy_before,elapsed,velosity_average,avth,vth_before; 
  while(n.ok())
    {
    current_time = ros::Time::now();
    
   if(!ccr1050_getvalue())//;
            { odom_sub;}//=n.subscribe("chatter", 50.0, chatterCallback);}
   

  /***compute odometry in a typical way given the velocities of the robot***/
   dt = (current_time - last_time).toSec();
   
   //   cout << " gAngle:" << gAngle << " [deg]\n";
   //   cout << " gRate"  <<gRate << "deg/sec]\n";
   //   cout << " Rt_pulse:" << Rt_pulse << " \n";
   //   cout << " Lt_pulse:" << Lt_pulse << " \n";
     
   /**********************ANGLE**************************/
   
   // the angle rotated
    d_cruze=(gAngle-gAngle_before);//rotated angle
    dth=-(d_cruze*pi)/180.0;//convert d_cruze in rad/sec
     // cout<< "dth"<<dth<<"rad\n";
   //Angular velosity
    vth=dth/dt;//angular velosity 
    //gRate_rad=(gRate*pi)/180;
    //cout << " gRate_rad:" << gRate_rad << " [rad/sec]\n";   
    
  
    /*******************DISTANCE************************/

    //calculate the distance in meters travelled by two wheels
    Rt_pulse_now=Rt_pulse-Rt_pulse_before;
    Rt_pulse_before=Rt_pulse;
    Lt_pulse_now=Lt_pulse-Lt_pulse_before;
    Lt_pulse_before=Lt_pulse;
    dright=(-Rt_pulse_now/pulsePerMeter);    
    dleft =(-Lt_pulse_now/pulsePerMeter); 
    

    //compute the average linear distance over the two wheels
    dxy_ave=(dleft+dright)/2.0;
   
    //Linear velosity
    vxy=dxy_ave/dt;
        //cout<< "dxy_ave"<<  dxy_ave  <<"m\n";
        //cout<< "dt"<<  dt <<"sec\n";
        //cout<< "velosity   "<<  vxy  <<"   m/sec\n";
        //Linear acceleration  
    axy=(vxy-vxy_before)/dt;
        //cout<< "acceleration   "<<  axy  <<"   m/sec2\n";
   
    
    //How far did we move forward?
    if (dxy_ave != 0) {
    dx = cos(dth) * dxy_ave;
    dy = -sin(dth) * dxy_ave;
    /* The total distance traveled so far */
    x += (cos(th) * dx - sin(th) * dy);
    y += (sin(th) * dx + cos(th) * dy);
    }

     /* The total angular rotated so far */
     if (dth != 0)
     th += dth;//
     
     //total time elapsed
    elapsed+=dt;
    velosity_average=x/elapsed;
    
    if(vxy !=0 || gRate !=0)
     {
      duration=duration+dt;  
      
     }
//cout << " duration;" << duration << " \n";
    //ROS_INFO("elapsed=: [%f]", elapsed);
    //ROS_INFO("x=: [%f]", x);
  
    //since all odometry is 6DOF we'll need a quaternion created from yaw
    geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(th);

    //first, we'll publish the transform over tf
    geometry_msgs::TransformStamped odom_trans;
    odom_trans.header.stamp = current_time;
    odom_trans.header.frame_id = "odom";
    odom_trans.child_frame_id = "base_link";

    odom_trans.transform.translation.x = x;
    odom_trans.transform.translation.y = y;
    odom_trans.transform.translation.z = 0.0;
    odom_trans.transform.rotation = odom_quat;

    //send the transform
    odom_broadcaster.sendTransform(odom_trans);

    //next, we'll publish the odometry message over ROS
    nav_msgs::Odometry odom;
    odom.header.stamp = current_time;
    odom.header.frame_id = "odom";
    odom.child_frame_id = "base_link";

    //set the position
    odom.pose.pose.position.x = x;
    odom.pose.pose.position.y = y;
    odom.pose.pose.position.z = 0.0;
    odom.pose.pose.orientation = odom_quat;

    //set the velocity
    odom.twist.twist.linear.x = vxy;
    odom.twist.twist.linear.y = 0;
    odom.twist.twist.linear.z=0;
    odom.twist.twist.angular.x=0; 
    odom.twist.twist.angular.y=0;
    odom.twist.twist.angular.z = vth;

    //publish the message
    odom_pub.publish(odom);
    
    //static transforms
 /*   broadcaster.sendTransform(
         tf::StampedTransform(
           tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.158, 0.0, 0.089)),
           ros::Time::now(),"base_link", "laser"));
    broadcaster.sendTransform(
         tf::StampedTransform(
           tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.0, 0.25, 0.074)),
           ros::Time::now(),"base_link",  "leftWheel"));
    broadcaster.sendTransform(
         tf::StampedTransform(
           tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.0, -0.25, 0.074)),
           ros::Time::now(),"base_link", "rightwheel"));*/


    vxy_before=vxy; 
    vth_before=vth;
    gRate_rad_before=gRate_rad;
    gAngle_before=gAngle;
    last_time = current_time;
    ros::spinOnce();
     
   // r.sleep();
  }
	//return 1;
 // }

   //ccr1050_close();
}
