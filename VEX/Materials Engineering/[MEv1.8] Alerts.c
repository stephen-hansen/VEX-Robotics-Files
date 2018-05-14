#pragma config(Sensor, in3,    line,           sensorLineFollower)
#pragma config(Sensor, dgtl3,  sonar,          sensorSONAR_cm)
#pragma config(Motor,  port2,           FL,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           BL,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           FR,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           BR,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          flashlight,    tmotorVexFlashlight, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define ARRAYSIZE(a) (sizeof(a)/sizeof(a[0]))
float pitch = 0.25;
int count = 1;
int CHANGE = 50; //CHANGE SPEED
int bpm = 120; //BEATS PER MINUTE
int spm = 100; //STROBE PER MINUTE
string power = "off";
string recordS = "ready";
float rec[100][10];
int recBpm[100][10];
string mode = "debug";
string prevMode = "debug";
string d1;
string d2;
int rData = 0;
int curData = 0;

void message () {
	clearLCDLine(0);
	clearLCDLine(1);
		bLCDBacklight = true;									// Turn on LCD Backlight
		displayLCDPos(0,0);
		displayNextLCDString(d1);
		displayLCDPos(1,0);
		displayNextLCDString(d2);
}

//timing = 60000/bpm
//TODO:
//UPLOAD SONGS AND CONFIG THEM TO BUTTONS (SEE BOOKMARKS)
//Upload chiptune config
//Add alerts
//Be able to turn off light (switch!!!)
//Get wheels/motors
//Add recorder [Done-ish, need to add alert]

task smb_under()
{
  //        100 = Tempo
  //          6 = Default octave
  //    Quarter = Default note length
  //        10% = Break between notes
  //
  PlayTone(  784,    7); wait1Msec(  75);  // Note(C, Duration(32th))
  PlayTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
  PlayTone( 1046,    7); wait1Msec(  75);  // Note(C7, Duration(32th))
  PlayTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
  PlayTone(  880,    7); wait1Msec(  75);  // Note(A5, Duration(32th))
  PlayTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
  PlayTone( 1320,    7); wait1Msec(  75);  // Note(A, Duration(32th))
  PlayTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
  PlayTone(  932,    7); wait1Msec(  75);  // Note(A#5, Duration(32th))
  PlayTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
  PlayTone( 1398,    7); wait1Msec(  75);  // Note(A#, Duration(32th))
  PlayTone(    0,  108); wait1Msec(1200);  // Note(Rest, Duration(Half))
  PlayTone(  784,    7); wait1Msec(  75);  // Note(C, Duration(32th))
  PlayTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
  PlayTone( 1046,    7); wait1Msec(  75);  // Note(C7, Duration(32th))
  PlayTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
  PlayTone(  880,    7); wait1Msec(  75);  // Note(A5, Duration(32th))
  PlayTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
  PlayTone( 1320,    7); wait1Msec(  75);  // Note(A, Duration(32th))
  PlayTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
  PlayTone(  932,    7); wait1Msec(  75);  // Note(A#5, Duration(32th))
  PlayTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
  PlayTone( 1398,    7); wait1Msec(  75);  // Note(A#, Duration(32th))
  PlayTone(    0,  108); wait1Msec(1200);  // Note(Rest, Duration(Half))
  PlayTone(  698,    7); wait1Msec(  75);  // Note(F5, Duration(32th))
  PlayTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
  PlayTone( 1047,    7); wait1Msec(  75);  // Note(F, Duration(32th))
  PlayTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
  PlayTone(  587,    7); wait1Msec(  75);  // Note(D5, Duration(32th))
  PlayTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
  PlayTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
  PlayTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
  PlayTone(  622,    7); wait1Msec(  75);  // Note(D#5, Duration(32th))
  PlayTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
  PlayTone(  933,    7); wait1Msec(  75);  // Note(D#, Duration(32th))
  PlayTone(    0,  108); wait1Msec(1200);  // Note(Rest, Duration(Half))
  PlayTone(  698,    7); wait1Msec(  75);  // Note(F5, Duration(32th))
  PlayTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
  PlayTone( 1047,    7); wait1Msec(  75);  // Note(F, Duration(32th))
  PlayTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
  PlayTone(  587,    7); wait1Msec(  75);  // Note(D5, Duration(32th))
  PlayTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
  PlayTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
  PlayTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
  PlayTone(  622,    7); wait1Msec(  75);  // Note(D#5, Duration(32th))
  PlayTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
  PlayTone(  933,    7); wait1Msec(  75);  // Note(D#, Duration(32th))
  return;
}

