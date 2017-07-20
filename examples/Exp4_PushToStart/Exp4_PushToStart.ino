/*******************************************************************************
* Exp4_PushToStart - Falcon Robot Experiment 4
*
* Push the button (A0) to start running!
*
* Hardware setup:
* This code requires only the most basic setup: the motors must be connected,
* and the board must be receiving power from the battery pack.
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
FalconRobotMotors motors(5, 7, 6, 8);

// Create a couple of constants for our pins.
const int ledPin = 13;
const int buttonPin = A0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // configures the button as an INPUT
  // INPUT_PULLUP defaults it to HIGH.
  pinMode(ledPin, OUTPUT);  // configures the ledPin as an OUTPUT
}

void loop() {
  if ( digitalRead(buttonPin) == LOW ) { // if the button is pushed (LOW)
    digitalWrite(ledPin, HIGH); // Turns LED ON - HIGH puts 5V on pin 13.

    motors.drive(100, FORWARD);     // Start the motors.
    delay(1000);   // delay for 1000 ms (1 second)

    digitalWrite(ledPin, LOW);  // Turns LED OFF - LOW puts 0V on pin 13.
    motors.stop();          // stop() or stop the motors.
  }
  else  { // otherwise, do this.

  }
}
