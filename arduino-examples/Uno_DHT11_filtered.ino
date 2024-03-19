#include <DHT.h>

// DHT Sensor Setup
#define DHTPIN 2            // DHT11 sensor is connected to pin 2
#define DHTTYPE DHT11       // DHT11 type
DHT dht(DHTPIN, DHTTYPE);

// Ultrasonic Sensor Setup
#define echoPin 5           // Echo Pin of HC-SR04 connected to pin 5
#define trigPin 6           // Trigger Pin of HC-SR04 connected to pin 6

// Timing Variables
unsigned long previousMillis = 0; // Stores last time temperature was updated
const long interval = 60000;      // Interval at which to read the sensor (1 minute)

// Smoothing Variables
const int numReadings = 10;       // Number of readings to average
float tempReadings[numReadings];  // Temperature readings from the sensor
float humReadings[numReadings];   // Humidity readings from the sensor
int readIndex = 0;                // the index of the current reading
float totalTemp = 0;              // the total of the temperature readings
float totalHum = 0;               // the total of the humidity readings
float averageTemp = 0;            // the average of the temperature readings
float averageHum = 0;             // the average of the humidity readings

void setup() {
  Serial.begin(9600);             // Start serial communication
  dht.begin();                    // Initialize the DHT11 sensor
  pinMode(trigPin, OUTPUT);       // Set the trigger pin as output
  pinMode(echoPin, INPUT);        // Set the echo pin as input
  // Initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    tempReadings[thisReading] = 0;
    humReadings[thisReading] = 0;
  }
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    // Save the last time you read the sensor
    previousMillis = currentMillis;

    // Subtract the last reading:
    totalTemp -= tempReadings[readIndex];
    totalHum -= humReadings[readIndex];

    // Read temperature and humidity from DHT11
    float newTemperature = dht.readTemperature();
    float newHumidity = dht.readHumidity();

    // Add the reading to the total:
    tempReadings[readIndex] = newTemperature;
    humReadings[readIndex] = newHumidity;
    totalTemp += tempReadings[readIndex];
    totalHum += humReadings[readIndex];

    // Advance to the next position in the array:
    readIndex = (readIndex + 1) % numReadings;

    // Calculate the averages:
    averageTemp = totalTemp / numReadings;
    averageHum = totalHum / numReadings;

    // Print the averages to the Serial Monitor
    Serial.print("Average Temperature: ");
    Serial.print(averageTemp);
    Serial.println(" °C");
    Serial.print("Average Humidity: ");
    Serial.print(averageHum);
    Serial.println(" %");
  }

  // Note: Add your ultrasonic sensor code here, using the smoothed temperature value (averageTemp)
  // to adjust the speed of sound if necessary.
}
