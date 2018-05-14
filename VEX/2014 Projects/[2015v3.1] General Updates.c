#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    controlSwitch,  sensorAnalog)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           BL,            tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           ALT,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           ALB,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           FL,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           FR,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           LC,            tmotorVex269_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           RC,            tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port8,           ARB,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           ART,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          BR,            tmotorVex393_HBridge, openLoop, reversed, encoderPort, I2C_1)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(145)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

//int modifySpeed = 1; // useful in case our robot is "too fast"
//bool isPressed = false; // to be used in the speed cycler
int auto = 0;

// TO DO: change wait statements to encoder statements

void drive(int leftSpeed, int rightSpeed, int time) { //primitive function meant for debugging
	motor[FL] = (leftSpeed);///(modifySpeed));
	motor[BL] = (leftSpeed);///(modifySpeed));
	motor[BR] = (rightSpeed);///(modifySpeed));
	motor[FR] = (rightSpeed);///(modifySpeed));
	wait1Msec(time);
	motor[FL] = 0;///(modifySpeed));
	motor[BL] = 0;///(modifySpeed));
	motor[BR] = 0;///(modifySpeed));
	motor[FR] = 0;///(modifySpeed));
}

void lift(int speed, int lifttime) { // tells arm motors to lift for set amount of time
	motor[ALB] = speed;
	motor[ALT] = speed;
	motor[ARB] = speed;
	motor[ART] = speed;
	wait1Msec(lifttime); // do you even lift
	motor[ALB] = 0;
	motor[ALT] = 0;
	motor[ARB] = 0;
	motor[ART] = 0;
}

task soundEffect() {
	playSoundFile("Airhorn.wav");
}

task airhorn() {
	startTask(soundEffect);
	wait1Msec(1200);
	stopTask(soundEffect);
	clearSounds();
	stopTask(airhorn);
}

task soundEffect2() {
	playSoundFile("Victory.wav");
}

task victory() {
	startTask(soundEffect2);
	wait1Msec(2000);
	stopTask(soundEffect2);
	clearSounds();
	stopTask(victory);
}

task sound1() {
	playSoundFile("GUILE.wav");
}

task sound2() {
	playSoundFile("MEGAMAN.wav");
}

task music1()
{
	while(true) {
		startTask(sound1);
		wait1Msec(2750);
		clearSounds();
	}
}

task music2()
{
	while(true) {
		startTask(sound2);
		wait1Msec(2000);
		clearSounds();
	}
}

task music1Control()
{
	while(true) {
		startTask(sound1);
		wait1Msec(2750);
		clearSounds();
		stopTask(music1Control);
	}
}

task music2Control()
{
	while(true) {
		startTask(sound2);
		wait1Msec(2000);
		clearSounds();
		stopTask(music2Control);
	}
}

void debugControls() {
	// simplistic movement
	if ((vexRT[Btn8U]) == 1) { // go forward one square
		drive(127,127,666);
	}
	if ((vexRT[Btn8D]) == 1) { // go backwards one square
		drive(-127,-127,666);
	}
	if ((vexRT[Btn8L]) == 1) { // turn 90 degrees left
		drive(-127,127,351);
	}
	if ((vexRT[Btn8R]) == 1) { // turn 90 degrees right
		drive(127,-127,351);
	}
	// speed changing
	/*if ((vexRT[Btn7U]) == 1) { // set speed to full speed
	modifySpeed = 1;
	}
	if ((vexRT[Btn7L]) == 1) { // set speed to half speed
	modifySpeed = 2;
	}
	if ((vexRT[Btn7D]) == 1) { // set speed to third speed
	modifySpeed = 3;
	}
	if ((vexRT[Btn7R]) == 1) { // set speed to quarter speed
	modifySpeed = 4;
	}*/
	// SOUND EFFECT BUTTONS are mapped to all shoulder buttons
	if ((vexRT[Btn5U]) == 1) {
		startTask(airhorn);
	}
	if ((vexRT[Btn5D]) == 1) {
		startTask(victory);
	}
	if ((vexRT[Btn6U]) == 1) {
		startTask(music1Control);
	}
	if ((vexRT[Btn6D]) == 1) {
		startTask(music2Control);
	}
	if ((vexRT[Btn7LXmtr2]) == 1) {
		startTask(airhorn);
	}
	if ((vexRT[Btn7RXmtr2]) == 1) {
		startTask(victory);
	}
	if ((vexRT[Btn7UXmtr2]) == 1) {
		startTask(music1Control);
	}
	if ((vexRT[Btn7DXmtr2]) == 1) {
		startTask(music2Control);
	}
}

