void setup() {
    // Define the pin 2 as input (Switch)
    pinMode(2, INPUT);
    // Define the pin 3 as output (LED)
    pinMode(3, OUTPUT);
}

void loop() {
    // Verify if the Switch is pressed
    if(digitalRead(2) == HIGH) {
        // Turn on the LED
        digitalWrite(3, HIGH);
    } else {
        // Turn off the LED
        digitalWrite(3, LOW);
    }
}