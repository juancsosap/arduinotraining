const int switch_pin = 2;
const int led_pin = 3;

int led_state = LOW;

void setup() {
    // Define the switch pin as input (Switch)
    pinMode(switch_pin, INPUT);
    // Define the led pin as output (LED)
    pinMode(led_pin, OUTPUT);
}

void loop() {
    // Verify the LED state
    if(led_state == LOW) {
        // Verify if the Switch is pressed
        if(digitalRead(switch_pin) == HIGH) {
            // Turn on the LED
            digitalWrite(led_pin, HIGH);
            // Change the LED state variable value
            led_state = HIGH;
        }
    } else {
        // Verify if the Switch is pressed
        if(digitalRead(switch_pin) == HIGH) {
            // Turn off the LED
            digitalWrite(led_pin, LOW);
            // Change the LED state variable value
            led_state = LOW;
        }
    }
}