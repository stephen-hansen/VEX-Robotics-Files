#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    betaTest,       sensorAnalog)
#pragma config(Sensor, I2C_1,  leftWheelEncoder, sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  rightWheelEncoder, sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  rightLiftEncoder, sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           FL,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           BL,            tmotorVex393_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port4,           FR,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           BR,            tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_2)
#pragma config(Motor,  port6,           LiftTL,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           LiftBL,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           LiftTR,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           LiftBR,        tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_3)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"
#include "SongTasks.c" //Songs to be used in the program

int testVar = 1;
//int lspeed;
//int rspeed;
int time = 0;
int debug = 0;
int liftEncSpeed;
int driveEncSpeed;
int oldLiftEnc = 0;
int oldRDriveEnc = 0;
int oldLDriveEnc = 0;
string line1 = "Autonomous 1";
string line2;

int automode = 1;
string side = "Left";
int turnDir = 1;
bool ready = false;
bool pressed = false;
bool record = false;

int oldLeftSpeed = 0;
int oldRightSpeed = 0;
int oldLiftSpeed = 0;

int deadzone3;
int deadzone2;

int t = 0;
int oldT = 0;

//bool click = false;
//bool check = false;
//int seed = 0;
//int step = 1;
//int timeleft = 15000;
//int timechosen;

//void setRandomSeed() {
//	clearLCDLine(0);
//	clearLCDLine(1);
//	check = false;
//	click = false;
//	while (check == false) {
//		bLCDBacklight = true;									// Turn on LCD Backlight
//		displayLCDPos(0,0);
//		string display1;
//		sprintf(display1, "SET RANDSEED");
//		displayNextLCDString(display1);
//		displayLCDPos(1,0);
//		string display2;
//		sprintf(display2, "SEED: %4d", seed);
//		displayNextLCDString(display2);
//		if (nLCDButtons == 1 && click == false) {
//			click = true;
//			seed = seed - 1;
//		} else if (nLCDButtons == 4 && click == false) {
//			click = true;
//			seed = seed + 1;
//		} else if (nLCDButtons == 2) {
//			check = true;
//		} else if (nLCDButtons == 0 && click == true) {
//			click = false;
//		}
//	}
//	clearLCDLine(0);
//	clearLCDLine(1);
//	bLCDBacklight = true;									// Turn on LCD Backlight
//	displayLCDPos(0,0);
//	string display1;
//	sprintf(display1, "RANDSEED SET!");
//	displayNextLCDString(display1);
//	displayLCDPos(1,0);
//	string display2;
//	sprintf(display2, "SEED: %4d", seed);
//	displayNextLCDString(display2);
//}

//void dumbAutonomous() {
//	srand(seed);
//	timeleft = 15000;
//	startTask(smb3);
//	while (timeleft > 0) {
//		clearLCDLine(0);
//		clearLCDLine(1);
//		bLCDBacklight = true;									// Turn on LCD Backlight
//		displayLCDPos(0,0);
//		string display1;
//		sprintf(display1, "RANDAUTO");
//		displayNextLCDString(display1);
//		displayLCDPos(1,0);
//		string display2;
//		sprintf(display2, "STEP: %2d", step);
//		displayNextLCDString(display2);
//		lspeed = random(254) - 127;
//		rspeed = random(254) - 127;
//		motor[BL] = lspeed;
//		motor[FL] = lspeed;
//		motor[BR] = rspeed;
//		motor[FR] = rspeed;
//		timechosen = random(timeleft);
//		timeleft = timeleft - timechosen;
//		wait1Msec(timechosen);
//		step = step + 1;
//	}
//	motor[BL] = 0;
//	motor[FL] = 0;
//	motor[BR] = 0;
//	motor[FR] = 0;
//	clearLCDLine(0);
//	clearLCDLine(1);
//	bLCDBacklight = true;									// Turn on LCD Backlight
//	displayLCDPos(0,0);
//	string display1;
//	sprintf(display1, "RANDAUTO");
//	displayNextLCDString(display1);
//	displayLCDPos(1,0);
//	string display2;
//	sprintf(display2, "COMPLETE");
//	displayNextLCDString(display2);
//}

task timer() {
	time = 0;
	while (true) {
		wait1Msec(1);
		time = time + 1;
	}
}

task preAutonData() {
	while (true) {
		bLCDBacklight = true;
		sprintf(line2, "Side: %5s", side);
		displayLCDPos(0, 0);
		displayNextLCDString(line1);
		displayLCDPos(1, 0);
		displayNextLCDString(line2);
	}
}

task encoderValues() {
	while (true) {
		displayLCDNumber(0, 3, nMotorEncoder[BR], 6);
		displayLCDNumber(1, 3, nMotorEncoder[BL], 6);
	}
}

void lifting(int sp) {
	motor[LiftBL] = sp;
	motor[LiftBR] = sp;
	motor[LiftTL] = sp;
	motor[LiftTR] = sp;
}