task smw_title()
{
  //        125 = Tempo
  //          5 = Default octave
  //    Quarter = Default note length
  //        10% = Break between notes
  //
  PlayTone( 1174,   22); wait1Msec( 240);  // Note(D7, Duration(Eighth))
  PlayTone( 1174,   22); wait1Msec( 240);  // Note(D7, Duration(Eighth))
  PlayTone( 1174,   22); wait1Msec( 240);  // Note(D7, Duration(Eighth))
  PlayTone(  880,   22); wait1Msec( 240);  // Note(D6, Duration(Eighth))
  PlayTone( 1174,   22); wait1Msec( 240);  // Note(D7, Duration(Eighth))
  PlayTone( 1174,   22); wait1Msec( 240);  // Note(D7, Duration(Eighth))
  PlayTone( 1174,   22); wait1Msec( 240);  // Note(D7, Duration(Eighth))
  PlayTone(  880,   22); wait1Msec( 240);  // Note(D6, Duration(Eighth))
  PlayTone( 1244,   86); wait1Msec( 960);  // Note(D#7, Duration(Half))
  PlayTone( 1174,   22); wait1Msec( 240);  // Note(D7, Duration(Eighth))
  PlayTone(    0,   43); wait1Msec( 480);  // Note(Rest)
  PlayTone(    0,    5); wait1Msec(  60);  // Note(Rest, Duration(32th))
  PlayTone(  880,   22); wait1Msec( 240);  // Note(D6, Duration(Eighth))
  PlayTone( 1481,   22); wait1Msec( 240);  // Note(B6, Duration(Eighth))
  PlayTone( 1481,   22); wait1Msec( 240);  // Note(B6, Duration(Eighth))
  PlayTone( 1481,   22); wait1Msec( 240);  // Note(B6, Duration(Eighth))
  PlayTone(  880,   22); wait1Msec( 240);  // Note(D6, Duration(Eighth))
  PlayTone( 1481,   22); wait1Msec( 240);  // Note(B6, Duration(Eighth))
  PlayTone( 1481,   22); wait1Msec( 240);  // Note(B6, Duration(Eighth))
  PlayTone( 1481,   22); wait1Msec( 240);  // Note(B6, Duration(Eighth))
  PlayTone(  880,   22); wait1Msec( 240);  // Note(D6, Duration(Eighth))
  PlayTone( 1481,   22); wait1Msec( 240);  // Note(B6, Duration(Eighth))
  PlayTone( 1481,   22); wait1Msec( 240);  // Note(B6, Duration(Eighth))
  PlayTone( 1481,   22); wait1Msec( 240);  // Note(B6, Duration(Eighth))
  PlayTone( 1481,   11); wait1Msec( 120);  // Note(B6, Duration(16th))
  PlayTone( 1046,   11); wait1Msec( 120);  // Note(C7, Duration(16th))
  PlayTone( 1481,   43); wait1Msec( 480);  // Note(B6)
  PlayTone( 1320,   22); wait1Msec( 240);  // Note(A6, Duration(Eighth))
  PlayTone(  880,   22); wait1Msec( 240);  // Note(D6, Duration(Eighth))
  PlayTone( 1320,   22); wait1Msec( 240);  // Note(A6, Duration(Eighth))
  PlayTone( 1320,   22); wait1Msec( 240);  // Note(A6, Duration(Eighth))
  PlayTone( 1320,   22); wait1Msec( 240);  // Note(A6, Duration(Eighth))
  PlayTone(  880,   22); wait1Msec( 240);  // Note(D6, Duration(Eighth))
  PlayTone( 1320,   22); wait1Msec( 240);  // Note(A6, Duration(Eighth))
  PlayTone( 1320,   22); wait1Msec( 240);  // Note(A6, Duration(Eighth))
  PlayTone( 1320,   22); wait1Msec( 240);  // Note(A6, Duration(Eighth))
  PlayTone(  880,   22); wait1Msec( 240);  // Note(D6, Duration(Eighth))
  PlayTone( 1320,   22); wait1Msec( 240);  // Note(A6, Duration(Eighth))
  PlayTone( 1320,   22); wait1Msec( 240);  // Note(A6, Duration(Eighth))
  PlayTone( 1320,   22); wait1Msec( 240);  // Note(A6, Duration(Eighth))
  PlayTone( 1320,   11); wait1Msec( 120);  // Note(A6, Duration(16th))
  PlayTone( 1481,   11); wait1Msec( 120);  // Note(B6, Duration(16th))
  PlayTone( 1320,   43); wait1Msec( 480);  // Note(A6)
  PlayTone( 1175,   22); wait1Msec( 240);  // Note(G6, Duration(Eighth))
  PlayTone(  880,   22); wait1Msec( 240);  // Note(D6, Duration(Eighth))
  PlayTone( 1481,   22); wait1Msec( 240);  // Note(B6, Duration(Eighth))
  PlayTone( 1481,   22); wait1Msec( 240);  // Note(B6, Duration(Eighth))
  PlayTone( 1481,   22); wait1Msec( 240);  // Note(B6, Duration(Eighth))
  PlayTone(  880,   22); wait1Msec( 240);  // Note(D6, Duration(Eighth))
  PlayTone( 1481,   22); wait1Msec( 240);  // Note(B6, Duration(Eighth))
  PlayTone( 1481,   22); wait1Msec( 240);  // Note(B6, Duration(Eighth))
  PlayTone( 1481,   22); wait1Msec( 240);  // Note(B6, Duration(Eighth))
  PlayTone(  880,   22); wait1Msec( 240);  // Note(D6, Duration(Eighth))
  PlayTone( 1481,   22); wait1Msec( 240);  // Note(B6, Duration(Eighth))
  PlayTone( 1481,   22); wait1Msec( 240);  // Note(B6, Duration(Eighth))
  PlayTone( 1481,   22); wait1Msec( 240);  // Note(B6, Duration(Eighth))
  PlayTone( 1320,   11); wait1Msec( 120);  // Note(A6, Duration(16th))
  PlayTone( 1481,   11); wait1Msec( 120);  // Note(B6, Duration(16th))
  PlayTone( 1046,   43); wait1Msec( 480);  // Note(C7)
  PlayTone( 1318,   43); wait1Msec( 480);  // Note(E7)
  PlayTone( 1174,   22); wait1Msec( 240);  // Note(D7, Duration(Eighth))
  PlayTone( 1174,   22); wait1Msec( 240);  // Note(D7, Duration(Eighth))
  PlayTone( 1174,   22); wait1Msec( 240);  // Note(D7, Duration(Eighth))
  PlayTone(  880,   22); wait1Msec( 240);  // Note(D6, Duration(Eighth))
  PlayTone( 1046,   22); wait1Msec( 240);  // Note(C7, Duration(Eighth))
  PlayTone( 1046,   22); wait1Msec( 240);  // Note(C7, Duration(Eighth))
  PlayTone( 1046,   22); wait1Msec( 240);  // Note(C7, Duration(Eighth))
  PlayTone( 1109,   22); wait1Msec( 240);  // Note(F#6, Duration(Eighth))
  PlayTone( 1175,   86); wait1Msec( 960);  // Note(G6, Duration(Half))
  return;
}

