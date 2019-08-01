const int relay_pin = 3;

void setup() {
  // Define the pin mode as output or input
  pinMode(relay_pin, OUTPUT);
}

void loop() {
  // Set the pin to HIGH
  digitalWrite(relay_pin, HIGH);
  // Wait 5 seconds
  delay(5000);
  // Set the pin to LOW
  digitalWrite(relay_pin, LOW);
  // Wait 5 seconds
  delay(5000);
}
