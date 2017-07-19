/***********************************************************************
 * Exp1_DriveForward - Falcon Robot Experiment 2
 *
 * Drive forward and stop.
 *
 * Hardware setup:
 * The motors must be connected, and the board must be receiving power
 * from the battery. The motor switch must also be switched to ON.
 *
 * 19 Jul 2017 MarceloFariaz
 *
 ***********************************************************************/

#include <FalconRobot.h> // This line "includes" the Falcon Robot library
//into your sketch. Provides special objects, methods, and functions.

FalconRobotMotors motors(5, 7, 6, 8); // Instantiate the motor control object. This
//only needs to be done once.

void setup() {
  motors.drive(100, FORWARD);   // Turn on Left and right motors at full speed forward.
  delay(1000);         // Waits for 1 seconds
  motors.stop();       // Stops both motors
}

void loop() {
  // Nothing here. We'll get to this in the next experiment.
}
