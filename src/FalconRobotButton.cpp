/*****************************************************************************
RoboCore Falcon Robot Button Functions (v1.0 - 30/06/2017)
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
This code is based on the SparkFun_RedBot_Arduino_Library by
SparkFun Electronics, Inc. (I shall retribute with a cold beverage when we meet)
------------------------------------------------------------------------------
30 Jun 2017 - MarceloFariaz, RoboCore

Code developed in Arduino 1.6.5, on an RoboCore Falcon Robot rev1
*****************************************************************************/

#include "FalconRobot.h"
#include <Arduino.h>

FalconRobotButton::FalconRobotButton(int pin) {
  // Sets the "default" state of the button to be HIGH.
  _pin = pin;
  pinMode(_pin, INPUT_PULLUP);
}

boolean FalconRobotButton::read() {
  return(!digitalRead(_pin));
}
