/*******************************************************************************
* Exp3_Turning - FalconRobot Experiment 3
*
* Explore turning with the FalconRobot by controlling the Right and Left motors
* separately.
*
* Hardware setup:
* The motors must be connected, and the board must be receiving power from the
* battery. The motor switch must also be switched to ON.
*
* This sketch was written by RoboCore, with lots of help from the Arduino
* community(especially from Sparkfun). This code is completely free for any use.
*
* Visit https://www.robocore.net/tutoriais/kit-iniciante-robotica-introducao
* for Falcon Robot Kit Information
*
* 20 Jul 2017 MarceloFariaz
*******************************************************************************/
#include <FalconRobot.h>  // This line "includes" the library into your sketch.

FalconRobotMotors motors; // Instantiate the motor control object.

void setup() {
  // drive forward -- instead of using motors.drive(); Here is another way.
  motors.leftDrive(75, FORWARD); // Turn on left motor counter clockwise (motorPower = 75%)
  motors.rightDrive(75, FORWARD); // Turn on right motor clockwise (motorPower = 75%)
  delay(1000);       // for 1000 ms.
  motors.stop();    // stop() motors
  delay(250);        // for 250 ms.

  // pivot -- spinning both motors CW causes the FalconRobot to turn to the left
  motors.leftDrive(50, BACKWARD);  // Turn CW at motorPower of 50%
  motors.rightDrive(50, FORWARD); // Turn CW at motorPower of 50%
  delay(250);        // for 250 ms.
  motors.stop();    // stop() motors
  delay(250);        // for 250 ms.

  // drive forward -- instead of using motors.drive(); Here is another way.
  motors.leftDrive(75, FORWARD); // Turn on left motor counter clockwise (motorPower = 75%)
  motors.rightDrive(75, FORWARD); // Turn on right motor clockwise (motorPower = 75%)
  delay(1000);       // for 1000 ms.
  motors.stop();     // stop() motors
  delay(250);        // for 250 ms.
}

void loop() {
  // Figure 8 pattern -- Turn Right, Turn Left, Repeat
  // motors.leftDrive(100, FORWARD);  // Left motor CCW at 100%
  // motors.rightDrive(25, FORWARD);   // Right motor CW at 40%
  // delay(2000);
  // motors.leftDrive(25, FORWARD);    // Left motor CCW at 40%
  // motors.rightDrive(100, FORWARD);   // Right motor CW at 100%
  // delay(2000);
}
