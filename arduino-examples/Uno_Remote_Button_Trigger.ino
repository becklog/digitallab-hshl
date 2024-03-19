#include <Servo.h>

Servo myservo; 
int servoPin = 9;   
int buttonPin = 2;  // Button connected to digital pin 2
int currentAngle = 90; // Start at neutral position

unsigned long lastDebounceTime = 0; // Timestamp of the last debounce check
unsigned long debounceDelay = 50; // Debounce delay in milliseconds
int lastButtonState = HIGH; // Last stable button state
int buttonState; // Current reading of the button state

void setup() {
  Serial.begin(9600); 
  myservo.attach(servoPin);
  myservo.write(currentAngle);
  pinMode(buttonPin, INPUT_PULLUP); // Use internal pull-up resistor
  Serial.println("Ready");
}

void loop() {
  int reading = digitalRead(buttonPin); // Read the button state

  // Check if the button state has changed to detect noise
  if (reading != lastButtonState) {
    lastDebounceTime = millis(); // Reset the debouncing timer
  }
  
  // If the current state has been stable longer than the debounce delay, proceed
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // If the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;
      // Only act on the button press, not the release (assuming active LOW)
      if (buttonState == LOW) {
        Serial.println("Debounced Button Pressed");
        myservo.write(180); // Example action: rotate servo to 180 degrees
        delay(1000); // Wait for a while to simulate action duration
        myservo.write(90); // Return to neutral position
      }
    }
  }
  lastButtonState = reading; // Save the current reading as the last stable state
}

