/*******************************************************************************
* Exp4_1_LineFollowing -- FalconRobot Experiment 4.1
*
* This code reads the two line following sensors on A2 and A3
* and prints them out to the Serial Monitor. Upload this example to your
* FalconRobot and open up the Serial Monitor by clicking the magnifying glass
* in the upper-right hand corner.
*
* Hardware setup:
* The Line Sensors must be connected to pins A2 and A3 (left and right sensor,
* respectively).
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
FalconRobotLineSensor lineSensor1 = FalconRobotLineSensor(A2);
FalconRobotLineSensor lineSensor2 = FalconRobotLineSensor(A3);

void setup() {
  Serial.begin(9600); // Setup the Serial to a speed of 9600bps
  Serial.println("Welcome to experiment 5!");
}

void loop() {
  // Print the sensors values
  Serial.print("Line Sensor Readings: ");
  Serial.print(lineSensor1.read());
  Serial.print("\t"); // tab character
  Serial.print(lineSensor2.read());
  Serial.println(); // new line
  delay(100);
}