task music () {
	count = 1;
	int ignore = SensorValue[sonar];
	while (true) {
		if(bSoundQueueAvailable && SensorValue[sonar] < ignore) // if there is still space in the Sound Queue:
		{
			int tone = abs(SensorValue[sonar])*pitch;
			playImmediateTone(tone, 50);  // play tone according to sensor readings
			if (recordS == "startReady") {
				rec[(count)][(rData)] = tone;
				recBpm[(count)][(rData)] = bpm;
				count = count + 1;
			}
			wait1Msec((60000/bpm));
		}
	}
}

task debug () {
	clearLCDLine(0);
	clearLCDLine(1);
	while (true) {
		bLCDBacklight = true;									// Turn on LCD Backlight
		displayLCDPos(0,0);
		string display1;
		sprintf(display1, "BPM:%3d  STR:%3d", bpm, spm);
		displayNextLCDString(display1);
		displayLCDPos(1,0);
		string display2;
		sprintf(display2, "PITCH: %4f", pitch);
		displayNextLCDString(display2);
	}
}

task bpmConfig () {
	clearLCDLine(0);
	clearLCDLine(1);
	while (true) {
		bLCDBacklight = true;									// Turn on LCD Backlight
		displayLCDPos(0,0);
		string display1;
		sprintf(display1, " CONFIGURE  BPM ");
		displayNextLCDString(display1);
		displayLCDPos(1,0);
		string display2;
		sprintf(display2, "    BPM: %3d    ", bpm);
		displayNextLCDString(display2);
	}
}

task spmConfig () {
	clearLCDLine(0);
	clearLCDLine(1);
	while (true) {
		bLCDBacklight = true;									// Turn on LCD Backlight
		displayLCDPos(0,0);
		string display1;
		sprintf(display1, "CONFIGURE STROBE");
		displayNextLCDString(display1);
		displayLCDPos(1,0);
		string display2;
		sprintf(display2, "STROBE RATE: %3d", spm);
		displayNextLCDString(display2);
	}
}

