#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    controlSwitch,  sensorAnalog)
#pragma config(Sensor, in2,    RedOrBluSwitch, sensorAnalog)
#pragma config(Sensor, in3,    LeftOrRightSwitch, sensorAnalog)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port3,           ArmMotorR,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port4,           FLmotor,       tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           BLmotor,       tmotorVex393, openLoop, encoder, encoderPort, I2C_1, 1000)
#pragma config(Motor,  port6,           BRmotor,       tmotorVex393, openLoop, reversed, encoder, encoderPort, I2C_2, 1000)
#pragma config(Motor,  port7,           FRmotor,       tmotorVex393, openLoop)
#pragma config(Motor,  port8,           ArmMotorL,     tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(125)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

//Important Functions

void Drive(int motorspeed, int armspeed) // updated for more control
{
	motor[FLmotor] = motorspeed;
	motor[BLmotor] = motorspeed;
	motor[BRmotor] = motorspeed;
	motor[FRmotor] = motorspeed;
	motor[ArmMotorL] = armspeed;
	motor[ArmMotorR] = armspeed;
}

void AutoPlaceholder() //autonomous placeholder for now
{
	SensorValue(I2C_1) = 0; //reset sensor
	float SquareValue;
	SquareValue = 1;
	Drive(127,63);
	wait1Msec(1500);
	SquareValue = SensorValue(I2C_1); //GET sensor value when moved one square
	if (SensorValue(I2C_1) == SquareValue)
	{
		Drive(-127,0);
	}
	if ((SensorValue(I2C_1) == 0) && (SquareValue != 1))
	{
		Drive(0,0);
		wait1Msec(6000);
		Drive(127,0);
	}
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
	//if no switch in port 2 choose blue
	if (SensorValue(RedOrBluSwitch) > 1)
	{
		//if no switch in port 3 choose left
		if (SensorValue(LeftOrRightSwitch) > 1)//Left is hang zone and right is middle
		{
			AutoPlaceholder(); //CODE FOR RED AND HANG ZONE GOES HERE
		}
		//if switch in port 3 choose right
		else if (SensorValue(LeftOrRightSwitch) == 0)
		{
			while (SensorValue(I2C_1) < 25)
			{
				motor[BLmotor] = 80; //left is controlled by left joystick
				motor[FLmotor] = 80;
				motor[BRmotor] = 80; //right is controlled by right joystick
				motor[FRmotor] = 80; //CODE FOR RED AND MIDDLE GOES HERE
				motor[ArmMotorL] = 80;
				motor[ArmMotorR] = 80;
			}
			SensorValue = 0;

			wait1Msec(2000);

			while (SensorValue(I2C_1) > -25)
			{
				//motor[BLmotor] = -80; //left is controlled by left joystick
				//motor[FLmotor] = -80;
				//motor[BRmotor] = -80; //right is controlled by right joystick
				//motor[FRmotor] = -80; //CODE FOR RED AND MIDDLE GOES HERE
				motor[ArmMotorL] = -127;
				motor[ArmMotorR] = -127;
			}
			SensorValue = 0;
		}
	}
	//if switch in port 2 choose blu
	else if (SensorValue(RedOrBluSwitch) == 0)
	{
		//if no switch in port 3 choose left
		if (SensorValue(LeftOrRightSwitch) > 1)
		{
			AutoPlaceholder(); //CODE FOR BLU AND HANG GOES HERE
		}
		//if switch in port 3 choose right
		else if (SensorValue(LeftOrRightSwitch) == 0)
		{
			AutoPlaceholder(); //CODE FOR BLU AND MIDDLE GOES HERE
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

//No switch in port 1 for BOSS tank controls
//Switch in port 1 for stinky steve joystick controls!!!
task usercontrol()
{
	float FixedI2C_2;
	SensorValue(I2C_1) = 0; //reset sensors
	SensorValue(I2C_2) = 0;
	while (1==1)
	{
		FixedI2C_2 = -(SensorValue(I2C_2)); // to fix sensor bug
		if (SensorValue(controlSwitch) > 1) //if theres no switch then the best tank controls ever
		{
			motor[BLmotor] = vexRT[Ch3]; //left is controlled by left joystick
			motor[FLmotor] = vexRT[Ch3];
			motor[BRmotor] = vexRT[Ch2]; //right is controlled by right joystick
			motor[FRmotor] = vexRT[Ch2];
			if (vexRT[Btn6U] == 1) //if 5U is pressed
			{
				motor[ArmMotorL] = 80; //arms move up
				motor[ArmMotorR] = 80; // modified the speed
			}
			else if (vexRT[Btn5U] == 1) //else if 6U is pressed
			{
				motor[ArmMotorL] = -80; //arms move down
				motor[ArmMotorR] = -80; // modified the speed
			}
			else
			{
				motor[ArmMotorL] = 0;
				motor[ArmMotorR] = 0;
			}
		}
		else if (SensorValue(controlSwitch) == 0) //if theres a switch then steve controls (joystick poopy stuff)
		{
			while (1==1)
			{
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
				motor[ArmMotorL] = vexRT[Ch2]; //arm motors move depending on how high/low right joystick is
				motor[ArmMotorR] = vexRT[Ch2];
			}
		}
	}
}
