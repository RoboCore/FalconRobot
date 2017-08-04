/*******************************************************************************
* Exp6_SerialDrive - FalconRobot Experiment 6
*
* The first step to controlling the Falcon Robot remotely is to first drive it
* from the Serial Monitor in a tethered setup.
*
* Hardware setup:
* After uploading this sketch, keep the Falcon Robot tethered to your computer
* with the USB cable. Open up the Seral Monitor to send commands to the Falcon
* Robot to drive.
* Optionally, you can add a Bluetooth Module (HC05, HC06 or HC08, for example),
* and control your Falcon Robot by a smartphone.
*
* This sketch was written by RoboCore, with lots of help from the Arduino
* community(especially from Sparkfun). This code is completely free for any use.
*
* Visit https://www.robocore.net/tutoriais/kit-iniciante-robotica-introducao
* for Falcon Robot Kit Information
*
* 20 Jul 2017 MarceloFariaz
*******************************************************************************/

#include <FalconRobot.h>
FalconRobotMotors motors(5, 7, 6, 8);
int leftPower;  // variable for setting the drive power
int rightPower; // variable for setting the drive power
int leftDirection; // variable for setting the direction
int rightDirection; // variable for setting the direction
int data;  // variable for holding incoming data from PC to Arduino

void setup(void) {
  Serial.begin(9600);
  Serial.print("Enter in left and right motor power values and click [Send].");
  Serial.print("Separate values with a space or non-numeric character.");
  Serial.println();
  Serial.print("Positive values spin the motor CW, and negative values spin the motor CCW.");
}

void loop(void) {
  // if there is data coming in on the Serial monitor, do something with it.
  if(Serial.available() > 0) {
    leftPower = Serial.parseInt();  // read in the next numeric value
    leftPower = constrain(leftPower, -100, 100);  // constrain the data to -100 to +100

    rightPower = Serial.parseInt();   // read in the next numeric value
    rightPower = constrain(rightPower, -100, 100);  // constrain the data to -100 to +100

    // set the direction by the signal of the speed
    if (leftPower < 0) {
      leftPower = - leftPower;
      leftDirection = BACKWARD;
    }
    else {
      leftDirection = FORWARD;
    }

    // set the direction by the signal of the speed
    if (rightPower < 0) {
      rightPower = - rightPower;
      rightDirection = BACKWARD;
    }
    else {
      rightDirection = FORWARD;
    }

    // set motors
    motors.leftDrive(leftPower, leftDirection);
    motors.rightDrive(rightPower, rightDirection);

  }
}
