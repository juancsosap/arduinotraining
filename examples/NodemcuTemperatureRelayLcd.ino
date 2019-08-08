/********************** LYBRARY ****************************/

#define BLYNK_PRINT Serial // Comment this out to disable prints and save space


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>

/* TIMER */
#include <SimpleTimer.h>
SimpleTimer timer;

/********************** BLYNK ACCOUNT ****************************/
char auth[] = "BLYNK_TOKEN";
char ssid[] = "SSID";
char pass[] = "PASS";


/********************** HARDWARE ****************************/
// Temperature sensor full ID, including family code and CRC
// use OneWire Scanner to get the address
DeviceAddress tempSensor = { 0x28, 0xFF, 0x64, 0x1D, 0x8F, 0x87, 0x95, 0xB1 };

// Pin used for the OneWire interface
#define ONE_WIRE_BUS 14 //pin D5 nodemcu Lolin v3

LiquidCrystal_I2C lcd(0x27, 16, 2); //LCD address and type.
//D2 = SDA D1 = SCL

/**************BIG CHAR*********************************************/


/********************** TEMPERATURE DEF****************************/
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);
float temp;

/********************** SETUP ****************************/
void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, IPAddress(188,166,206,43), 8080); //use other method to connect to blynk server
  DS18B20.begin();
  timer.setInterval(15000L, getSendData);
  Blynk.syncAll();

  Wire.begin(D2, D1); // D1 = SCL | D2 = SDA
  lcd.init();
  lcd.backlight();
  lcd.clear();

}

/********************** LOOP ****************************/
void loop()
{
  Blynk.run();
  timer.run();
}

/********************** Send Sensor data to Blynk ****************************/
void getSendData()
{
  DS18B20.requestTemperatures(); 
  temp = DS18B20.getTempCByIndex(0);
  Serial.println(temp);
  Blynk.virtualWrite(10, temp); //virtual pin V10
  
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.setCursor(6,0);
  lcd.print(temp);
  lcd.setCursor(12,0);
  lcd.print("'C");
}