task pitchConfig () {
	clearLCDLine(0);
	clearLCDLine(1);
	while (true) {
		bLCDBacklight = true;									// Turn on LCD Backlight
		displayLCDPos(0,0);
		string display1;
		sprintf(display1, "CONFIGURE  PITCH");
		displayNextLCDString(display1);
		displayLCDPos(1,0);
		string display2;
		sprintf(display2, "  PITCH:  %4f  ", pitch);
		displayNextLCDString(display2);
	}
}

task playr () {
	clearLCDLine(0);
	clearLCDLine(1);
	while (true) {
		bLCDBacklight = true;									// Turn on LCD Backlight
		displayLCDPos(0,0);
		string display1;
		sprintf(display1, "CURRENT RECORD  ");
		displayNextLCDString(display1);
		displayLCDPos(1,0);
		string display2;
		sprintf(display2, "RECORD : %2d      ", curData);
		displayNextLCDString(display2);
	}
}

string fader = "rising";
task strobe() {
	while (true) {
		if (fader == "rising") {
			if (motor[flashlight] < 127) {
				motor[flashlight] = motor[flashlight] + 1;
				wait1Msec(60000/(spm*254));
			} else {
				fader = "fading";
			}
		}	else {
			if (motor[flashlight] > 0) {
				motor[flashlight] = motor[flashlight] - 1;
				wait1Msec(60000/(spm*254));
			} else {
				fader = "rising";
			}
		}
	}
}

void tank() {
	motor[FL] = vexRT[Ch3];
	motor[BL] = vexRT[Ch3];
	motor[FR] = vexRT[Ch2];
	motor[BR] = vexRT[Ch2];
}

void tankMotion() {
	if (abs(vexRT[AccelX]) > abs(vexRT[AccelY])) {
		motor[BR] = (-(vexRT[AccelX])) / 2;
		motor[FR] = (-(vexRT[AccelX])) / 2;
		motor[BL] = (vexRT[AccelX]) / 2;
		motor[FL] = (vexRT[AccelX]) / 2;
		} else if (abs(vexRT[AccelY]) >= abs(vexRT[AccelX])) {
		motor[BR] = (-(vexRT[AccelY]));
		motor[FR] = (-(vexRT[AccelY]));
		motor[BL] = (-(vexRT[AccelY]));
		motor[FL] = (-(vexRT[AccelY]));
	}
}

int X2 = 0, Y1 = 0, X1 = 0, threshold = 15;
void tankMecanum() {
	//Create "deadzone" for Y1/Ch3
	if (abs(vexRT[Ch3]) > threshold) {
		Y1 = vexRT[Ch3];
		} else {
		Y1 = 0;
	}
	//Create "deadzone" for X1/Ch4
	if (abs(vexRT[Ch4]) > threshold) {
		X1 = vexRT[Ch4];
		} else {
		X1 = 0;
	}
	//Create "deadzone" for X2/Ch1
	if (abs(vexRT[Ch1]) > threshold) {
		X2 = vexRT[Ch1];
		} else {
		X2 = 0;
	}
	//Remote Control Commands
	motor[FR] = Y1 - X2 - X1;
	motor[BR] =  Y1 - X2 + X1;
	motor[FL] = Y1 + X2 + X1;
	motor[BL] =  Y1 + X2 - X1;
}

void tankMotionMecanum() {
	if (abs(vexRT[AccelY]) > threshold) {
		Y1 = -(vexRT[AccelY]);
		} else {
		Y1 = 0;
	}
	//Create "deadzone" for X1/Ch4
	if ((abs(vexRT[AccelX]) > threshold) && (vexRT[Btn5D] == 0)) {
		X1 = (vexRT[AccelX]);
		} else {
		X1 = 0;
	}
	//Create "deadzone" for X2/Ch1
	if ((abs(vexRT[AccelX]) > threshold) && (vexRT[Btn5D] == 1)) {
		X2 = (vexRT[AccelX])/2;
		} else {
		X2 = 0;
	}
	//Remote Control Commands
	motor[FR] = Y1 - X2 - X1;
	motor[BR] =  Y1 - X2 + X1;
	motor[FL] = Y1 + X2 + X1;
	motor[BL] =  Y1 + X2 - X1;
}

string playMode;

