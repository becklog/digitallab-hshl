int ledPin = 3; // PWM pin connected to the LED
int sensorPin = A0; // Analog pin connected to the photoresistor
int sensorValue = 0; // Variable to store the sensor value
int brightness = 0; // Variable to store LED brightness
int fadeAmount = 5; // How many points to fade the LED by

void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as OUTPUT
  Serial.begin(9600); // Start serial communication
}

void loop() {
  // Set the brightness of the LED
  analogWrite(ledPin, brightness);

  // Read the value from the photoresistor
  sensorValue = analogRead(sensorPin);

  // Print the sensor value and the current LED brightness
  Serial.print("Light intensity: ");
  Serial.print(sensorValue);
  Serial.print(", LED Brightness: ");
  Serial.println(brightness);

  // Change the brightness for next cycle
  brightness += fadeAmount;
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount; // Reverse the direction of the fading
  }

  // Wait for 30 milliseconds to see the dimming effect
  delay(30);
}

