/*****************************************************************************
RoboCore Falcon Robot Line Sensor Functions (v1.0 - 30/06/2017)
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

FalconRobotLineSensor::FalconRobotLineSensor(int pin) {
  _pin = pin;
  _BGLevel = -1;
  _lineLevel = -1;
}

int FalconRobotLineSensor::read() {
  return analogRead(_pin);
}

// If both the background and detection levels for this sensor have been
//  set, returns true.
boolean FalconRobotLineSensor::calStatus() {
  if (_BGLevel != -1 && _lineLevel != -1) return true;
  else                                      return false;
}

// An attempt at a decent single-call, quick return line detection function.
boolean FalconRobotLineSensor::check() {
  // Collect a sample.
  int level = analogRead(_pin);

  // Are we looking for something that is darker than our normal level (say,
  //  a table edge, or a black stripe on a white surface) or something that
  //  is brighter than our normal level (say, a piece of copper tape? on a
  //  dark floor)?
  // Remember, the darker the surface, the higher the value returned.
  if (_BGLevel < _lineLevel) {  // Light-on-dark situation
    // For a light-on-dark detection, we're looking to see if the level is
    //  higher than _BGLevel. Our threshold will be a rise above the BGLevel
      //  of 1/4 the difference between background and detect levels.
    int threshold = (_lineLevel - _BGLevel)>>2;
    if (level-threshold > _BGLevel) return true;
    else                            return false;
  }
  else {  // Dark-on-light situation
    // For a dark-on-light detection, we'll do exactly the opposite: check to
    //  see if the level is lower than _BGLevel by at least 1/4 the difference
    //  between the levels.
    int threshold = (_BGLevel - _lineLevel)>>2;
    if (level+threshold < _BGLevel) return true;
    else                            return false;
  }
}

// setBGLevel() is used to calibrate the level that we expect to see when we
//  aren't seeing something interesting.
int FalconRobotLineSensor::setBGLevel() {
  _BGLevel = analogRead(_pin);

  return _BGLevel;
}

// setDetectLevel() works exactly the same as setBGLevel(), but with different
//  variables.
int FalconRobotLineSensor::setDetectLevel() {
  _lineLevel = analogRead(_pin);

  return _lineLevel;
}
