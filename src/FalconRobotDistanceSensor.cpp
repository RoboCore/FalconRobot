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

FalconRobotDistanceSensor::FalconRobotDistanceSensor(int pinTrig, int pinEcho) {
  _pinTrig = pinTrig;
  _pinEcho = pinEcho;
  pinMode(_pinTrig, OUTPUT);
  pinMode(_pinEcho, INPUT);
}

int FalconRobotDistanceSensor::timing() {
  digitalWrite(_pinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(_pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(_pinTrig, LOW);
  return pulseIn(_pinEcho, HIGH); // duration
}

int FalconRobotDistanceSensor::read(int und) {
  if (und)
    return timing() / CM_DIVISOR / 2;  //distance in CM
  else
    return timing() / INC_DIVISOR / 2; //distance in INC
}

int FalconRobotDistanceSensor::read() {
  /*
   * If the unit of measure is not passed as a parameter,
   * by default, it will return the distance in centimeters.
   * To change the default, replace CM by INC.
   */
  return read(CM);
}
