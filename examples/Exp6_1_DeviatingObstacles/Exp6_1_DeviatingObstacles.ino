/*******************************************************************************
* Exp6_1_DeviatingObstacles - FalconRobot Experiment 6.1
*
* Now let's experiment with the distance sensor. This code reads the distance
* sensor and prints them out to the Serial Monitor. Upload this example to your
* FalconRobot and open up the Serial Monitor by clicking the magnifying glass
* in the upper-right hand corner.
*
* This sketch was written by RoboCore, with lots of help from the Arduino
* community(especially from Sparkfun). This code is completely free for any use.
*
* Hardware setup:
* The Distance Sensor must be connected to pins 2 and 3 (Echo and Trig
* respectively).
*
* Visit https://www.robocore.net/tutoriais/kit-iniciante-robotica-introducao
* for Falcon Robot Kit Information
*
* 20 Jul 2017 MarceloFariaz
*******************************************************************************/

#include <FalconRobot.h>

// initialzes Distance Sensor object on pins 2 and 3
FalconRobotDistanceSensor distanceSensor(2, 3);  // (echo, trig)


void setup() {
  Serial.begin(9600); // Setup the Serial to a speed of 9600bps
  Serial.println("Welcome to experiment 6!");
}

void loop() {
  // Print the sensor distance value
  Serial.print("Distance Sensor Readings: ");
  Serial.print(distanceSensor.read());
  Serial.println(); // new line
  delay(100);
}
