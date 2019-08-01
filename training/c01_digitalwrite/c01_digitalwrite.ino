void setup(){
    // Define the pin 13 as output (Buildin LED)
    pinMode(13, OUTPUT);
}

void loop(){
    // Set the pin 13 with a High Voltage (1)
    digitalWrite(13, HIGH);
    // Wait 1 second
    delay(1000);
    // Set the pin 13 with a Low Voltage (0)
    digitalWrite(13, LOW);
    // Wait 1 second
    delay(1000);
}