// KeyPad must be installed
#include <Keypad.h>
#include <Key.h>

// Define the 
const byte rows = 4;
const byte columns = 4;
const char keys[rows][columns] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Define the pins used by the keypad
const byte row_pins[rows] = {5, 4, 3, 2};
const byte column_pins[columns] = {9, 8, 7, 6};

// Initialize the Keypad
Keypad keypad01 = Keypad(makeKeymap(keys), row_pins, column_pins, rows, columns);

// Valid pincode including the EOF character at the end
const char pincode[5] = "1234";

char usercode[5];
int index = 0;

void setup() {
  // Initialize and Set the serial port speed
  Serial.begin(9600);
}

void loop() {
  // Get the key value presed
  char key = keypad01.getKey();

  if(key) {
    usercode[index] = key;
    index++;
    Serial.print(key);
  }

  if(index == 6) {
    if(!strcmp(usercode, pincode)) {
      Serial.println(" Correcta");
    } else {
      Serial.println(" Incorrecta");
    }
    index = 0;
  }

}
