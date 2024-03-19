// Define LED pins
const int ledPins[] = {8, 9, 10}; // Array of LED pins
const int ledCount = sizeof(ledPins) / sizeof(int); // Number of LEDs

// Array to store the interval for each LED
long intervals[] = {500, 700, 900}; // Blink intervals for each LED in milliseconds

// Arrays to store the timing information
unsigned long previousMillis[ledCount] = {0, 0, 0}; // Last update time for each LED

void setup() {
  // Initialize each LED pin as an output
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Get the current time
  unsigned long currentMillis = millis();

  // Loop through each LED
  for (int i = 0; i < ledCount; i++) {
    // Check if it's time to toggle the LED
    if (currentMillis - previousMillis[i] >= intervals[i]) {
      // Save the last update time for this LED
      previousMillis[i] = currentMillis;
      
      // Read the current state and invert it
      int ledState = digitalRead(ledPins[i]);
      digitalWrite(ledPins[i], !ledState);
    }
  }
  // The rest of your program can run here
}
