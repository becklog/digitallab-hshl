#include <Servo.h>

Servo myservo; // Create servo object to control a servo
int val = 0; // Variable to store the servo position

void setup() {
  Serial.begin(9600); // Initialize Serial communication at 9600 baud rate
  myservo.attach(9); // Attaches the servo on pin 9 to the servo object
  Serial.println("Enter a value between 0 and 180: ");
}

void loop() {
  String inputString = ""; // String to store the incoming input

  if (Serial.available() > 0) { // Check if data is available to read
    inputString = Serial.readString(); // Read the incoming string
    val = inputString.toInt(); // Convert the incoming string to an integer

    if (val >= 0 && val <= 180) { // Check if the value is within the servo's range
      myservo.write(val); // Sets the servo position according to the scaled value
      Serial.print("Moving servo to ");
      Serial.println(val);
    } else {
      Serial.println("Value is out of range. Please enter a value between 0 and 180.");
    }
    Serial.println("Enter a value between 0 and 180: "); // Prompt again for the next input
  }

  // No need for a delay here, as Serial.readString() pauses the execution until the newline character is received
}
