const int led_pin = 3;

int intensity = 0;

void setup() {
  // Define the led pin as output (LED)
  pinMode(led_pin, OUTPUT);
}

void loop() {
  // increment the pulse weigth (PWM) from 0 to the maximum (255)
  while(intensity < 255) {
    intensity++;
    // generate a PWM signal with high frecuency and the specified
    // intensity value as a factor between the HIGH and LOW levels
    // of each period
    analogWrite(led_pin, intensity);
    delay(15);
  }
  
  // decrement the pulse weigth (PWM) from 255 to the minimum (0)
  while(intensity > 0) {
    intensity--;
    // generate a PWM signal with high frecuency and the specified
    // intensity value as a factor between the HIGH and LOW levels
    // of each period
    analogWrite(led_pin, intensity);
    delay(15);
  }
}
