const int led_pin = 3;
const int pot_pin = 0;

void setup() {
  // Define the led pin as output (LED)
  pinMode(led_pin, OUTPUT);

  // The analog input do not require initialization
}

void loop() {
  // The analog input has a resolution from 0 to 1023
  // while the PWM has a resolution from 0 to 255
  // then the relation is 1:4
  int intensity = analogRead(pot_pin)/4;
  analogWrite(led_pin, intensity);
}
