/*******************************************************************************
* Exp6_1_DeviatingObstacles - FalconRobot Experiment 6.1
*
* Now let's experiment with the distance sensor. This ultrasonic sensor let you
* detect a collision before it really happens. You can read the exact distance
* from the robot to the obstacle.
*
* This sketch was written by RoboCore, with lots of help from the Arduino
* community(especially from Sparkfun). This code is completely free for any use.
*
* Hardware setup:
* The Distance Sensor must be connected to pins 2 and 3 (Echo and Trig
* respectively). The motors must be connected, and the board must be receiving
* power from the battery pack.
*
* Visit https://www.robocore.net/tutoriais/kit-iniciante-robotica-introducao
* for Falcon Robot Kit Information
*
* 20 Jul 2017 MarceloFariaz
*******************************************************************************/

#include <FalconRobot.h>
FalconRobotMotors motors(5, 7, 6, 8);

// initialzes Distance Sensor object on pins 2 and 3
FalconRobotDistanceSensor distanceSensor(2, 3);
// DISTANCETHRESHOLD is the level to detect if the obstacle is very close or
// not. If the sensor value is greater than this, the robot needs to deviate.
#define DISTANCETHRESHOLD 20 // cm - Set to any number from 2 - 400.

int distance;  // variable to store the distance value

void setup() {
  Serial.begin(9600);
  Serial.println("Welcome to experiment 6.2 - Obstacle Avoidance!");
  delay(2000);
  Serial.println("Distance Sensor Readings: ");
  delay(500);
}

void loop() {
  motors.drive(50, FORWARD);

  // by default, returns the distance in cm. Try read(INCH) to get inches
  distance = distanceSensor.read();

  // Print the sensor distance value
  Serial.print(distance);
  Serial.println(); // new line

  if (distance <= DISTANCETHRESHOLD) { // The obstacle is really very close
    reverse();    // backs up
    turnRight();  // Can be replaced by  turnLeft();
  }

  delay(60);  // delay to wait sensor reading, suggested by datasheet
}

// reverse() function -- backs up at full power
void reverse() {
  motors.stop();
  delay(500);  // short delay to let robot fully stop
  motors.drive(50, BACKWARD);
  delay(500);
  motors.stop();
  delay(500);  // short delay to let robot fully stop
}

// turnRight() function -- turns FalconRobot to the Right
void turnRight() {
  motors.leftDrive(50, FORWARD);  // spin CCW
  motors.rightDrive(50, BACKWARD); // spin CCW
  delay(250);
  motors.stop();
  delay(250);  // short delay to let robot fully stop
}

// turnLeft() function -- turns FalconRobot to the Left
void turnLeft() {
  motors.leftDrive(50, BACKWARD);  // spin CW
  motors.rightDrive(50, FORWARD); // spin CW
  delay(250);
  motors.stop();
  delay(250);  // short delay to let robot fully stop
}