task playback() {
	clearLCDLine(0);
	clearLCDLine(1);
	count = 1;
	curData = rData;
	startTask(playr);
	while (true) {
		if (nLCDButtons == 2 || playMode == "play") {
			if (rec[(count)][(curData)] != 0) {
				playImmediateTone(rec[(count)][(curData)], 50);  // play tone according to sensor readings
				wait1Msec((60000/recBpm[(count)][(curData)]));
				count = count + 1;
			}	else {
				count = 1;
			}
			playMode = "play";
		}
		if (nLCDButtons == 7) {
			playMode = "stop";
		}
		if (nLCDButtons == 1 && curData > 1) {
			curData = curData - 1;
			count = 1;
			wait1Msec(CHANGE);
		}
		if (nLCDButtons == 4 && curData < rData) {
			curData = curData + 1;
			count = 1;
			wait1Msec(CHANGE);
		}
	}
}

void record()
{
	if (vexRT[Btn8U] == 1) {
		if (recordS == "ready") {
			recordS = "start";
			rData = rData + 1;
			mode = "alert";
			stopTask(bpmConfig);
			stopTask(spmConfig);
			stopTask(pitchConfig);
			stopTask(debug);
			d1 = "RECORDING       ";
			d2 = "STARTED         ";
			message();
			wait1Msec(1000);
			mode = prevMode;
			//for (int i = 0; i < ARRAYSIZE(rec); i++) {
			//	rec[i] = 0;
			//	recBpm[i] = 0;
			//}
		}	else if (recordS == "startReady") {
			recordS = "finish";
			stopTask(music);
			mode = "alert";
			stopTask(bpmConfig);
			stopTask(spmConfig);
			stopTask(pitchConfig);
			stopTask(debug);
			startTask(playback);
		} else if (recordS == "quit") {
			recordS = "quitReady";
			startTask(music);
			stopTask(playback);
			stopTask(playr);
			mode = prevMode;
		}
	}	else {
		if (recordS == "start") {
			recordS = "startReady";
		}	else if (recordS == "finish") {
			recordS = "quit";
		} else if (recordS == "quitReady") {
			recordS = "ready";
		}
	}
}

task main()
{
	while (true) {
		if (power == "on") {
			record();
			tank();
			if (mode == "alert") {
			}
			else if (mode == "debug") {
				stopTask(bpmConfig);
				stopTask(spmConfig);
				stopTask(pitchConfig);
				startTask(debug);
				mode = "";
				prevMode = "debug";
				wait1Msec(1000);
			}
			else if (nLCDButtons == 1 || mode == "bpm") {
				mode = "bpm";
				prevMode = "bpm";
				stopTask(debug);
				startTask(bpmConfig);
				wait1Msec(1000);
				while (mode == "bpm") {
					wait1Msec(CHANGE);
					if (nLCDButtons == 1) {
						if (bpm > 1) {
							bpm = bpm - 1;
						}
					}
					else if (nLCDButtons == 4) {
						bpm = bpm + 1;
					}
					else if (nLCDButtons == 2) {
						mode = "debug";
						prevMode = "debug";
					}
				}
			}
			else if (nLCDButtons == 2 || mode == "spm") {
				mode = "spm";
				prevMode = "spm";
				stopTask(debug);
				startTask(spmConfig);
				wait1Msec(1000);
				while (mode == "spm") {
					wait1Msec(CHANGE);
					if (nLCDButtons == 1) {
						if (spm > 1) {
							spm = spm - 1;
						}
					}
					else if (nLCDButtons == 4) {
						spm = spm + 1;
					}
					else if (nLCDButtons == 2) {
						mode = "debug";
						prevMode = "debug";
					}
				}
			}
			else if (nLCDButtons == 4 || mode == "pitch") {
				mode = "pitch";
				prevMode = "pitch";
				stopTask(debug);
				startTask(pitchConfig);
				wait1Msec(1000);
				while (mode == "pitch") {
					wait1Msec(CHANGE);
					if (nLCDButtons == 1) {
						if (pitch > 0.01) {
							pitch = pitch - 0.01;
						}
					}
					else if (nLCDButtons == 4) {
						pitch = pitch + 0.01;
					}
					else if (nLCDButtons == 2) {
						mode = "debug";
						prevMode = "debug";
					}
				}
			}
			if (SensorValue[line] < 2500) {
				stopTask(debug);
				stopTask(strobe);
				stopTask(music);
				stopTask(playback);
				stopTask(bpmConfig);
				stopTask(spmConfig);
				stopTask(pitchConfig);
				motor[flashlight] = 0;
				bLCDBacklight = false;
				clearLCDLine(0);
				clearLCDLine(1);
				power = "off";
				wait1Msec(1000);
			}
		}
		else if (power == "off") {
			if (SensorValue[line] < 2500) {
				power = "on";
				wait1Msec(1000);
				startTask(strobe);
				startTask(music);
				mode = "debug";
				prevMode = "debug";
			}
		}
	}
}
