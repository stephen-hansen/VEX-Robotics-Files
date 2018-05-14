#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    controlSwitch,  sensorAnalog)
#pragma config(Sensor, in2,    RedOrBluSwitch, sensorAnalog)
#pragma config(Sensor, in3,    LeftOrRightSwitch, sensorAnalog)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           FlapperL,      tmotorVex269, openLoop)
#pragma config(Motor,  port2,           ArmMotorR2,    tmotorVex393, openLoop)
#pragma config(Motor,  port3,           ArmMotorR,     tmotorVex393, openLoop)
#pragma config(Motor,  port4,           FLmotor,       tmotorVex393, openLoop)
#pragma config(Motor,  port5,           BLmotor,       tmotorVex393, openLoop, encoder, encoderPort, I2C_1, 1000)
#pragma config(Motor,  port6,           BRmotor,       tmotorVex393, openLoop, reversed, encoder, encoderPort, I2C_2, 1000)
#pragma config(Motor,  port7,           FRmotor,       tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port8,           ArmMotorL,     tmotorVex393, openLoop)
#pragma config(Motor,  port9,           ArmMotorL2,    tmotorVex393, openLoop)
#pragma config(Motor,  port10,          FlapperR,      tmotorVex269, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(125)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

//Important Functions

void Drive(int motorspeed, int armspeed, int time) // updated for more control
{
	motor[FLmotor] = motorspeed;
	motor[BLmotor] = motorspeed;
	motor[BRmotor] = motorspeed;
	motor[FRmotor] = motorspeed;
	motor[ArmMotorL] = armspeed;
	motor[ArmMotorR] = armspeed;
	motor[ArmMotorL2] = armspeed;
	motor[ArmMotorR2] = armspeed;
	wait1Msec(time);
}

void FlapperSpin()
{
	if (vexRT[Btn5D] == 1) //if 5D is pressed
  {
		motor[FlapperL] = 127; //flappers move inward
		motor[FlapperR] = 127;
	}
	else if (vexRT[Btn6D] == 1) //else if 6D is pressed
	{
		motor[FlapperL] = -127; //flappers move inward
		motor[FlapperR] = -127;
  }
  else
	{
		motor[FlapperL] = 0;
		motor[FlapperR] = 0;
	}
}

void AutoPlaceholder() //autonomous placeholder for now
{
	SensorValue(I2C_1) = 0; //reset sensor
	SensorValue(I2C_2) = 0;
  Drive(127,127,1500);
  Drive(-127,-127,1500);
  Drive(0,0,6000);
  Drive(127,127,1500);
  Drive(-127,-127,1500);
  Drive(0,0,3000);
}

float FixedI2C_2; // TO BE USED LATER

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
	//if no switch in port 2 choose red
  if (SensorValue(RedOrBluSwitch) > 1)
  {
  	//if no switch in port 3 choose left
  	if (SensorValue(LeftOrRightSwitch) > 1)
  	{
  		AutoPlaceholder(); //CODE FOR RED AND LEFT GOES HERE
  	}
  	//if switch in port 3 choose right
  	else if (SensorValue(LeftOrRightSwitch) == 0)
  	{
  		AutoPlaceholder(); //CODE FOR RED AND RIGHT GOES HERE
  	}
  }
  //if switch in port 2 choose blu
  else if (SensorValue(RedOrBluSwitch) == 0)
  {
  	//if no switch in port 3 choose left
  	if (SensorValue(LeftOrRightSwitch) > 1)
  	{
  		AutoPlaceholder(); //CODE FOR BLU AND LEFT GOES HERE
  	}
  	//if switch in port 3 choose right
  	else if (SensorValue(LeftOrRightSwitch) == 0)
  	{
  		AutoPlaceholder(); //CODE FOR BLU AND RIGHT GOES HERE
  	}
  }
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

//No switch in port 1 for tank controls
//Switch in port 1 for awesome steve joystick controls!!!
task usercontrol()
{
  SensorValue(I2C_1) = 0; //reset sensors
  SensorValue(I2C_2) = 0;
	while (1==1)
		{
		FixedI2C_2 = -(SensorValue(I2C_2)); // to fix sensor bug
		if (SensorValue(controlSwitch) > 1) //if theres no switch then tank controls
		{
		 while (1==1) // not sure if necessary
		 {
		 motor[BLmotor] = vexRT[Ch3]; //left is controlled by left joystick
		 motor[FLmotor] = vexRT[Ch3];
		 motor[BRmotor] = vexRT[Ch2]; //right is controlled by right joystick
		 motor[FRmotor] = vexRT[Ch2];
		 if (vexRT[Btn6U] == 1) //if 5U is pressed
		 {
		   motor[ArmMotorL] = 127; //arms move up
		   motor[ArmMotorR] = 127;
		   motor[ArmMotorL2] = 127;
		   motor[ArmMotorR2] = 127;
		 }
		 else if (vexRT[Btn5U] == 1) //else if 6U is pressed
		 {
		   motor[ArmMotorL] = -127; //arms move down
		   motor[ArmMotorR] = -127;
		   motor[ArmMotorL2] = -127;
		   motor[ArmMotorR2] = -127;
		 }
		 else
		 {
		   motor[ArmMotorL] = 0;
		   motor[ArmMotorR] = 0;
		   motor[ArmMotorL] = 0;
		   motor[ArmMotorR] = 0;
		 }
		 FlapperSpin();
 	  }
    }
 	  else if (SensorValue(controlSwitch) == 0) //if theres a switch then steve controls (joystick magic!!!)
 		{
 			while (1==1)
 				{
		 	  if (abs(vexRT[Ch4]) > abs(vexRT[Ch3])) //if absolute value of LR > absolute value of UD
				{
				motor[BRmotor] = -(vexRT[Ch4]); //LR is the chosen control
				motor[FRmotor] = -(vexRT[Ch4]); //right side is inverted speed of LR
				motor[BLmotor] = vexRT[Ch4]; //left side isnt inverted
				motor[FLmotor] = vexRT[Ch4]; //so that it turns in direction of LR
				}
				else if (abs(vexRT[Ch3]) >= abs(vexRT[Ch4])) //if absolute value of LR <= absolute value of UD
				{
				motor[BRmotor] = vexRT[Ch3]; //UD is the chosen control
				motor[FRmotor] = vexRT[Ch3]; //drive forwards/backwards at UD speed
				motor[BLmotor] = vexRT[Ch3];
				motor[FLmotor] = vexRT[Ch3];
				}
				motor[ArmMotorL] = vexRT[Ch2]; //arm motors move depending on how high/low right joystick is
				motor[ArmMotorR] = vexRT[Ch2];
				motor[ArmMotorL2] = vexRT[Ch2];
				motor[ArmMotorR2] = vexRT[Ch2];
				FlapperSpin();
			}
		}
	}
}
