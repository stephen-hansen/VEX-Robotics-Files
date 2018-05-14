#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    limiter,        sensorPotentiometer)
#pragma config(Sensor, in8,    betaTest,       sensorAnalog)
#pragma config(Sensor, I2C_1,  lockEncoder,    sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  rightLiftEncoder, sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  rightWheelEncoder, sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_4,  leftWheelEncoder, sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           lock,          tmotorVex393_HBridge, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port2,           FL,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           BL,            tmotorVex393_MC29, openLoop, encoderPort, I2C_4)
#pragma config(Motor,  port4,           FR,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           BR,            tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_3)
#pragma config(Motor,  port6,           LiftTL,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           LiftBL,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           LiftTR,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           LiftBR,        tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_2)
#pragma config(Motor,  port10,          spinners,      tmotorVex393_HBridge, openLoop)
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
string line1 = "Autonomous 1";
string line2;
int mode = 0;
int mode2 = 0;
bool locked = true;
string linee1, linee2;
string mainBattery, backupBattery;

int potent = 0;
int automode = 1;
string side = "Left";
int turnDir = -1;
bool ready = false;
bool pressed = false;

int deadzone3;
int deadzone2;
int limit = 0;

int auSpeed = 25;
int debugSpeed = 50;
int lockTime = 500;
int lockLim = 3600; //Hits 3700 max
int lockEncVal = 500;
int liftEncVal;
int drive1SquareEncVal = 400; //Need to test, KILL CLICKY MOTOR
int turn90DegEncVal;
int holdSpeed = 20; //20 without rubber bands

float voltage = nImmediateBatteryLevel;

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
		clearLCDLine(0);
		clearLCDLine(1);
		displayLCDString(0, 0, "Limiter: ");
		sprintf(linee1, "%4d", SensorValue[limiter]);
		displayNextLCDString(linee1);
		displayLCDString(1, 0, "LockEnc: ");
		sprintf(linee2, "%4d", nMotorEncoder[lock]);
		displayNextLCDString(linee2);
		wait1Msec(100);
	}
}

void locking(int sp) {
	motor[lock] = sp;
}

void lifting(int sp) {
	motor[LiftBL] = sp;
	motor[LiftBR] = sp;
	motor[LiftTL] = sp;
	motor[LiftTR] = sp;
}

task lockIt() {
	limit = 1;
	locking(127);
	lifting(-holdSpeed);
	while (nMotorEncoder[lock] < 0) {
	}
	locking(0);
	lifting(0);
	locked = true;
	limit = 0;
}

