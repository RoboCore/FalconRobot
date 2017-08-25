/*****************************************************************************
RoboCore Falcon Robot Ultrasonic Distance Sensor Functions (v1.0 - 30/06/2017)
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
This code is based on the Ultrasonic Arduino Library by ErickSimoes.
(I shall retribute with a cold beverage when we meet)
------------------------------------------------------------------------------
30 Jun 2017 - MarceloFariaz, RoboCore

Code developed in Arduino 1.6.5, on an RoboCore Falcon Robot rev1
*****************************************************************************/

#include "FalconRobot.h"
#include <Arduino.h>

#define CM_DIVISOR  28
#define INC_DIVISOR 71

FalconRobotDistanceSensor::FalconRobotDistanceSensor(int pinEcho, int pinTrig, unsigned long timeout) {
  _pinEcho = pinEcho;
  _pinTrig = pinTrig;
  pinMode(_pinEcho, INPUT);
  pinMode(_pinTrig, OUTPUT);
  _timeout = timeout;
}

unsigned long FalconRobotDistanceSensor::timing() {
  digitalWrite(_pinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(_pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(_pinTrig, LOW);
  return pulseIn(_pinEcho, HIGH, _timeout); // duration
}

unsigned int FalconRobotDistanceSensor::read(int unit) {
  // return the distance in the unit
  return timing() / unit / 2;
}

unsigned int FalconRobotDistanceSensor::read() {
  /*
   * If the unit of measure is not passed as a parameter,
   * by default, it will return the distance in centimeters.
   * To change the default, replace CM by INCH.
   */
  return read(CM);
}
