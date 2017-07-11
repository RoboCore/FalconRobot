/*****************************************************************************
RoboCore Falcon Robot Library - Header File (v1.0 - 30/06/2017)
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

#ifndef FalconRobot_h
#define FalconRobot_h

#include <Arduino.h>

// Pins definitions
// Motors
#define PIN_ML_PWM   5
#define PIN_ML_DIR   7
#define PIN_MR_PWM   6
#define PIN_MR_DIR   8
// Buttons
#define PIN_BTN0  A0
#define PIN_BTN1  A1
// Ultrasonic Distance Sensor
#define PIN_ECHO  2
#define PIN_TRIG  3
// Infrared Line Sensor
#define PIN_LS_1  A2
#define PIN_LS_2  A3

#define BACKWARD  0
#define FORWARD 1
#define RIGHT 0
#define LEFT 1

#define CM 1
#define INCH 0

// This class handles motor functionality. I expect one instance of this at the
// start of a piece of FalconRobot code.
class FalconRobotMotors {
  public:
    FalconRobotMotors();  // Constructor. Mainly sets up pins.
    FalconRobotMotors(int pinMLPWM, int pinMLDIR, int pinMRPWM, int pinMRDIR); // Constructor

    void leftStop();  // Stop left motor, as with stop().
    void rightStop(); // Stop right motor, as with stop().

    void stop();  // Stop motors

    void drive(int speed, boolean direction); // Drive in direction given
    void drive(int speed, boolean direction, int duration); // drive(), but with a delay(duration)

    void pivot(int speed, boolean direction); // Pivot more or less in place. Turns motors in
    void pivot(int speed, boolean direction, int duration); // pivot() with a delay(duration)

    void rightDrive(int speed, boolean direction);  // Drive just the right motor
    void rightDrive(int speed, boolean direction, int duration);  // Drive just the right motor; delay(duration);

    void leftDrive(int speed, boolean direction);  // Drive just the left motor
    void leftDrive(int speed, boolean direction, int duration); // Drive just the left motor; delay(duration);

  private:
    int _pinMLPWM;
    int _pinMLDIR;
    int _pinMRPWM;
    int _pinMRDIR;

};

// This is a simple class to handle the button object on the robot. It has only one
// method, read(). This returns a boolean value for whether the button is pressed.
class FalconRobotButton {
  public:
    FalconRobotButton(int pin);  // Constructor
    boolean read();  // Return the button state(Pressed = HIGH / Released = LOW)
  private:
    int _pin;
};

// This is the reflectance sensor used for eg line following and table edge
//  detection. It's pretty crude, but since they're analog sensors, they're
//  kind of hard to work with.
class FalconRobotLineSensor {
  public:
    FalconRobotLineSensor(int pin);  // Configure a pin as a sensor.
    int read();             // Return the current value of the pin.
    boolean check();        // In theory, this will be true if a deviation from
                            //  detectLevel is found; false otherwise.
    int setBGLevel();       // You can calibrate the sensor to detect a deviation
    int setDetectLevel();   //  from detectLevel; these functions allow for that.
    boolean calStatus();    // Have both calibrated levels been set yet?
  private:
    int _pin;
    int _BGLevel;
    int _lineLevel;
};

// This handles the ultrasonic distance sensor.
class FalconRobotDistanceSensor {
  public:
    FalconRobotDistanceSensor(int pinEcho, int pinTrig); // Simple constructor
    int read(int und);
    int read();

  private:
    int _pinEcho;
    int _pinTrig;
    int timing();
};

#endif