task unlockIt() {
	limit = 1;
	locking(-127);
	lifting(0);
	while (nMotorEncoder[lock] > -lockEncVal) {
	}
	locking(0);
	locked = false;
	limit = 0;
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

void auto1() { //Go forward
	moving(127); //Drop spinners
	wait1Msec(500);
	moving(-127);
	wait1Msec(500);
	moving(127);
	wait1Msec(500);
	moving(-127);
	wait1Msec(500);
	moving(0);
	wait1Msec(500); //Wait
	locking(-127); //Unlock
	lifting(0);
	while (nMotorEncoder[lock] > -lockEncVal) {
	}
	locking(0);
	locked = false;
	limit = 0;
	lifting(127); //Lift up
	wait1Msec(1750);
	lifting(0);
	moving(127); //Move up
	wait1Msec(1750);
	moving(-127); //Move back
	wait1Msec(2000);
	moving(0);
}

void auto2() { //Debug
	moving(127); //Drop spinners
	wait1Msec(500);
	moving(-127);
	wait1Msec(500);
	moving(127);
	wait1Msec(500);
	moving(-127);
	wait1Msec(500);
	moving(0);
	wait1Msec(500); //Wait
	wait1Msec(500); //Wait
	locking(-127); //Unlock
	lifting(0);
	while (nMotorEncoder[lock] > -lockEncVal) {
	}
	locking(0);
	locked = false;
	limit = 0;
	lifting(-127); //Lift up
	wait1Msec(1000);
	lifting(0);
	moving(-127); //Move back
	while (abs(nMotorEncoder[BR]) < 2*drive1SquareEncVal) {
	}
	nMotorEncoder[BR] = 0;
	moving(0);
}

//void auto2() { //Middle stars
//	moving(127); //Drop spinners
//	wait1Msec(500);
//	moving(-127);
//	wait1Msec(500);
//	moving(127);
//	wait1Msec(500);
//	moving(-127);
//	wait1Msec(500);
//	moving(0);
//	wait1Msec(500); //Wait
//	locking(-127); //Unlock
//	lifting(0);
//	while (nMotorEncoder[lock] > -lockEncVal) {
//	}
//	locking(0);
//	locked = false;
//	limit = 0;
//	turning(turnDir * 60); //Turn to middle
//	wait1Msec(500);
//	turning(0);
//	lifting(127); //Lift up
//	wait1Msec(1750);
//	lifting(0);
//	moving(127); //Move up
//	wait1Msec(1000);
//	moving(0);
//	moving(127); //Move up
//	wait1Msec(1500);
//	moving(-127); //Go back
//	wait1Msec(1500);
//	moving(0);
//}

void auto3() { //Cube

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
	if (vexRT[Btn5D] == 1 || vexRT[Btn5U] == 1 || vexRT[Btn6D] == 1 || vexRT[Btn6U] == 1) {
	}	//Skip bootup
	else {
	SensorType[limiter] = sensorNone;
	wait1Msec(1000);
	SensorType[limiter] = sensorPotentiometer;
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
	nMotorEncoder[lock] = 0;
	//Reset motors
	motor[BL] = 0;
	motor[BR] = 0;
	motor[FL] = 0;
	motor[FR] = 0;
	motor[LiftBL] = 0;
	motor[LiftBR] = 0;
	clearLCDLine(0);
	clearLCDLine(1);
	bLCDBacklight = true;
	//Show battery data before match
	displayLCDString(0, 0, "Primary: ");
	sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V'); //Build the value to be displayed
	displayNextLCDString(mainBattery);
	displayLCDString(1, 0, "Backup: ");
	sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');    //Build the value to be displayed
	displayNextLCDString(backupBattery);
	wait1Msec(2000);
	clearLCDLine(0);
	clearLCDLine(1);
	startTask(preAutonData);
	startTask(timer);
	while (ready == false) {
		if (time > 3000) { //Failsafe, normally 3000
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
	}
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
	startTask(pacman);
	//Reset encoders
	nMotorEncoder[LiftBR] = 0;
	nMotorEncoder[BR] = 0;
	nMotorEncoder[BL] = 0;
	soundPlay = true;
	//startTask(placeholder);
	if (automode == 1) { //Drive forward
		auto1();
		}	else if (automode == 2) { //Middle stars
		auto2();
		} else if (automode == 3) { //CUBE
		auto3();
		} else {
		auto1();
	}
	stopTask(pacman);
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
	stopTask(timer);
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
	startTask(balloon);
	while (true)
	{
		potent = SensorValue[limiter];
		//Drive motor controls
		if (vexRT[Btn8D] == 0 && vexRT[Btn8U] == 0 && vexRT[Btn8L] == 0 && vexRT[Btn8R] == 0) {
			if (testVar == 1) {
				if (abs(vexRT[Ch3]) <= abs(deadzone3)) {
					motor[BL] = 0;
					motor[FL] = 0;
					}	else {
					motor[BL] = vexRT[Ch3];
					motor[FL] = vexRT[Ch3];
				}
				if (abs(vexRT[Ch2]) <= abs(deadzone2)) {
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
			if (vexRT[Btn7R] == 1) {
				soundPlay = true;
				startTask(PokemonGO2);
				} else if (vexRT[Btn7D] == 1) {
				soundPlay = true;
				startTask(PPAP);
			} else if (vexRT[Btn7L] == 1) {
				soundPlay = true;
				startTask(smb3);
			} else if (vexRT[Btn7U] == 1) {
				soundPlay = true;
				startTask(smw2_map);
			}
		}
		if (vexRT[Btn8D] == 1) {
			mode = 1;
			motor[BR] = -127;
			motor[BL] = -127;
			motor[FL] = -127;
			motor[FR] = -127;
			while (abs(nMotorEncoder[BR]) < drive1SquareEncVal) {
			}
			nMotorEncoder[BR] = 0;
			motor[BR] = 0;
			motor[BL] = 0;
			motor[FL] = 0;
			motor[FR] = 0;
			}	else if (vexRT[Btn8U] == 1) {
			mode = 2;
			motor[BR] = 127;
			motor[BL] = 127;
			motor[FL] = 127;
			motor[FR] = 127;
			while (abs(nMotorEncoder[BR]) < drive1SquareEncVal) {
			}
			nMotorEncoder[BR] = 0;
			motor[BR] = 0;
			motor[BL] = 0;
			motor[FL] = 0;
			motor[FR] = 0;
			}	else if (vexRT[Btn8L] == 1) {
			mode = 3;
			turning(-debugSpeed);
			} else if (vexRT[Btn8R] == 1) {
			mode = 4;
			turning(debugSpeed);
			} else { //AutoGenerator
			if (mode != 0) {
				if (mode == 1) {
					writeDebugStreamLine("while (nMotorEncoder[BR] > %d) {", nMotorEncoder[BR]);
					writeDebugStreamLine("	moving(-auSpeed);");
					writeDebugStreamLine("}");
					writeDebugStreamLine("moving(0);");
					writeDebugStreamLine("wait1Msec(100);");
					}	else if (mode == 2) {
					writeDebugStreamLine("while (nMotorEncoder[BR] < %d) {", nMotorEncoder[BR]);
					writeDebugStreamLine("	moving(auSpeed);");
					writeDebugStreamLine("}");
					writeDebugStreamLine("moving(0);");
					writeDebugStreamLine("wait1Msec(100);");
					} else if (mode == 3) {
					writeDebugStreamLine("while (nMotorEncoder[BR] < %d) {", nMotorEncoder[BR]);
					writeDebugStreamLine("	right(auSpeed);");
					writeDebugStreamLine("}");
					writeDebugStreamLine("right(0);");
					writeDebugStreamLine("wait1Msec(100);");
					} else if (mode == 4) {
					writeDebugStreamLine("while (nMotorEncoder[BL] < %d) {", nMotorEncoder[BL]);
					writeDebugStreamLine("	left(auSpeed);");
					writeDebugStreamLine("}");
					writeDebugStreamLine("left(0);");
					writeDebugStreamLine("wait1Msec(100);");
				}
				mode = 0;
			}
		}
		if (vexRT[Btn5U] == 1 || vexRT[Btn6U] == 1) {
			if (locked == true && limit == 0) {
				startTask(unlockIt);
			}	else if (locked == false) {
				if (vexRT[Btn5U] == 1) {
					lifting(127);
				}	else if (vexRT[Btn6U] == 1) {
					lifting(-127);
				}
			}
		} else if (vexRT[Btn5U] == 0 && vexRT[Btn6U] == 0) {
			if (locked == false && limit == 0 && potent > lockLim) {
				startTask(lockIt);
			} else if (limit == 0 && potent <= lockLim) {
				lifting(0);
			}
		}
		if (vexRT[Btn6D] == 1) {
			motor[spinners] = 127;
		}	else if (vexRT[Btn5D] == 1) {
			motor[spinners] = -127;
		} else {
			motor[spinners] = 0;
		}
	}
}
