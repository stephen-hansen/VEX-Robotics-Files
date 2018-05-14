#pragma config(Sensor, in1,    controlSwitch,  sensorAnalog)
#pragma config(Motor,  port4,           FLmotor,       tmotorVex393, openLoop)
#pragma config(Motor,  port5,           BLmotor,       tmotorVex393, openLoop)
#pragma config(Motor,  port6,           BRmotor,       tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port7,           FRmotor,       tmotorVex393, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(125)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

//Important Functions

void Drive(int S, int T) //S for speed T for time
{
	motor[FLmotor] = S;
	motor[BLmotor] = S;
	motor[BRmotor] = S;
	motor[FRmotor] = S;
	wait1Msec(T);
}


/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
  Drive(127,1500);
  Drive(-127,1500);
  Drive(0,6000);
  Drive(127,1500);
  Drive(-127,1500);
  Drive(0,3000);
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	while (1==1)
		{
		wait1Msec(1); //meant for not-going-crazy-robot; not sure if necessary
		if (SensorValue(controlSwitch) > 1) //if theres no switch then tank controls
		{
		 motor[BLmotor] = vexRT[Ch3]; //left is controlled by left joystick
		 motor[FLmotor] = vexRT[Ch3];
		 motor[BRmotor] = vexRT[Ch2]; //right is controlled by right joystick
		 motor[FRmotor] = vexRT[Ch2];
 	  }
 	  else if (SensorValue(controlSwitch) == 0) //if theres a switch then steve controls (one joystick magic!!!)
 		{
 			while (1==1)
 				{
  			wait1Msec(1); //also meant for notgoingcrazy, not sure if necessary
		 	  if (abs(vexRT[Ch4]) > abs(vexRT[Ch3])) //if absolute value of LR > absolute value of UD
				{
				motor[BRmotor] = -(vexRT[Ch4]); //LR is the chosen control
				motor[FRmotor] = -(vexRT[Ch4]); //left side is inverted speed of LR
				motor[BLmotor] = vexRT[Ch4]; //right side isnt inverted
				motor[FLmotor] = vexRT[Ch4]; //so that it turns in direction of LR
				}
				else if (abs(vexRT[Ch3]) >= abs(vexRT[Ch4])) //if absolute value of LR <= absolute value of UD
				{
				motor[BRmotor] = vexRT[Ch3]; //UD is the chosen control
				motor[FRmotor] = vexRT[Ch3]; //drive forwards/backwards at UD speed
				motor[BLmotor] = vexRT[Ch3];
				motor[FLmotor] = vexRT[Ch3];
				}
			}
		}
	}
}