void simpleAuto() { // Autonomous program to be used when we are not scoring peg pieces in autonomous
	lift(127,1000); // lift up a bit
	drive(127,127,333); // drive forward
	lift(-127,1000); // lift down a bit
	drive(-127,-127,333); // drive backwards
}

void advAutoRed() { // Autonomous peg moving for red team
	lift(127,500); // lift up cube a bit
	drive(127,127,333); // drive forward
	lift(-127,500); // drop cube
	drive(-127,-127,333); // drive back a bit
	drive(127,-127,351); // turn 90 deg right
	lift(127,1000); // lift up more
	drive(127,127,333); // drive forward a bit
	lift(127,500); // lift up a little more
	drive(-127,-127,333); // drive back
	drive(-127,127,351); // turn 90 deg left
	drive(127,127,333); // drive forward a bit
	lift(-127,1250); // lift down some
	drive (-127,-127,333); // drive back
}

void advAutoBlu() { // Autonomous peg moving for blu team
	lift(127,500); // lift up cube a bit
	drive(127,127,333); // drive forward
	lift(-127,500); // drop cube
	drive(-127,-127,333); // drive back a bit
	drive(-127,127,351); // turn 90 deg left
	lift(127,1000); // lift up more
	drive(127,127,333); // drive forward a bit
	lift(127,500); // lift up a little more
	drive(-127,-127,333); // drive back
	drive(127,-127,351); // turn 90 deg right
	drive(127,127,333); // drive forward a bit
	lift(-127,1250); // lift down some
	drive(-127,-127,333); // drive back
}

void placeholderAuto() {
	drive(127,127,3000);
}

void liftControls() // for partner 2
{
	if (vexRT[Btn8UXmtr2] == 1) //if P2 8U is pressed
	{
		motor[ALT] = 127; //lift up
		motor[ALB] = 127;
		motor[ART] = 127;
		motor[ARB] = 127;
	}
	else if (vexRT[Btn8DXmtr2] == 1) //else if P2 8D is pressed
	{
		motor[ALT] = -127; //lift down
		motor[ALB] = -127;
		motor[ART] = -127;
		motor[ARB] = -127;
	}
	else
	{
		motor[ALT] = 0; //do nothing
		motor[ALB] = 0;
		motor[ART] = 0;
		motor[ARB] = 0;
	}
}

