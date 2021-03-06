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

    def Set_SteeringAngles(self, lin_vel_x, ang_vel):
        '''
        Converts the steering command [angle of joystick] to angles for the different motors
        '''
        steering_angles = [0]*6
        motor_speeds = [0]*6
        # Determine radius of turning point (from the center of the rover) (Centimeters):
        # lin_vel = math.sqrt((lin_vel_x*lin_vel_x)+(lin_vel_y*lin_vel_y)) # Jeg er ikke sikker paa vi kan goere det saadan her
        
        if ang_vel != 0:
            radius = (abs(lin_vel_x)/abs(ang_vel))*10

        # Distance from center of the rover to the top (centimeters):
        y_top = 19.5 # check if it's correct
        # Distance from center of the the side:
        x_side = 15 # check if it's correct

        """
        Steering angles calculation 
        """
        if ang_vel == 0: 
            steering_angles[self.FL] = 0
            steering_angles[self.FR] = 0
            steering_angles[self.CL] = 0
            steering_angles[self.CR] = 0
            steering_angles[self.RL] = 0
            steering_angles[self.RR] = 0
        # If the turning point is within the chassis of the robot, turn on the spot:
        elif radius <= x_side : 
            steering_angles[self.FL] = math.atan2(y_top,x_side)
            steering_angles[self.FR] = -math.atan2(y_top,x_side)
            steering_angles[self.CL] = 0
            steering_angles[self.CR] = 0
            steering_angles[self.RL] = -math.atan2(y_top,x_side)
            steering_angles[self.RR] = math.atan2(y_top,x_side)
        # If the rotation is positive, we turn anticlockwise
        elif (ang_vel > 0 and np.sign(lin_vel_x) > 0) or (ang_vel < 0 and np.sign(lin_vel_x) < 0):
            steering_angles[self.FL] = -math.atan2(y_top,(radius-x_side))
            steering_angles[self.FR] = -math.atan2(y_top,(radius+x_side))
            steering_angles[self.CL] = 0
            steering_angles[self.CR] = 0
            steering_angles[self.RL] = math.atan2(y_top,(radius-x_side))
            steering_angles[self.RR] = math.atan2(y_top,(radius+x_side))
        # If the rotation is negativ, we turn clockwise
        elif (ang_vel < 0 and np.sign(lin_vel_x) > 0) or (ang_vel > 0 and np.sign(lin_vel_x) < 0):
            steering_angles[self.FL] = math.atan2(y_top,(radius+x_side))
            steering_angles[self.FR] = math.atan2(y_top,(radius-x_side))
            steering_angles[self.CL] = 0
            steering_angles[self.CR] = 0
            steering_angles[self.RL] = -math.atan2(y_top,(radius+x_side))
            steering_angles[self.RR] = -math.atan2(y_top,(radius-x_side))

        """
        Motor speeds calculation
        """
        # Speed moving forward/backward
        if ang_vel == 0: 
            motor_speeds[self.FL] = lin_vel_x
            motor_speeds[self.FR] = lin_vel_x
            motor_speeds[self.CL] = lin_vel_x
            motor_speeds[self.CR] = lin_vel_x
            motor_speeds[self.RL] = lin_vel_x
            motor_speeds[self.RR] = lin_vel_x
        # Speed turning in place
        
        # elif radius <= x_side and ang_vel > 0: # anticlockwise
        #     motor_speeds[self.FL] = -math.sqrt((y_top*y_top)+(x_side*x_side))*abs(ang_vel)
        #     motor_speeds[self.FR] = math.sqrt((y_top*y_top)+(x_side*x_side))*abs(ang_vel)
        #     motor_speeds[self.CL] = -x_side*abs(ang_vel)
        #     motor_speeds[self.CR] = x_side*abs(ang_vel)
        #     motor_speeds[self.RL] = -math.sqrt((y_top*y_top)+(x_side*x_side))*abs(ang_vel)
        #     motor_speeds[self.RR] = math.sqrt((y_top*y_top)+(x_side*x_side))*abs(ang_vel)
        
        elif radius <= x_side and ang_vel > 0: # anticlockwise
            frontLeft = math.sqrt((y_top*y_top)+(x_side*x_side))*abs(ang_vel)
            centerLeft = x_side*abs(ang_vel)
            relation = centerLeft/frontLeft
            motor_speeds[self.FL] = abs(ang_vel)
            motor_speeds[self.FR] = -abs(ang_vel)
            motor_speeds[self.CL] = abs(ang_vel)*relation
            motor_speeds[self.CR] = -abs(ang_vel)*relation
            motor_speeds[self.RL] = abs(ang_vel)
            motor_speeds[self.RR] = -abs(ang_vel)
        # elif radius <= x_side and ang_vel < 0: # Clockwise
        #     motor_speeds[self.FL] = math.sqrt((y_top*y_top)+(x_side*x_side))*abs(ang_vel)
        #     motor_speeds[self.FR] = -math.sqrt((y_top*y_top)+(x_side*x_side))*abs(ang_vel)
        #     motor_speeds[self.CL] = x_side*abs(ang_vel)
        #     motor_speeds[self.CR] = -x_side*abs(ang_vel)
        #     motor_speeds[self.RL] = math.sqrt((y_top*y_top)+(x_side*x_side))*abs(ang_vel)
        #     motor_speeds[self.RR] = -math.sqrt((y_top*y_top)+(x_side*x_side))*abs(ang_vel)
        elif radius <= x_side and ang_vel < 0: # Clockwise
            frontLeft = math.sqrt((y_top*y_top)+(x_side*x_side))*abs(ang_vel)
            centerLeft = x_side*abs(ang_vel)
            relation = centerLeft/frontLeft
            motor_speeds[self.FL] = -abs(ang_vel)
            motor_speeds[self.FR] = abs(ang_vel)
            motor_speeds[self.CL] = -abs(ang_vel)*relation
            motor_speeds[self.CR] = abs(ang_vel)*relation
            motor_speeds[self.RL] = -abs(ang_vel)
            motor_speeds[self.RR] = abs(ang_vel)
        # Speed turning anticlockwise:
        # elif ang_vel > 0:
        #     motor_speeds[self.FL] = (math.sqrt((y_top*y_top)+((radius-x_side)*(radius-x_side)))*abs(ang_vel))*np.sign(lin_vel_x)
        #     motor_speeds[self.FR] = (math.sqrt((y_top*y_top)+((radius+x_side)*(radius+x_side)))*abs(ang_vel))*np.sign(lin_vel_x)
        #     motor_speeds[self.CL] = ((radius-x_side)*abs(ang_vel))*np.sign(lin_vel_x)
        #     motor_speeds[self.CR] = ((radius+x_side)*abs(ang_vel))*np.sign(lin_vel_x)
        #     motor_speeds[self.RL] = (math.sqrt((y_top*y_top)+((x_side-x_side)*(x_side-x_side)))*abs(ang_vel))*np.sign(lin_vel_x)
        #     motor_speeds[self.RR] = (math.sqrt((y_top*y_top)+((x_side+x_side)*(x_side+x_side)))*abs(ang_vel))*np.sign(lin_vel_x)
        elif ang_vel > 0:
            frontLeft = (math.sqrt((y_top*y_top)+((radius-x_side)*(radius-x_side)))*abs(ang_vel))*np.sign(lin_vel_x)
            frontRight = (math.sqrt((y_top*y_top)+((radius+x_side)*(radius+x_side)))*abs(ang_vel))*np.sign(lin_vel_x)
            frontRelation = frontLeft/frontRight
            centerLeft = ((radius-x_side)*abs(ang_vel))*np.sign(lin_vel_x)
            centerRight = ((radius+x_side)*abs(ang_vel))*np.sign(lin_vel_x)
            centerRelation = centerLeft/centerRight
            frontCenterRelation = centerRight/frontRight
            motor_speeds[self.FL] = lin_vel_x*frontRelation
            motor_speeds[self.FR] = lin_vel_x
            motor_speeds[self.CL] = lin_vel_x*frontCenterRelation*centerRelation
            motor_speeds[self.CR] = lin_vel_x*frontCenterRelation
            motor_speeds[self.RL] = lin_vel_x*frontRelation
            motor_speeds[self.RR] = lin_vel_x
        # Speed turning clockwise
        elif ang_vel < 0:
            frontLeft = (math.sqrt((y_top*y_top)+((radius+x_side)*(radius+x_side)))*abs(ang_vel))*np.sign(lin_vel_x)
            frontRight = (math.sqrt((y_top*y_top)+((radius-x_side)*(radius-x_side)))*abs(ang_vel))*np.sign(lin_vel_x)
            frontRelation = frontRight/frontLeft
            centerLeft = ((radius+x_side)*abs(ang_vel))*np.sign(lin_vel_x)
            centerRight = ((radius-x_side)*abs(ang_vel))*np.sign(lin_vel_x)
            centerRelation = centerRight/centerLeft
            frontCenterRelation = centerLeft/frontLeft
            # motor_speeds[self.FL] = (math.sqrt((y_top*y_top)+((radius+x_side)*(radius+x_side)))*abs(ang_vel))*np.sign(lin_vel_x)
            # motor_speeds[self.FR] = (math.sqrt((y_top*y_top)+((radius-x_side)*(radius-x_side)))*abs(ang_vel))*np.sign(lin_vel_x)
            # motor_speeds[self.CL] = ((radius+x_side)*abs(ang_vel))*np.sign(lin_vel_x)
            # motor_speeds[self.CR] = ((radius-x_side)*abs(ang_vel))*np.sign(lin_vel_x)
            # motor_speeds[self.RL] = (math.sqrt((y_top*y_top)+((radius+x_side)*(radius+x_side)))*abs(ang_vel))*np.sign(lin_vel_x)
            # motor_speeds[self.RR] = (math.sqrt((y_top*y_top)+((radius-x_side)*(radius-x_side)))*abs(ang_vel))*np.sign(lin_vel_x)
            motor_speeds[self.FL] = lin_vel_x
            motor_speeds[self.FR] = lin_vel_x*frontRelation
            motor_speeds[self.CL] = lin_vel_x*frontCenterRelation
            motor_speeds[self.CR] = lin_vel_x*frontCenterRelation*centerRelation
            motor_speeds[self.RL] = lin_vel_x
            motor_speeds[self.RR] = lin_vel_x*frontRelation

    
        motor_speeds[self.FL] = int(motor_speeds[self.FL])
        motor_speeds[self.FR] = int(motor_speeds[self.FR])
        motor_speeds[self.CL] = int(motor_speeds[self.CL])
        motor_speeds[self.CR] = int(motor_speeds[self.CR])
        motor_speeds[self.RL] = int(motor_speeds[self.RL])
        motor_speeds[self.RR] = int(motor_speeds[self.RR])

        steering_angles[self.FL] = int(np.rad2deg(steering_angles[self.FL]))
        steering_angles[self.FR] = int(np.rad2deg(steering_angles[self.FR]))
        steering_angles[self.CL] = int(np.rad2deg(steering_angles[self.CL]))
        steering_angles[self.CR] = int(np.rad2deg(steering_angles[self.CR]))
        steering_angles[self.RL] = int(np.rad2deg(steering_angles[self.RL]))
        steering_angles[self.RR] = int(np.rad2deg(steering_angles[self.RR]))
    

        return steering_angles, motor_speeds