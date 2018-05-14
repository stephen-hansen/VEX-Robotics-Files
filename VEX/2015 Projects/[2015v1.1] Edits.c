#pragma config(Sensor, in1,    light,          sensorReflection)
#pragma config(Sensor, in2,    gyro,           sensorGyro)
#pragma config(Sensor, in3,    accel,          sensorAccelerometer)
#pragma config(Sensor, in4,    line,           sensorLineFollower)
#pragma config(Motor,  port2,           shooter1,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           lift1,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           lift2,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           lift3,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lift4,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           lift5,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           lift6,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           shooter2,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          flashlight,    tmotorVexFlashlight, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

int LIGHT_VALUE = 2500; //The value of light the robot needs or less to shoot
int DELAY_TIME = 100; //Time between detection of ball and shoot

void shoot (int speed, int time) { //Function to shoot spheres from launcher
	wait1Msec(DELAY_TIME);
	motor[shooter1] = speed;
	motor[shooter2] = speed;
	wait1Msec(time);
	motor[shooter1] = 0;
	motor[shooter2] = 0;
}

task debug () {
	clearLCDLine(0);
	clearLCDLine(1);
	bLCDBacklight = true;									// Turn on LCD Backlight
	string mainBattery;
	displayLCDPos(0,0);
	displayNextLCDString("FIRING!!!");
	displayLCDPos(1,0);
	displayNextLCDString("Battery : ");
	sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V'); //Build the value to be displayed
	displayNextLCDString(mainBattery);
	playSound(soundBeepBeep);
}

task nodebug () {
	playSound(soundLowBuzz);
	clearLCDLine(0);
	clearLCDLine(1);
	bLCDBacklight = true;									// Turn on LCD Backlight
	string mainBattery;
	displayLCDPos(0,0);
	displayNextLCDString("NOT FIRING!!!");
	displayLCDPos(1,0);
	displayNextLCDString("Battery : ");
	sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V'); //Build the value to be displayed
	displayNextLCDString(mainBattery);
}
int debugvar;
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
  debugvar = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous() {
  while (true) {
  	if (SensorValue[line] <= LIGHT_VALUE) {
  		startTask(debug);
  		shoot(127,4000);
  		debugvar = 0;
  	}
  	if (debugvar == 0) {
  		startTask(nodebug);
  		debugvar = 1;
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

task usercontrol() {
	while (true) {
		if (SensorValue[line] <= LIGHT_VALUE) {
  		if (vexRT[Btn5D] == 1 || vexRT[Btn5U] == 1) {
  			startTask(debug);
  			shoot(127,4000);
  			debugvar = 0;
  		}
  	}
  	if (vexRT[Btn6D] == 1 || vexRT[Btn6U] == 1) {
  		startTask(debug);
  		shoot(127,4000);
  		debugvar = 0;
  	}
  	if (debugvar == 0) {
  		startTask(nodebug);
  		debugvar = 1;
  	}
	}
}
