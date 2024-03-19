#include <DHT.h>

// DHT Sensor Setup
#define DHTPIN 2            // DHT11 sensor is connected to pin 2
#define DHTTYPE DHT11       // DHT11 type
DHT dht(DHTPIN, DHTTYPE);

// Ultrasonic Sensor Setup
#define echoPin 5           // Echo Pin of HC-SR04 connected to pin 5
#define trigPin 6           // Trigger Pin of HC-SR04 connected to pin 6

// Variables for DHT11 smoothing
const int numReadings = 10;
float tempReadings[numReadings];
int readIndex = 0;
float totalTemp = 0;
float averageTemp = 0;

unsigned long previousMillis = 0; 
const long interval = 60000;      // Interval for sensor readings (1 minute)

void setup() {
  Serial.begin(9600);             
  dht.begin();                    
  pinMode(trigPin, OUTPUT);       
  pinMode(echoPin, INPUT);        
  // Initialize all the readings to 0
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    tempReadings[thisReading] = 0;
  }
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Read new temperature value
    float newTemperature = dht.readTemperature();
    // Update average temperature
    totalTemp -= tempReadings[readIndex];
    tempReadings[readIndex] = newTemperature;
    totalTemp += tempReadings[readIndex];
    readIndex = (readIndex + 1) % numReadings;
    averageTemp = totalTemp / numReadings;
  
    // Calculate speed of sound in cm/us based on average temperature
    float speedOfSound = 331.4 + (0.606 * averageTemp);
    float soundSpeedInCmPerUs = speedOfSound * 100 / 1000000;

    // Trigger ultrasonic sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    long duration = pulseIn(echoPin, HIGH);
    int distance = duration * soundSpeedInCmPerUs / 2;

    // Print the results
    Serial.print("Average Temperature: ");
    Serial.print(averageTemp);
    Serial.println(" °C");
    Serial.print("Calculated Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
}
