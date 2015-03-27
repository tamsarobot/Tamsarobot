#!/usr/bin/env python
import roslib; roslib.load_manifest('robot_mover')
import rospy
import curses
from geometry_msgs.msg import Twist

dirty = False

def get_new_command():
  
    global window
    global dirty
    global twist

    c = window.getch()


    if c == ord('i'):
        print("FORWARD."), 
        twist.linear.x = 0.2; # move forward 
        twist.angular.z=0.0;
    elif c == ord(','):
        print("BACKWARD."),
        twist.linear.x = -(0.2); # move backward 
        twist.angular.z=0.0;
    elif c == ord('j'):
        print("RIGHT TURN."),
        twist.angular.z = 0.5; # turn right 
        twist.linear.x = 0.0;
    elif c == ord('l'):
        print("LEFT TURN."),
        twist.angular.z = -(0.5); # turn_left
        twist.linear.x = 0.0;
    elif c == ord('k'):
        print("STOP."),
        twist.linear.x = 0.0; #stop
        twist.angular.z=0.0;
    dirty = True

    return twist

def cleanup():
    global window
    curses.nocbreak(); window.keypad(0); curses.echo()
    curses.endwin()
def mover():
    global window
    global dirty
    global twist
    pub = rospy.Publisher('/cmd_vel', Twist)
    rospy.init_node('robot_mover')
    rospy.on_shutdown(cleanup)
    twist = Twist()
    # # init simple curses interface
    window = curses.initscr()
    window.keypad(0)
    curses.noecho()
    curses.cbreak()
    # main loop
    while not rospy.is_shutdown():
        twist=get_new_command()
        window.refresh()

        if (dirty):
            pub.publish(twist)
            dirty = False






   

if __name__ == '__main__':
    try:
        mover()
    except rospy.ROSInterruptException: pass
