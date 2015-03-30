# Tamsarobot
ROS custom  Robot using arduino mega

this repository is aimed for those custom robot DIY enthuiasts who wish to make robot based on 
x86 PC ROS 
communicating with
arduino mega microcontroller

PC side node includes
  1. Robot_mover(teleoperation--topic:cmd_vel)
  2. Odometry4 (Ttopic-/odom)
  3. rossserial_python
  4. sick_wrappe(topic (scan/Laser)
  5. TF 
  6. RVIZ

Arduiono_side
  subscrives cmd_vel --> serial-->BLDC command
  publish odometruy info

PARTS
  1.sernsor:SICK Laser Scanner(could be others ex)Neato scanner etc)
  2.micro_infinity MEMS sensor
  3.2BLDC motors
  4.arduino mega board
  5.Battery 12v Bosch
  6.USB to serial coverter
  7.24V DC converter
