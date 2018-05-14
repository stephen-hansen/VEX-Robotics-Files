#pragma config(Sensor, in1,    betaTest,       sensorAnalog)
#pragma config(Motor,  port2,           FL,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           BL,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           FR,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           BR,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           LiftTL,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           LiftBL,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           LiftTR,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           LiftBR,        tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform Steve is good at coding he is going to write a code that hacks all the pictures saved in our phone
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

int testVar = 1;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  bStopTasksBetweenModes = true;

  if (SensorValue[betaTest] == 0) {
  	testVar = 0; //Enable beta features
    } else {
    testVar = 1; //Disable beta features
	}
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
  // ..........................................................................
  // Insert user code here.
  // ..........................................................................

  // Remove this function call once you have "real" code.
  AutonomousCodePlaceholderForTesting();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
	//Start tasks here
  while (true)
  {
		//Drive motor controls
		if (testVar == 1) { //Default tank controls
			motor[BL] = vexRT[Ch3];
			motor[FL] = vexRT[Ch3];
			motor[BR] = vexRT[Ch2];
			motor[FR] = vexRT[Ch2];
		} else { //Beta motion controls
			if (abs(vexRT[AccelX]) > abs(vexRT[AccelY])) { //Turning Activated
				motor[BL] = vexRT[AccelX];
				motor[FL] = vexRT[AccelX];
				motor[BR] = -vexRT[AccelX];
				motor[FR] = -vexRT[AccelX];
	 	  } else { //Moving Activated
		  	motor[BL] = -vexRT[AccelY];
				motor[FL] = -vexRT[AccelY];
				motor[BR] = -vexRT[AccelY];
				motor[FR] = -vexRT[AccelY];
			}
		}
		//Lift controls
		if (nVexRCReceiveState & vrXmit2) { //Enable partner controls
			motor[LiftTL] = vexRT[Ch3Xmtr2];
			motor[LiftBL] = vexRT[Ch3Xmtr2];
			motor[LiftTR] = vexRT[Ch3Xmtr2];
			motor[LiftBR] = vexRT[Ch3Xmtr2];
		}	else { //Single controls
			if (vexRT[Btn5U] == 1) {
				motor[LiftTL] = 127;
				motor[LiftBL] = 127;
				motor[LiftTR] = 127;
				motor[LiftBR] = 127;
			}	else if (vexRT[Btn5D] == 1) {
				motor[LiftTL] = -127;
				motor[LiftBL] = -127;
				motor[LiftTR] = -127;
				motor[LiftBR] = -127;
			} else {
				motor[LiftTL] = 0;
				motor[LiftBL] = 0;
				motor[LiftTR] = 0;
				motor[LiftBR] = 0;
			}
		}
  }
}
