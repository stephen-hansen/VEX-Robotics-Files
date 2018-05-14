#pragma config(Sensor, dgtl1,  Bump,           sensorTouch)
#pragma config(Motor,  port2,           clawMotor,     tmotorVex269, openLoop)
#pragma config(Motor,  port4,           frontRightMotor, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           backRightMotor, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           frontLeftMotor, tmotorVex393, openLoop)
#pragma config(Motor,  port7,           backLeftMotor, tmotorVex393, openLoop)
#pragma config(Motor,  port8,           shoulderMotor, tmotorVex269, openLoop)
#pragma config(Motor,  port9,           turnTableMotor, tmotorVex269, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

#include "Vex_Competition_Includes.c"   //Main competition background BOSS code...DO NOT MODIFY LIKE A BOSS!!!!!!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some BOSS actions before the BOSS competition starts. Do them in the
// following BOSS function, but do them LIKE A BOSS!!!
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
// This BOSS task is used to control your BOSS robot during the BOSS autonomous phase of a BOSS VEX Competition.
// You must modify the BOSS code LIKE A BOSS to add your own BOSS robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
  motor[backLeftMotor]=127;
  motor[backRightMotor]=127;
  motor[frontLeftMotor]=127;
  motor[frontRightMotor]=127;
  wait1Msec(1500);
  motor[backLeftMotor]=127;
  motor[backRightMotor]=-127;
  motor[frontLeftMotor]=127;
  motor[frontRightMotor]=-127;
  wait1Msec(300);
  motor[backLeftMotor]=127;
  motor[backRightMotor]=127;
  motor[frontLeftMotor]=127;
  motor[frontRightMotor]=127;
  wait1Msec(1500);
  motor[backLeftMotor]=0;
  motor[backRightMotor]=0;
  motor[frontLeftMotor]=0;
  motor[frontRightMotor]=0;
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This BOSS task is used to control your BOSS robot during the BOSS user control phase of a BOSS VEX Competition.
// You must modify the BOSS code LIKE A BOSS to add your own BOSS robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

//dont modify this unless ur stephen
void TopSecretBumpSwitchStuff()
{
	while(SensorValue(Bump) == 1) //loop thing
		{
			motor[frontRightMotor] = -127;  //Set the motor to go backwards at power level -50
		  motor[frontLeftMotor] = -127; //Set the motor to go backwards at power level -50
		  motor[backLeftMotor] = -127; //blah blah blah
		  motor[backRightMotor] = -127; //insert pointless advice here
		  wait1Msec(1000); //pause code execution for 1000ms (2 seconds)
		  motor[backLeftMotor]=0; // THE
      motor[backRightMotor]=0; // WHEELS
      motor[frontLeftMotor]=0; // WILL
      motor[frontRightMotor]=0; // STOP!!
    }
  }

task usercontrol()
{
	while(1 == 1)
	{
		//Right side of the robot is controlled by the right joystick, Y-axis
		motor[frontRightMotor] = vexRT[Ch2];
		motor[backRightMotor]  = vexRT[Ch2];
		//Left side of the robot is controlled by the left joystick, Y-axis
		motor[frontLeftMotor] = vexRT[Ch3];
		motor[backLeftMotor]  = vexRT[Ch3];
		//Turntable is controlled by right joystick on helper controller
		motor[turnTableMotor] = vexRT[Ch2Xmtr2];
		//Shoulder is controlled by left joystick on helper controller
		motor[shoulderMotor] = vexRT[Ch3Xmtr2];
		//pointless bump switch stuff requested by nick and jonny
    TopSecretBumpSwitchStuff();
		//claw stuff
		if(vexRT[Btn5UXmtr2] == 1)
			{
				motor[clawMotor] = 40;
			}
			else if(vexRT[Btn5DXmtr2] == 1)
			{
			  motor[clawMotor] = -40;
			}
			else
			{
				motor[clawMotor] = 0;
			}

	}
}
