// DHT22 Humidity and Temperature Sensor

// Installation of DHT sensor library and Adafruit
// Unified Sensor by Adafruit is required
#include <DHT.h>
#include <DHT_U.h>

const int sensor_pin = 3;

DHT dht(sensor_pin, DHT22);

void setup() {
  // Initialize and Set the serial port speed
  Serial.begin(9600);

  // Initialize DHT Sensor
  dht.begin();
}

void loop() {
  // Read Temperature and Humidity from the sensor
  int temperature = dht.readTemperature();
  int humidity = dht.readHumidity();

  // Print the info in the console
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
}
