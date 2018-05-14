#pragma config(Sensor, dgtl1,  Bump,           sensorTouch)
#pragma config(Motor,  port2,           clawMotor,     tmotorVex393, openLoop)
#pragma config(Motor,  port3,           elbowMotor,    tmotorVex269, openLoop)
#pragma config(Motor,  port4,           frontRightMotor, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           backRightMotor, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           frontLeftMotor, tmotorVex393, openLoop)
#pragma config(Motor,  port7,           backLeftMotor, tmotorVex393, openLoop)
#pragma config(Motor,  port8,           shoulderMotor, tmotorVex393, openLoop)
#pragma config(Motor,  port9,           turnTableMotor, tmotorVex269, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

#include "Vex_Competition_Includes.c"   //Main competition background BOSS code...DO NOT MODIFY LIKE A BOSS!!!!!!
/*How to Control Guide
Robot has a 15 second autonomous. It will drive forward, turn, and drive forward again.
Main control uses the joysticks to move the wheels.
Main left joystick = left wheels
Main right joystick = right wheels
Helper control works the arm.
Helper left joystick = shoulder
Helper right joystick = turntable
Helper 5UX and 5DX buttons = claw
Helper Left U and D buttons = elbow
if bump switch is hit, robot will move forward a bit*/

//have fun - lead boss programmer steve hansen

//tip of the day: use compile to check for errors, then google how to fix those errors.

//this area has code for control/autonomous. add codes here whenever making a new function for a motor, and edit these to ur liking.

//current functions here: auto driving, auto turning, bump switch, elbow control, claw control.

void DriveStuff(int T, int S) //set T to time amount, and S to speed level
{
	motor[backLeftMotor]=S; //drive according to S (speed level)
	motor[backRightMotor]=S;
	motor[frontLeftMotor]=S;
	motor[frontRightMotor]=S;
	wait1Msec(T); // time driving according to T (time amount)
	motor[backLeftMotor]=0; // after T (time amount) ends, the robot stops
	motor[backRightMotor]=0;
	motor[frontLeftMotor]=0;
	motor[frontRightMotor]=0; // Experiment with speed and time to determine how far the robot drives
}

void TurnStuff (int T, int S) // same variables as DriveStuff (time and speed) but turns
{
	motor[backLeftMotor]=S; // set S to the speed level you want your robot to turn
	motor[backRightMotor]=-S;
	motor[frontLeftMotor]=S;
	motor[frontRightMotor]=-S;
	wait1Msec(T); //insert time here
	motor[backLeftMotor]=0; // the robot stops after time is up
	motor[backRightMotor]=0;
	motor[frontLeftMotor]=0;
	motor[frontRightMotor]=0; //Experiment with speed and time to determine the turn angle of the robot
}

void TopSecretBumpSwitchStuff() //this code is set to make the robot drive forward when bump switch is hit
{
	while(SensorValue(Bump) == 1) //loop thing
	{
		DriveStuff(1000, 127); //drive stuff
	}
	if(vexRT[Btn6UXmtr2] == 1)
	{
		(SensorValue(Bump) == 0);
	}

}

void ElbowStuff(int x) //this code in a nutshell:
{
	if(vexRT[Btn7UXmtr2] == 1) //if helper control button 7U is hit
	{
		motor[elbowMotor] = x; //the elbow motor moves up
	}
	else if(vexRT[Btn7DXmtr2] == 1) //else if helper control button 7D is hit
	{
		motor[elbowMotor] = -x; //the elbow motor moves down
	}
	else //if nothing happens
	{
		motor[elbowMotor] = 0; //nothing happens
	}

}

void ShoulderStuff(int x) //this code in a nutshell:
{
	if(vexRT[Btn8UXmtr2] == 1) //if helper control button 8U is hit
	{
		motor[shoulderMotor] = x; //the shoulder motor moves up
	}
	else if(vexRT[Btn8DXmtr2] == 1) //else if helper control button 8D is hit
	{
		motor[shoulderMotor] = -x; //the shoulder motor moves down
	}
	else //if nothing happens
	{
		motor[shoulderMotor] = 0; //nothing happens
	}

}

void ClawStuff(int x) //this code in a nutshell (basically same as ElbowStuff)
{
	if(vexRT[Btn5UXmtr2] == 1) //if helper control button 5UX is hit
	{
		motor[clawMotor] = x; //claw motor opens
	}
	else if(vexRT[Btn5DXmtr2] == 1) //else if helper control button 5DX is hit
	{
		motor[clawMotor] = -x; //claw motor closes
	}
	else //if nothing happens
	{
		motor[clawMotor] = 0; //NOTHING HAPPENS
	}

}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some BOSS actions before the BOSS competition starts. Do them in the
// following BOSS function, but do them LIKE A BOSS!!!
//
/////////////////////////////////////////////////////////////////////////////////////////

//nothing here for now

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
	//autonomous is set so that the robot goes forward, turns right/left, goes forward again, and stops. seriously, dont modify.
	DriveStuff(1500, 127);
	TurnStuff(300, 127);
	DriveStuff(1500, 127);
	TopSecretBumpSwitchStuff(); //bump switch will work in autonomous, but I don't think it will actually operate in autonomous
	// --FUTURE IDEA-- might add sensors that make robot automatically work in autonomous
	// note: whatever you do, don't add any user control elements here
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

task usercontrol()
{
	while(1 == 1) //1 always equals 1 so this is always true derp
	{
		//Right side of the robot is controlled by the right joystick, Y-axis
		motor[frontRightMotor] = vexRT[Ch2];
		motor[backRightMotor]  = vexRT[Ch2];
		//Left side of the robot is controlled by the left joystick, Y-axis
		motor[frontLeftMotor] = vexRT[Ch3];
		motor[backLeftMotor]  = vexRT[Ch3];
		//Turntable is controlled by right joystick on helper controller
		motor[turnTableMotor] = vexRT[Ch2Xmtr2];
		//nothing with left joystick yet
		//pointless bump switch stuff requested by nick and jonny
		TopSecretBumpSwitchStuff();
		//Elbow motor is controlled by buttons
		ElbowStuff(40);
		//Shoulder stuff
		ShoulderStuff(40);
		//claw stuff
		ClawStuff(127);
		//le end of le code
		//you should probably add any new functions here that you make (unless it is some sort of autonomous function)
	}
}
