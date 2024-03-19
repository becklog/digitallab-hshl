/*
This example illustrates how to use a potentiometer to adjust the blinking rate of an LED in real-time, without using delay(). As the potentiometer's resistance changes, it alters the input voltage read by analogRead(), which then dynamically adjusts the blinking interval of the LED. This method allows the main program loop to remain responsive to other inputs or tasks, showcasing a fundamental multitasking technique.

By integrating sensor input with non-blocking timing, you can create interactive projects that respond immediately to user inputs or environmental changes, a cornerstone of effective embedded system design.
*/

// Define the LED and potentiometer pins
const int ledPin = 9;
const int potPin = A0;

// Variables for timing
unsigned long previousMillis = 0;
unsigned long interval = 100; // Default interval

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  
  // Read the potentiometer value
  int potValue = analogRead(potPin);
  // Map the potentiometer value to a suitable range for interval
  interval = map(potValue, 0, 1023, 50, 1000); // Adjust these values as needed
  
  // Check if it's time to toggle the LED
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; // Save the last update time
    
    // If the LED is on, turn it off, and vice versa
    digitalWrite(ledPin, !digitalRead(ledPin));
  }
  // Your program can handle other tasks here without delay
}
