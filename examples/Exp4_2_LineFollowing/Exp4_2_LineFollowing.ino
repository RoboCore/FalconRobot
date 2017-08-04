/*******************************************************************************
* Exp4_2_LineFollowing -- Falcon Robot Experiment 4.2
*
* This code reads the two line following sensors on A2 and A3
* and prints them out to the Serial Monitor. Upload this example to your
* Falcon Robot and open up the Serial Monitor by clicking the magnifying glass
* in the upper-right hand corner.
*
* This is a real simple example of a line following algorithm. It has
* a lot of room for improvement, but works fairly well for a curved track.
* It does not handle right angles reliably -- maybe you can come up with a
* better solution?
*
* Hardware setup:
* The Line Sensors must be connected to pins A2 and A3 (left and right sensor,
* respectively). The motors must be connected, and the board must be receiving
* power from the battery pack.
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
// initialize a sensor object on A2 and A3
FalconRobotLineSensor left(A2);
FalconRobotLineSensor right(A3);

int leftValue;  // variable to store the left sensor value
int rightValue;  // variable to store the right sensor value

// constants that are used in the code. LINETHRESHOLD is the level to detect
// if the sensor is on the line or not. If the sensor value is greater than this
// the sensor is above a DARK line.
//
// SPEED sets the nominal speed

#define LINETHRESHOLD 700
#define SPEED 50  // Set to any number from 0 - 100.

FalconRobotMotors motors(5, 7, 6, 8);
int leftSpeed;   // variable used to store the leftMotor speed
int rightSpeed;  // variable used to store the rightMotor speed


void setup() {
  Serial.begin(9600);
  Serial.println("Welcome to experiment 5.2 - Line Following");
  delay(2000);
  Serial.println("Line Sensor Readings: ");
  delay(500);
}

void loop() {

  // Read the sensors
  leftValue = left.read();
  rightValue = right.read();

  // Print the sensors values
  Serial.print(leftValue);
  Serial.print("\t");  // tab character
  Serial.print(rightValue);
  Serial.println();   // new line

  // if the both sensors are on the line, drive forward left and right at the same speed
  if((leftValue > LINETHRESHOLD) && (rightValue > LINETHRESHOLD)) {
  	leftSpeed = SPEED;
  	rightSpeed = SPEED;
  }

  // if the line only is under the right sensor, adjust relative speeds to turn to the right
  else if(rightValue > LINETHRESHOLD) {
  	leftSpeed = SPEED + 40;
  	rightSpeed = SPEED - 40;
  }

  // if the line only is under the left sensor, adjust relative speeds to turn to the left
  else if(leftValue > LINETHRESHOLD) {
  	leftSpeed = SPEED - 40;
  	rightSpeed = SPEED + 40;
  }

  // run motors given the control speeds above
  motors.leftDrive(leftSpeed, FORWARD);
  motors.rightDrive(rightSpeed, FORWARD);

  delay(0);  // add a delay to decrease sensitivity.
}
