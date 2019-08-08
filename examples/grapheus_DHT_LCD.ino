// DHT22 Temperature & Humidity display on 16x2 LCD Display
// Unified Sensor Library Example// Written by Ahmed Fayaz, GRAPHEUS, New Zealand
// www.grapheus.co.nz

// USes the following Arduino libraries:
// (1) Adafruit Unified Sensor Library: https://github.com/adafruit/Adafruit_Sensor
// (2) DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Pin which is connected to the DHT sensor.
#define DHTPIN 9

// Set the LCD address to 0x3F for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16, 2);

// Uncomment the type of sensor in use:
//#define DHTTYPE           DHT11     // DHT 11 
#define DHTTYPE           DHT22     // DHT 22 (AM2302)
//#define DHTTYPE           DHT21     // DHT 21 (AM2301)

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

void setup() {
  Serial.begin(9600); 
  // Initialize device.
  dht.begin();

  // initialize the LCD
  lcd.begin();
  lcd.backlight();
  
  Serial.println("www.grapheus.co.nz");

  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  dht.humidity().getSensor(&sensor);
  delayMS = sensor.min_delay / 1000;
}

void loop() {
  // Delay between measurements.
  delay(delayMS);
  // Get temperature event and print its value.
  sensors_event_t event;  
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println("Error reading temperature!");
  }
  else {
    //Serial.print("Temperature: ");
    //Serial.print(event.temperature);
    //Serial.println(" *C");
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(event.temperature);
    lcd.print((char)223); //degree sign
    lcd.print("C");
  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println("Error reading humidity!");
  }
  else {
    //Serial.print("Humidity: ");
    //Serial.print(event.relative_humidity);
    //Serial.println("%");
    lcd.setCursor(0, 1);
    lcd.print("Humid: ");
    lcd.print(event.relative_humidity);
    lcd.print(" %");
  }
}
