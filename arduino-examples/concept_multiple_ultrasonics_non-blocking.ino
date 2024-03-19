#include <Arduino.h>

// Define pin connections for the first ultrasonic sensor
#define echoPin1 5
#define trigPin1 6

// Define pin connections for the second ultrasonic sensor
#define echoPin2 7
#define trigPin2 8

// Variables for measuring durations and calculating distances
long duration1, duration2;
int distance1, distance2;

// Variables to manage timing without delay()
unsigned long previousMillis1 = 0, previousMillis2 = 0;
const long interval = 2000; // Interval at which to take measurements (2 seconds)

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Set pin modes for both ultrasonic sensors
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  // Handle the first ultrasonic sensor
  if (currentMillis - previousMillis1 >= interval) {
    previousMillis1 = currentMillis;

    // Trigger the measurement for the first sensor
    digitalWrite(trigPin1, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1, LOW);
    duration1 = pulseIn(echoPin1, HIGH);
    distance1 = duration1 * 0.034 / 2;

    // Print the first sensor's distance
    Serial.print("Sensor 1 Distance: ");
    Serial.print(distance1);
    Serial.println(" cm");
  }

  // Handle the second ultrasonic sensor
  if (currentMillis - previousMillis2 >= interval) {
    previousMillis2 = currentMillis;

    // Trigger the measurement for the second sensor
    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);
    duration2 = pulseIn(echoPin2, HIGH);
    distance2 = duration2 * 0.034 / 2;

    // Print the second sensor's distance
    Serial.print("Sensor 2 Distance: ");
    Serial.print(distance2);
    Serial.println(" cm");
  }

  // Note: The actual measurement for each sensor could be moved to a function
  // for better code reuse and readability, especially if more sensors are added.
}
