#include "DHT.h" // Include the DHT library

#define DHTPIN 2          // DHT sensor is connected to pin 2
#define DHTTYPE DHT11     // Define the type of DHT sensor used, DHT11

DHT dht(DHTPIN, DHTTYPE); // Initialize the DHT sensor

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 baud
  dht.begin();        // Initialize the DHT11 sensor
}

void loop() {
  delay(2000); // Wait for 2 seconds to give the sensor time to stabilize

  // Read humidity and temperature values
  float humidity = dht.readHumidity();        // Read humidity value and store it
  float temperature = dht.readTemperature();  // Read temperature value and store it

  // Print humidity and temperature to the Serial Monitor, including the degree Celsius symbol
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C"); // Include the degree Celsius symbol here

  // Optionally, check if any reads failed and exit early (to the next loop iteration).
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
}
