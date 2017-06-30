/*****************************************************************************
RoboCore Falcon Robot Motor Control Functions (v1.0 - 30/06/2017)
Copyright 2015 RoboCore (MarceloFariaz) ( http://www.RoboCore.net )
------------------------------------------------------------------------------
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
------------------------------------------------------------------------------
This code is based on the SparkFun_FalconRobot_Arduino_Library by
SparkFun Electronics, Inc. (I shall retribute with a cold beverage when we meet)
------------------------------------------------------------------------------
30 Jun 2017 - MarceloFariaz, RoboCore

Code developed in Arduino 1.6.5, on an RoboCore Falcon Robot rev1
*****************************************************************************/

#include "FalconRobot.h"
#include <Arduino.h>

// Constructor.
FalconRobotMotors::FalconRobotMotors(int pinMLPWM, int pinMLDIR, int pinMRPWM, int pinMRDIR) {
  // DIR defines the direction (forward, reverse); PWM defines the speed.
  _pinMLPWM = pinMLPWM;
  _pinMLDIR = pinMLDIR;
  _pinMRPWM = pinMRPWM;
  _pinMRDIR = pinMRDIR;

  pinMode(_pinMLPWM, OUTPUT);
  pinMode(_pinMLDIR, OUTPUT);
  pinMode(_pinMRPWM, OUTPUT);
  pinMode(_pinMRDIR, OUTPUT);
}

// Constructor. Mostly for pin setup;
FalconRobotMotors::FalconRobotMotors() {
    // DIR defines the direction (forward, reverse); PWM defines the speed.
  _pinMLPWM = PIN_ML_PWM;
  _pinMLDIR = PIN_ML_DIR;
  _pinMRPWM = PIN_MR_PWM;
  _pinMRDIR = PIN_MR_DIR;

  pinMode(_pinMLPWM, OUTPUT);
  pinMode(_pinMLDIR, OUTPUT);
  pinMode(_pinMRPWM, OUTPUT);
  pinMode(_pinMRDIR, OUTPUT);
}



// Basically the same as drive(), but omitting the right motor.
void FalconRobotMotors::rightDrive(int speed, boolean direction) {
  speed = speed > 100 ? 100 : speed < 0 ? 0 : speed;
  speed = map(speed, 0, 100, 0, 255);
  digitalWrite(_pinMRDIR, direction);
  analogWrite(_pinMRPWM, speed);
}

void FalconRobotMotors::rightDrive(int speed, boolean direction, int duration) {
  rightDrive(speed, direction);
  delay(duration);
  rightStop();
}

// Basically the same as drive, but omitting the left motor.
void FalconRobotMotors::leftDrive(int speed, boolean direction) {
  speed = speed > 100 ? 100 : speed < 0 ? 0 : speed;
  speed = map(speed, 0, 100, 0, 255);
  digitalWrite(_pinMLDIR, direction);
  analogWrite(_pinMLPWM, speed);
}

void FalconRobotMotors::leftDrive(int speed, boolean direction, int duration) {
  leftDrive(speed, direction);
  delay(duration);
  leftStop();
}

// Stop funcions for the each motor
void FalconRobotMotors::leftStop() {
  analogWrite(_pinMLPWM, 0);
}

void FalconRobotMotors::rightStop() {
  analogWrite(_pinMRPWM, 0);
}

// Stop funcion for the both motors
void FalconRobotMotors::stop() {
  leftStop();
  rightStop();
}

// drive() starts both motors. It figures out whether the motors should go
//  forward or revers, then calls the appropriate individual functions.
void FalconRobotMotors::drive(int speed, boolean direction) {
  leftDrive(speed, direction);
  rightDrive(speed, direction);
}

// this variant of drive() integrates a delay duration to allow for single
// commmand instruction.
void FalconRobotMotors::drive(int speed, boolean direction, int duration) {
  drive(speed, direction);
  delay(duration);
  stop();
}

// pivot() is very much like drive(), except the motors are driven in opposite
//  directions, so as to pivot the motor on it's central axis.
void FalconRobotMotors::pivot(int speed, boolean direction) {
  leftDrive(speed, direction);
  rightDrive(speed, !direction);
}

void FalconRobotMotors::pivot(int speed, boolean direction, int duration) {
  pivot(speed, direction);
  delay(duration);
  stop();
}
