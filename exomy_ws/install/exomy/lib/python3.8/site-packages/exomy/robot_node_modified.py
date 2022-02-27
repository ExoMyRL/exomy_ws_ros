#!/usr/bin/env python
from exomy_msgs.msg import MotorCommands
import rclpy
from rclpy.node import Node
from .rover_modified import Rover
from geometry_msgs.msg import Twist



class RobotNode(Node):
    def __init__(self):
        #navn i ros domænet oprettes og klassen instantieres med subscriber og publisher
        self.node_name = 'robot_node_modified'
        super().__init__(self.node_name)
        #der oprettes subscriber på topic: cmd_vel. når der modtages en besked bliver den sendt til funktionen "rover_callback"
        self.cmdvel_sub = self.create_subscription(
            Twist,
            'cmd_vel',
            self.rover_callback,
            10)
        #der oprettes en publisher der skriver en beskedtype defineret som MotorCommands på topic: motorcommands. beskeden er en del af exomy bibleoteket
        self.robot_pub = self.create_publisher(
            MotorCommands,
            'motor_commands',
            1)
        
        #der instantieres et objekt fra klassen rover_modified
        self.robot = Rover()

    #her starter rover_callback som seperat funktion
    def rover_callback(self, msg):
        #variablen cmds oprettes og defineres som beskedtypen MotorCommands
        cmds = MotorCommands()
        #værdierne i cmds opdateres igennem funktionen set_steeringangles som er en del af rover_modified klassen. set_steeringangles tager den ønskede lineære og angulære hastighed på robotten som argument
        cmds.motor_angles, cmds.motor_speeds = self.robot.Set_SteeringAngles(
            msg.linear.x, msg.angular.y)
        print(cmds)    
        #her sendes beskeden ud på det dertil allokerede topic
        self.robot_pub.publish(cmds)


def main(args=None):
    rclpy.init(args=args)
    #klassen der er defineret startes for at oprette publisher og subscriber
    try:
        robot_node = RobotNode()
        try:
            #klassen lytter efter beskeder og processerere og sende dem videre når de ankommer
            rclpy.spin(robot_node)
        finally:
            #klassen lukkes ned når koden slukkes
            robot_node.destroy_node()
    except KeyboardInterrupt:
        pass
    finally:
        rclpy.shutdown()


if __name__ == '__main__':
    main()