void conveyControls() // for partner 2
{
	if (vexRT[Btn5UXmtr2] || vexRT[Btn5DXmtr2] == 1) //if P2 5U or 5D is pressed
	{
		motor[RC] = 127;
		motor[LC] = 127;
	}
	else if (vexRT[Btn6UXmtr2] || vexRT[Btn6DXmtr2] == 1) //else if P2 6D or 6U is pressed
	{
		motor[RC] = -127;
		motor[LC] = -127;
	}
	else
	{
		motor[RC] = 0;
		motor[LC] = 0;
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
	bStopTasksBetweenModes = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
	bLCDBacklight = true;									// Turn on LCD Backlight
	string mainBattery, backupBattery;

	// Clear LCD Lines
	clearLCDLine(0);
	clearLCDLine(1);

	// Top LCD Line Display Stuff:
	displayLCDPos(0,0);
	displayNextLCDString("Auto");
	displayNextLCDChar(' ');
	displayNextLCDChar(':');
	displayNextLCDChar(' ');
	auto = 0;
	for(int i=0; i<50; i++)
	{
		if (nLCDButtons == 1) { // left
			auto = 1;
			}	else if (nLCDButtons == 2) { // center
			auto = 2;
			} else if (nLCDButtons == 4) { // right
			auto = 4;
		}

		displayLCDPos(0,8);
		if (auto == 1) { // left
			displayNextLCDString("Generic");
			}	else if (auto == 2) { // center
			displayNextLCDString("Adv Red");
			} else if (auto == 4) { // right
			displayNextLCDString("Adv Blu");
		  } else {
		  displayNextLCDString("Default");
		}
		displayLCDPos(1,0);
		displayNextLCDString("P:");
		sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V'); //Build the value to be displayed
		displayNextLCDString(mainBattery);
		displayNextLCDString("B:");
		sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');	//Build the value to be displayed
		displayNextLCDString(backupBattery);
		displayNextLCDNumber(i);

		//Wait a little to keep the screen refreshing smoothly:
		wait1Msec(100);
	}
	clearLCDLine(0);
	clearLCDLine(1);
	displayLCDPos(0,0);
	displayNextLCDString("AUTONOMOUS SET!");
	wait1Msec(1000);
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
	int message = random(5);
	clearLCDLine(0);
	clearLCDLine(1);
  //startTask(sound);
	//LCD Line Display Stuff for when the match begins:
	displayLCDPos(0,0);
	if (message == 0) {
		startTask(music1);
		displayNextLCDString("do you even lift");
		displayLCDPos(1,0);
		displayNextLCDString("do you even lift");
		}	else if (message == 1) {
		startTask(music1);
		displayNextLCDString("i r8 8 no b8 m8");
		displayLCDPos(1,0);
		displayNextLCDString("i r8 8 no b8 m8");
		} else if (message == 2) {
		startTask(music1);
		displayNextLCDString("come on and slam");
		displayLCDPos(1,0);
		displayNextLCDString("come on and slam");
		} else if (message == 3) {
		startTask(music2);
		displayNextLCDString("THAT AIN'T FALCO");
		displayLCDPos(1,0);
		displayNextLCDString("THAT AIN'T FALCO");
		} else if (message == 4) {
		startTask(music2);
		displayNextLCDString("DEAL WITH IT");
		displayLCDPos(1,0);
		displayNextLCDString("DEAL WITH IT");
		} else if (message == 5) {
		startTask(music2);
		displayNextLCDString("DUDUDUDUDUDUDUDU");
		displayLCDPos(1,0);
		displayNextLCDString("DUDUDUDUDUDUDUDU");
		}
	if (auto == 1) { // left
		simpleAuto();
		}	else if (auto == 2) { // center
		advAutoRed();
		} else if (auto == 4) { // right
		advAutoBlu();
	  } else if (auto == 0) {
	  placeholderAuto();
	}
	placeholderAuto();
	wait1Msec(7000);
	clearSounds();
	stopTask(music1);
	stopTask(music2);
	stopTask(sound1);
	stopTask(sound2);
	clearSounds();
	playSoundFile("Victory.wav");
	wait1Msec(4000);
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
	clearSounds();
	while (true)
	{
		if (SensorValue(controlSwitch) > 1) //if theres no switch then tank controls
		{
			while(true)
			{
				motor[BL] = (vexRT[Ch3]);///modifySpeed); //left is controlled by left joystick
				motor[FL] = (vexRT[Ch3]);///modifySpeed);
				motor[BR] = (vexRT[Ch2]);///modifySpeed); //right is controlled by right joystick
				motor[FR] = (vexRT[Ch2]);///modifySpeed);
				debugControls(); // debug controls for player 1 (uses buttons)
				liftControls(); // lift controls for player 2 (uses buttons)
				conveyControls(); // conveyor controls
			}
		}
		else if (SensorValue(controlSwitch) == 0) //if theres a switch then enable experimental motion controls
		{
			while(true)
			{
				if (abs(vexRT[AccelX]) > abs(vexRT[AccelY])) //crazy motion controls that mimick a wii remote
				{
					motor[BR] = (-(vexRT[AccelX])) / 2;///modifySpeed); //turning is the chosen control
					motor[FR] = (-(vexRT[AccelX])) / 2;///modifySpeed); //right side is inverted speed of LR
					motor[BL] = (vexRT[AccelX]) / 2;///modifySpeed); //left side isnt inverted
					motor[FL] = (vexRT[AccelX]) / 2;///modifySpeed); //so that it turns in direction of the controller
				}
				else if (abs(vexRT[AccelY]) >= abs(vexRT[AccelX])) //check the direction of the controller's tilt
				{
					motor[BR] = (-(vexRT[AccelY]));///modifySpeed); //driving is the chosen control
					motor[FR] = (-(vexRT[AccelY]));///modifySpeed); //drive forwards/backwards at tilted speed
					motor[BL] = (-(vexRT[AccelY]));///modifySpeed);
					motor[FL] = (-(vexRT[AccelY]));///modifySpeed);
				}
				debugControls();
				liftControls();
				conveyControls();
			}
		}
	}
}
