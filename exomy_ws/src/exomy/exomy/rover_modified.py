#!/usr/bin/env python
import numpy as np
from .locomotion_modes import LocomotionMode
import math


class Rover():
    '''
    Rover class contains all the math and motor control algorithms to move the rover
    '''

    # Defining wheel names
    FL, FR, CL, CR, RL, RR = range(0, 6)

    # Defining locomotion modes
    #FAKE_ACKERMANN, ACKERMANN, POINT_TURN, CRABBING = range(0, 4)

    def __init__(self):
        #self.locomotion_mode = LocomotionMode.FAKE_ACKERMANN

        self.wheel_x = 12.0
        self.wheel_y = 20.0

    def Set_SteeringAngles(self, lin_vel_x, lin_vel_y, ang_vel):
        '''
        Converts the steering command [angle of joystick] to angles for the different motors
        '''
        steering_angles = [0]*6
        motor_speeds = [0]*6
        # Determine radius of turning point (from the center of the rover) (Centimeters):
        lin_vel = math.sqrt(lin_vel_x^2+lin_vel_y^2) # Jeg er ikke sikker paa vi kan goere det saadan her
        radius = (lin_vel/abs(ang_vel))*10

        # Distance from center of the rover to the top (centimeters):
        y_top = 20 # check if it's correct
        # Distance from center of the the side:
        x_side = 15 # check if it's correct

        """
        Steering angles calculation 
        """
        # If the turning point is within the chassis of the robot, turn on the spot:
        if radius <= 15: 
            steering_angles[self.FL] = -math.atan2(y_top/x_side)
            steering_angles[self.FR] = math.atan2(y_top/x_side)
            steering_angles[self.CR] = 0
            steering_angles[self.CL] = 0
            steering_angles[self.RL] = math.atan2(y_top/x_side)
            steering_angles[self.RR] = -math.atan2(y_top/x_side)
        # If the rotation is positive, we turn anticlockwise
        elif ang_vel >= 0:
            steering_angles[self.FL] = math.atan2(y_top/(radius-x_side))
            steering_angles[self.FR] = math.atan2(y_top/(radius+x_side))
            steering_angles[self.CR] = 0
            steering_angles[self.CL] = 0
            steering_angles[self.RL] = -math.atan2(y_top/(radius-x_side))
            steering_angles[self.RR] = -math.atan2(y_top/(radius+x_side))
        # If the rotation is negativ, we turn clockwise
        elif ang_vel < 0:
            steering_angles[self.FL] = -math.atan2(y_top/(radius+x_side))
            steering_angles[self.FR] = -math.atan2(y_top/(radius-x_side))
            steering_angles[self.CR] = 0
            steering_angles[self.CL] = 0
            steering_angles[self.RL] = math.atan2(y_top/(radius+x_side))
            steering_angles[self.RR] = math.atan2(y_top/(radius-x_side))

        """
        Motor speeds calculation
        """
        # Speed turning in place:
        if radius <= 15 and ang_vel >= 0: # anticlockwise
            motor_speeds[self.FL] = -math.sqrt(y_top^2+x_side^2)*ang_vel
            motor_speeds[self.FR] = math.sqrt(y_top^2+x_side^2)*ang_vel
            motor_speeds[self.CL] = -x_side*ang_vel
            motor_speeds[self.CR] = x_side*ang_vel
            motor_speeds[self.RL] = -math.sqrt(y_top^2+x_side^2)*ang_vel
            motor_speeds[self.RR] = math.sqrt(y_top^2+x_side^2)*ang_vel
        if radius <= 15 and ang_vel < 0: # Clockwise
            motor_speeds[self.FL] = math.sqrt(y_top^2+x_side^2)*ang_vel
            motor_speeds[self.FR] = -math.sqrt(y_top^2+x_side^2)*ang_vel
            motor_speeds[self.CL] = x_side*ang_vel
            motor_speeds[self.CR] = -x_side*ang_vel
            motor_speeds[self.RL] = math.sqrt(y_top^2+x_side^2)*ang_vel
            motor_speeds[self.RR] = -math.sqrt(y_top^2+x_side^2)*ang_vel
        # Speed turning anticlockwise:
        elif ang_vel >= 0:
            motor_speeds[self.FL] = math.sqrt(y_top^2+(radius-x_side)^2)*ang_vel
            motor_speeds[self.FR] = math.sqrt(y_top^2+(radius+x_side)^2)*ang_vel
            motor_speeds[self.CL] = (radius-x_side)*ang_vel
            motor_speeds[self.CR] = (radius+x_side)*ang_vel
            motor_speeds[self.RL] = math.sqrt(y_top^2+(x_side-x_side)^2)*ang_vel
            motor_speeds[self.RR] = math.sqrt(y_top^2+(x_side+x_side)^2)*ang_vel
        # Speed turning clockwise
        elif ang_vel < 0:
            motor_speeds[self.FL] = math.sqrt(y_top^2+(radius+x_side)^2)*ang_vel
            motor_speeds[self.FR] = math.sqrt(y_top^2+(radius-x_side)^2)*ang_vel
            motor_speeds[self.CL] = (radius+x_side)*ang_vel
            motor_speeds[self.CR] = (radius-x_side)*ang_vel
            motor_speeds[self.RL] = math.sqrt(y_top^2+(radius+x_side)^2)*ang_vel
            motor_speeds[self.RR] = math.sqrt(y_top^2+(radius-x_side)^2)*ang_vel

        """
        motor_speeds[self.FL] = 50
        motor_speeds[self.FR] = 50
        motor_speeds[self.CR] = 50
        motor_speeds[self.CL] = 50
        motor_speeds[self.RL] = 50
        motor_speeds[self.RR] = 50
        """
        return steering_angles, motor_speeds