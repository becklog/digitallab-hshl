// Define the LED pin and variables for timing
const int ledPin = 8; // LED connected to digital pin 8
unsigned long previousMillis = 0; // will store last time LED was updated
long interval = 1000; // interval at which to blink (milliseconds)

void setup() {
  // Initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Here we'll use the millis() function to manage when the LED turns on and off
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (digitalRead(ledPin) == LOW) {
      digitalWrite(ledPin, HIGH); // Turn the LED on
      interval = 500; // Change the interval for faster blinking
    } else {
      digitalWrite(ledPin, LOW); // Turn the LED off
      interval = 1000; // Change the interval back for slower blinking
    }
  }

  // The rest of your program can run here without being affected by the delay
}
