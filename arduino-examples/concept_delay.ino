// Define the LED pin
const int ledPin = 13; // Standard internal LED pin for Arduino Uno

void setup() {
  // Initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Turn the LED on:
  digitalWrite(ledPin, HIGH);
  // Pause the program for 1000 milliseconds (1 second)
  delay(1000);
  // Turn the LED off:
  digitalWrite(ledPin, LOW);
  // Pause the program for 1000 milliseconds (1 second)
  delay(1000);
  
  // Now let's blink the LED faster, with a shorter delay
  digitalWrite(ledPin, HIGH);
  delay(500); // Shorter delay of 500 milliseconds (0.5 seconds)
  digitalWrite(ledPin, LOW);
  delay(500);
  
  // Blink the LED with an even shorter delay for rapid blinking
  digitalWrite(ledPin, HIGH);
  delay(100); // Short delay of 100 milliseconds (0.1 seconds)
  digitalWrite(ledPin, LOW);
  delay(100);
  
  // This loop will run over and over, making the LED blink at different rates
}
