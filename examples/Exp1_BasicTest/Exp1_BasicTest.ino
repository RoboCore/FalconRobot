/*******************************************************************************
* Exp1_BasicTest - Falcon Robot Experiment 1
*
* Time to make sure the electronics work! To test everything out, we're
* going to blink the LED on the board.
*
* This sketch was written by RoboCore, with lots of help from the Arduino
* community(especially from Sparkfun). This code is completely free for any use.
*
* Visit https://www.robocore.net/tutoriais/kit-iniciante-robotica-introducao
* for Falcon Robot Kit Information
*
* 20 Jul 2017 MarceloFariaz
*******************************************************************************/

// setup() function runs once at the very beginning.
void setup() {
  pinMode(13, OUTPUT); // The board has an LED connected to pin 13.
  // Pins are all generic, so we have to first configure it
  // as an OUTPUT using this command.
}

// loop() function repeats over and over... forever!
void loop() {
  // Blink sequence
  digitalWrite(13, HIGH); // Turns LED ON - HIGH puts 5V on pin 13.
  delay(250);             // delay(250) "pauses" the program for 250 milliseconds
  digitalWrite(13, LOW);  // Turns LED OFF - LOW puts 0V on pin 13.
  delay(250);             // delay(250) "pauses" the program for 250 milliseconds
  // The total delay period is 500 ms, or 0.5 second.
}
