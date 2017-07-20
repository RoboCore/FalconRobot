/*******************************************************************************
* Exp7_FollowingDiverting - FalconRobot Experiment 7
*
* Now that we already know how to use the line sensors to follow the line and
* the distance sensor to divert obstacles, what about doing the two together?
*
* Hardware setup:
* The Line Sensors must be connected to pins A2 and A3 (left and right sensor,
* respectively). The Distance Sensor must be connected to pins 2 and 3 (Echo and
* Trig, respectively). The motors must be connected, and the board must be
* receiving power from the battery pack.
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

#define LINETHRESHOLD 700
#define SPEED 50  // Set to any number from 0 - 100.
// initialzes Distance Sensor object on pins 2 and 3

// initialzes Distance Sensor object on pins 2 and 3
FalconRobotDistanceSensor distanceSensor(2, 3);
// DISTANCETHRESHOLD is the level to detect if the obstacle is very close or
// not. If the sensor value is greater than this, the robot needs to deviate.
#define DISTANCETHRESHOLD 15 // cm - Set to any number from 2 - 400.

int distance;  // variable to store the distance value

FalconRobotMotors motors(5, 7, 6, 8);
int leftSpeed;   // variable used to store the leftMotor speed
int rightSpeed;  // variable used to store the rightMotor speed


const int buttonPin = A0; // variable to store the button Pin

void setup() {
  Serial.begin(9600);
  Serial.println("Welcome to experiment 5.2 - Line Following");
  delay(2000);
  Serial.println("Sensors Readings: ");
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
  Serial.println();

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
