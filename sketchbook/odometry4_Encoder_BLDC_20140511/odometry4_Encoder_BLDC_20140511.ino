/*
 * This sketch pulishes 
 * and Rt-pulse, Lt-pulse odometry data to "ros_workspace/odometry4" to a pc side
 * which publishes whole odometry data based on this  
 *---------------------------running code------------------------------------------------
 *$roscore
 *$rosrun rosserial_python serial_node.py /dev/ttyACM0
 *$rosrun odometry4 odometry4
 *---------------------------------------------------------------------------------------
 */


#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include <WProgram.h>
#endif

#include <ros.h>
#include <Encoder.h>
#include <geometry_msgs/Twist.h>
#include <odometry4/MyOdometry4.h>


using namespace std;
Encoder myEnc_Rt(2,3);
Encoder myEnc_Lt(20,21);

//unsigned char chCPS;
//unsigned char data_string[8];
int cnt;
//float gRate;
//float gAngle;

float oldPosition_Rt  = -999.0;
float oldPosition_Lt  = -999.0;
float Rt_pulse;
float Lt_pulse;

//float Rt_pulse=0.0;//Rt stepper moteor pulse
//float Lt_pulse=0.0;
//short int rate;
//short int angle;
//short check_sum;
//float x;
unsigned char moving = 0; // is the base in motion?


unsigned long  nextOdom = 0;
ros::NodeHandle  nh;
#define ODOM_RATE 10.0  
const float ODOM_INTERVAL = 1000.0 / ODOM_RATE;
//#define REPLY_SIZE 7
//char reply[REPLY_SIZE];
//#define TIMEOUT 100
odometry4::MyOdometry4 myodometry_msg;
ros::Publisher chatter("chatter", &myodometry_msg);




//int delayTime = 500;
int k=0;

  int m=0;
float time_start;

int i;int ii;
float x;
float th;
//char* myStrings[]={"#0.SPD 1000\r"};
//float myFloat1=1000.0; 
//float myFloat2= -1000.0;
float spd_right;
float spd_left;
float wheeltrack=0.35;//inter tire distance

int BLDC_SPEED()
{
       Serial1.write("#0.SPD ");Serial1.println(-spd_right);Serial1.write("\r");
       // Serial1.write("#0.SPD -1000\r");
       Serial1.write("#0.RUN\r");
     
        //-------------------------------------------------------------------//
       Serial2.write("#1.SPD ");Serial2.println(spd_left);Serial2.write("\r");
      //  Serial2.write("#1.SPD -1000\r");
       Serial2.write("#1.RUN\r");
       return 1;
   
}
/* The callback function to convert Twist messages into motor speeds */
void cmdVelCb(const geometry_msgs::Twist& msg) {
  x = msg.linear.x; // m/s
  x=x*6600.0;
  th = msg.angular.z; // rad/s
  th = th*6500.0;
 //th=51.8;
    return;
  }

/* A subscriber for the /cmd_vel topic */
ros::Subscriber<geometry_msgs::Twist> cmdVelSub("/cmd_vel", &cmdVelCb);

void setup(){
 // step_motor_ready();
  nh.getHardware()->setBaud(57600);//or whatever baud you want
  nh.initNode();
  nh.subscribe(cmdVelSub);
  nh.advertise(chatter);
  nextOdom = ODOM_INTERVAL;
  //Serial.begin(115200);
  Serial1.begin(115200);
    //
 //   delay(100);
    Serial1.write("#0.PWR 42 1\r");//serial mode
    Serial1.write("#0.COP\r");
   Serial1.write("#0.PWR 30 3\r");
    Serial1.write("#0.PWR 21 10\r");//deceleration
    Serial1.write("#0.PSV\r");
 //   Serial1.write("#0.PWR 20 10\r");//acceleration*/
//  delay(100);
  Serial2.begin(115200);
   // delay(100);
    Serial2.write("#1.PWR 42 0\r");//serial mode
    Serial2.write("#1.COP\r");
    Serial2.write("#1.PWR 30 3\r");
    Serial1.write("#1.PWR 21 10\r");
    Serial1.write("#1.PSV\r");
    // Serial1.write("#1.PWR 20 10\r");*/
    
    delay(100);
}

void loop(){
 
      if (x==0 && th ==0)
      {moving=0;
        spd_right=spd_left=0;
       BLDC_SPEED();  
       // Serial1.write("#0.PWR BRK\r");//motor break
       // Serial1.write("#1.PWR BRK\r"); 
    //    Serial1.write("#0.PWR 31 3\r");//emergency stop
    //    Serial1.write("#1.PWR 31 3\r"); 
        
      }
      moving=1; 
      if(x==0)
      {//turn inplace
       spd_right=(th*wheeltrack)/2.0;
       spd_left=-spd_right;
       BLDC_SPEED();
      }
      else if (th==0)
      {//pure forward or backward motion
       spd_right=spd_left=x;
       BLDC_SPEED();
      }
      else{
        //rotation about point in space
        spd_left=x-((th*wheeltrack)/2.0);
        spd_right=x+((th*wheeltrack)/2.0);
        BLDC_SPEED();
      }
   // nextOdom = nextOdom+1;
// if (millis() > nextOdom)
 
   { 
     float newPosition_Rt = myEnc_Rt.read();
  if (newPosition_Rt != oldPosition_Rt) {
  oldPosition_Rt = newPosition_Rt;
  Rt_pulse=oldPosition_Rt; 
}
  float newPosition_Lt = myEnc_Lt.read();
  if (newPosition_Lt != oldPosition_Lt) {
    oldPosition_Lt = newPosition_Lt;
    Lt_pulse=oldPosition_Lt;  
}
   myodometry_msg.Rt_pulse=Rt_pulse;
   myodometry_msg.Lt_pulse=-1*Lt_pulse;
   chatter.publish( &myodometry_msg );

  nextOdom += ODOM_INTERVAL;
  }
 

 
  
  nh.spinOnce();
 // delay(2);
}
