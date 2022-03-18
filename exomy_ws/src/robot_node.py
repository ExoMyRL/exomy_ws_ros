#!/usr/bin/env python
import time
from exomy.msg import RoverCommand, MotorCommands, Screen
import rospy
from rover import Rover
import message_filters
from geometry_msgs.msg import Twist


global robot
robot = Rover()

def rover_callback(msg):
        #variablen cmds oprettes og defineres som beskedtypen MotorCommands
        print(msg)
        cmds = MotorCommands()
        #værdierne i cmds opdateres igennem funktionen set_steeringangles som er en del af rover_modified klassen. set_steeringangles tager den ønskede lineære og angulære hastighed på robotten som argument
        cmds.motor_angles, cmds.motor_speeds = robot.Set_SteeringAngles(
            msg.linear.x, msg.angular.z)
        print(cmds)    
        #her sendes beskeden ud på det dertil allokerede topic
        robot_pub.publish(cmds)

# def joy_callback(message):
#     cmds = MotorCommands()

#     if message.motors_enabled is True:
#         exomy.setLocomotionMode(message.locomotion_mode)

#         cmds.motor_angles = exomy.joystickToSteeringAngle(
#             message.vel, message.steering)
#         cmds.motor_speeds = exomy.joystickToVelocity(
#             message.vel, message.steering)
#     else:
#         cmds.motor_angles = exomy.joystickToSteeringAngle(0, 0)
#         cmds.motor_speeds = exomy.joystickToVelocity(0, 0)

    robot_pub.publish(cmds)

if __name__ == '__main__':
    rospy.init_node('robot_node')
    rospy.loginfo("Starting the robot node")
    global robot_pub
    cmdvel_sub = rospy.Subscriber(
        "/cmd_vel", Twist, rover_callback, queue_size=10)

    rate = rospy.Rate(10)

    robot_pub = rospy.Publisher("/motor_commands", MotorCommands, queue_size=1)

    rospy.spin()