void moving(int sp) {
	motor[BR] = sp;
	motor[FR] = sp;
	motor[BL] = sp;
	motor[FL] = sp;
}

void turning(int sp) {
	motor[BR] = sp;
	motor[FR] = sp;
	motor[BL] = -sp;
	motor[FL] = -sp;
}

void right(int sp) {
	motor[BR] = sp;
	motor[FR] = sp;
}

void left(int sp) {
	motor[BL] = sp;
	motor[FL] = sp;
}

void test() {

}

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
	clearDebugStream();
	bStopTasksBetweenModes = true;
	if (SensorValue[betaTest] == 0) {
		testVar = 0; //Enable beta features
		//setRandomSeed();
		} else {
		testVar = 1; //Disable beta features
	}
	//Reset controller
	deadzone2 = vexRT[Ch2];
	deadzone3 = vexRT[Ch3];
	//Reset encoders
	nMotorEncoder[LiftBR] = 0;
	nMotorEncoder[BR] = 0;
	nMotorEncoder[BL] = 0;
	//Reset motors
	motor[BL] = 0;
	motor[BR] = 0;
	motor[FL] = 0;
	motor[FR] = 0;
	motor[LiftBL] = 0;
	motor[LiftBR] = 0;
	startTask(preAutonData);
	startTask(timer);
	while (ready == false) {
		if (time > 3000) { //Failsafe
			ready = true;
		}
		if (nLCDButtons == 1 && pressed == false) {
			pressed = true;
			automode = automode + 1;
			if (automode == 4) {
				automode = 1;
			}
			if (automode == 1) {
				line1 = "Autonomous 1";
				}	else if (automode == 2) {
				line1 = "Autonomous 2";
				} else if (automode == 3) {
				line1 = "Autonomous 3";
			}
			clearLCDLine(0);
			clearLCDLine(1);
			}	else if (nLCDButtons == 2 && pressed == false) {
			pressed = true;
			if (side == "Left") {
				side = "Right";
				}	else {
				side = "Left";
			}
			turnDir = -turnDir;
			clearLCDLine(0);
			clearLCDLine(1);
			}	else if (nLCDButtons == 4 && pressed == false) {
			pressed = true;
			ready = true;
			}	else if (nLCDButtons == 0 && pressed == true) {
			pressed = false;
		}
	}
	stopTask(preAutonData);
	stopTask(timer);
	bLCDBacklight = true;
	clearLCDLine(0);
	clearLCDLine(1);
	if ((time % 10) <= 3) {
		sprintf(line1, "AUTO SET!");
		sprintf(line2, "READY");
		}	else if ((time % 10) <= 5) {
		sprintf(line1, "AUTO GET!");
		sprintf(line2, "REEFY");
		}	else if ((time % 10) <= 7) {
		sprintf(line1, "SET AUTO!");
		sprintf(line2, "GRAVY");
		}	else if ((time % 10) <= 8) {
		sprintf(line1, "SORRY BRO!");
		sprintf(line2, "- YOUNG");
		}	else if ((time % 10) <= 9) {
		sprintf(line1, "HEY, THAT'S");
		sprintf(line2, "PRETTY GOOD!");
	}
	displayLCDPos(0, 0);
	displayNextLCDString(line1);
	displayLCDPos(1, 0);
	displayNextLCDString(line2);
	wait1Msec(2000);
	clearLCDLine(0);
	clearLCDLine(1);
	playSound(soundBlip);
	playSound(soundException);
	playSound(soundBeepBeep);
	playSound(soundLowBuzz);
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
	stopTask(timer);
	//startTask(timer);
	startTask(encoderValues);
	//Reset encoders
	nMotorEncoder[LiftBR] = 0;
	nMotorEncoder[BR] = 0;
	nMotorEncoder[BL] = 0;
	soundPlay = true;
	//startTask(placeholder);
	test();
	if (automode == 1) { //Drive forward
		}	else if (automode == 2) { //Middle stars
		} else if (automode == 3) { //CUBE
	}
	//stopTask(placeholder);
	soundPlay = true;
	startTask(smbdeath);
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
	clearDebugStream();
	t = 0;
	startTask(encoderValues);
	//Reset encoders
	nMotorEncoder[LiftBR] = 0;
	nMotorEncoder[BR] = 0;
	nMotorEncoder[BL] = 0;
	//Reset motors
	motor[BL] = 0;
	motor[BR] = 0;
	motor[FL] = 0;
	motor[FR] = 0;
	motor[LiftBL] = 0;
	motor[LiftBR] = 0;
	//Start tasks here
	stopTask(timer);
	startTask(timer);
	soundPlay = true;
	startTask(pacman);
	while (true)
	{
		liftEncSpeed = nMotorEncoder[LiftBR];
		driveEncSpeed = nMotorEncoder[BR];
		//Drive motor controls
		if (vexRT[Btn8D] == 0 && vexRT[Btn8U] == 0 && vexRT[Btn5D] == 0 && vexRT[Btn6D] == 0) {
			if (testVar == 1) {
				if (fabs(vexRT[Ch3]) <= fabs(deadzone3)) {
					motor[BL] = 0;
					motor[FL] = 0;
					}	else {
					motor[BL] = vexRT[Ch3];
					motor[FL] = vexRT[Ch3];
				}
				if (fabs(vexRT[Ch2]) <= fabs(deadzone2)) {
					motor[BR] = 0;
					motor[FR] = 0;
					} else {
					motor[BR] = vexRT[Ch2];
					motor[FR] = vexRT[Ch2];
				}
				} else { //Motion controls
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
		}
		//Sound controls
		if (soundPlay == false) {
			if (vexRT[Btn7L] == 1) {
				soundPlay = true;
				startTask(zelda);
				} else if (vexRT[Btn7D] == 1) {
				soundPlay = true;
				startTask(ffvii);
				}	else if (vexRT[Btn7R] == 1) {
				soundPlay = true;
				startTask(smb3);
				} else if (vexRT[Btn8L] == 1) {
				soundPlay = true;
				startTask(PokemonGO2);
				} else if (vexRT[Btn8R] == 1) {
				soundPlay = true;
				startTask(PPAP);
			}
		}
		if (vexRT[Btn8D] == 1) {
			moving(-127);
			}	else if (vexRT[Btn8U] == 1) {
			moving(127);
			}	else if (vexRT[Btn5D] == 1) {
			turning(127);
			} else if (vexRT[Btn6D] == 1) {
			turning(-127);
		}
		if (nVexRCReceiveState & vrXmit2) { //Enable partner controls
			motor[LiftTL] = vexRT[Ch3Xmtr2];
			motor[LiftBL] = vexRT[Ch3Xmtr2];
			motor[LiftTR] = vexRT[Ch3Xmtr2];
			motor[LiftBR] = vexRT[Ch3Xmtr2];
			}	else { //Single controls
			if (vexRT[Btn5U] == 1) {
				lifting(127);
				}	else if (vexRT[Btn6U] == 1) {
				lifting(-127);
				} else {
				lifting(0);
			}
		}

		//Auto generator
		if ((sgn(oldLeftSpeed) != sgn(motor[BL]) && (fabs(motor[BL]) > fabs(deadzone3)))
			|| (sgn(oldRightSpeed) != sgn(motor[BR]) && (fabs(motor[BR]) > fabs(deadzone2)))
	    || (sgn(oldLiftSpeed) != sgn(motor[LiftBR]) && (motor[LiftBR] != 0))) {
			if (record == true) {
				if (sgn(oldLeftSpeed) > sgn(motor[BL]) && (fabs(motor[BL]) > fabs(deadzone3))) {
					writeDebugStreamLine("while (nMotorEncoder[BL] < %d) {", nMotorEncoder[BL]);
				}	else if (sgn(oldLeftSpeed) < sgn(motor[BL]) && (fabs(motor[BL]) > fabs(deadzone3))) {
					writeDebugStreamLine("while (nMotorEncoder[BL] > %d) {", nMotorEncoder[BL]);
				} else if (sgn(oldRightSpeed) > sgn(motor[BR]) && (fabs(motor[BR]) > fabs(deadzone2))) {
					writeDebugStreamLine("while (nMotorEncoder[BR] < %d) {", nMotorEncoder[BR]);
				}	else if (sgn(oldRightSpeed) < sgn(motor[BR]) && (fabs(motor[BR]) > fabs(deadzone2))) {
					writeDebugStreamLine("while (nMotorEncoder[BR] > %d) {", nMotorEncoder[BR]);
				}	else if (sgn(oldLiftSpeed) < sgn(motor[LiftBR]) && (motor[LiftBR] != 0)) {
					writeDebugStreamLine("while (nMotorEncoder[LiftBR] > %d) {", nMotorEncoder[LiftBR]);
				} else if (sgn(oldLiftSpeed) > sgn(motor[LiftBR]) && (motor[LiftBR] != 0)) {
					writeDebugStreamLine("while (nMotorEncoder[LiftBR] < %d) {", nMotorEncoder[LiftBR]);
				} else {
					debug = 1;
				}
				writeDebugStreamLine("	left(%d);", oldLeftSpeed);
				writeDebugStreamLine("	right(%d);", oldRightSpeed);
				writeDebugStreamLine("	lift(%d);", oldLiftSpeed);
				if (debug != 1) {
					writeDebugStreamLine("}");
				} else {
					debug = 0;
				}
			} else {
			  record = true;
			}
			oldLeftSpeed = sgn(motor[BL]) * 127;
			oldRightSpeed = sgn(motor[BR]) * 127;
			oldLiftSpeed = sgn(motor[LiftBR]) * 127;
			oldRDriveEnc = nMotorEncoder[BR];
			oldLDriveEnc = nMotorEncoder[BL];
			oldLiftEnc = nMotorEncoder[LiftBR];
		}
	}
}
