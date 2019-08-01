const int led_pin = 3;
const int eco_pin = 9;
const int trig_pin = 10;

const int soundspeed = 343; // meters/seconds
const unsigned long threashold = 1000000; // 1 meters

void setup() {
  // Define the pin mode as output or input
  pinMode(led_pin, OUTPUT);
  pinMode(eco_pin, INPUT);
  pinMode(trig_pin, OUTPUT);
}

void loop() {
  // send a 1 msg pulse signal to the trigger pin
  digitalWrite(trig_pin, HIGH);
  delay(1);
  digitalWrite(trig_pin, LOW);

  // return the duration until a pulse is received
  // in microseconds, then must be converted to seconds
  unsigned long duration = pulseIn(eco_pin, LOW);

  // convert the duration to distance in micrometers, 
  // based on sound speed and considering round trip
  unsigned long distance = (duration/2)*soundspeed;

  if(distance <= threashold) {
    digitalWrite(led_pin, HIGH);  
  } else {
    digitalWrite(led_pin, LOW);
  }
}
