const int switch_pin = 2;
const int led_pin = 3;

int led_state;

void setup() {
    // Define the switch pin as input (Switch)
    pinMode(switch_pin, INPUT);
    // Define the led pin as output (LED)
    pinMode(led_pin, OUTPUT);
}

void loop() {
    // While the Switch is not pressed
    while(digitalRead(switch_pin) == LOW) {}

    // Verify the LED state variable value
    led_state = digitalRead(led_pin);
    digitalWrite(led_pin, !led_state);

    // While the Switch is not pressed
    // It is usefull to protect the code from transitory switch states 
    while(digitalRead(switch_pin) == HIGH) {}
}