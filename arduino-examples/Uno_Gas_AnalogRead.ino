void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 bits per second.
}

void loop() {
  int gasValue = analogRead(A1); // Read the gas sensor value from analog pin A1

  // Print the gas sensor value to the Serial Monitor
  Serial.println(gasValue, DEC); // DEC is optional here as it's the default

  delay(100); // Delay for a short period to avoid flooding the Serial Monitor
}
