int ledPin = 3; // PWM pin connected to the LED
int sensorPin = A0; // Analog pin connected to sense the voltage across the shunt resistor

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Example to control LED brightness (can be replaced with your own logic)
  analogWrite(ledPin, 127); // Set to about 50% brightness as an example
  
  int sensorValue = analogRead(sensorPin); // Read the voltage across the shunt resistor
  float voltage = sensorValue * (5.0 / 1023.0); // Convert to voltage
  float current = voltage / 1.0; // Calculate current (A) assuming a 1 Ohm resistor
  
  Serial.print("Current: ");
  Serial.print(current);
  Serial.println(" A");

  delay(1000); // Delay for 1 second before the next read
}
