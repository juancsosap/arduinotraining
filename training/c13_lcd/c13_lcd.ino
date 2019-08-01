// KeyPad must be installed
#include <Keypad.h>
#include <Key.h>

#include <LiquidCrystal.h>

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
const byte row_pins[rows] = {43, 45, 47, 49};
const byte column_pins[columns] = {35, 37, 39, 41};

// Initialize the Keypad
Keypad keypad01 = Keypad(makeKeymap(keys), row_pins, column_pins, rows, columns);

// Set the pins used for the LCD
// RS E D3 D2 D1 D0
LiquidCrystal lcd(33, 31, 29, 27, 25, 23);
  
// Valid pincode including the EOF character at the end
const char pincode[5] = "1234";

char usercode[5];
int index = 0;

void setup() {
  // Initialize the LCD and set the LCD size
  lcd.begin(16, 2);

  // Initialize the position in the LCD
  lcd.home();

  // Print in the lcd
  lcd.print("User Code: ");
}

void loop() {
  // Get the key value presed
  char key = keypad01.getKey();

  // Show the cursor blinking
  lcd.cursor();
  delay(500);
  // Hide the cursor
  lcd.noCursor();
  delay(500);
  
  if(key) {
    usercode[index] = key;
    index++;
    lcd.print(key);
  }

  if(index == 6) {
    // Set the position in the LCD
    lcd.setCursor(0,1);
  
    if(!strcmp(usercode, pincode)) {
      lcd.print("Correcta");
    } else {
      lcd.print("Incorrecta");
    }
    index = 0;

    // Wait 5 seconds
    delay(5000);

    // Clear and initialize the LDC
    lcd.clear();
    lcd.print("User Code: ");    
  }

}
