#include <Servo.h>

Servo servo01;

const int servo_pin = 3;
const int pot_pin = 0;

const int min_pulse = 1000; // microsecods
const int max_pulse = 2000; // microsecods


void setup() {
  // defining the pulse limits for the servo
  servo01.attach(servo_pin, min_pulse, max_pulse);

  // The analog input do not require initialization

  // set the initial servo position 
  servo01.write(0);
  delay(500);
}

void loop() {
  // The analog input has a resolution from 0 to 1023
  // while the servo is between 0 and 180 degrees
  int position = map(analogRead(pot_pin), 0, 1023, 0, 180);
  servo01.write(position);
  delay(50);
}
