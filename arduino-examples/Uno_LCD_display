#include <Wire.h> // Include Wire library for I2C communication
#include <LiquidCrystal_I2C.h> // Include the library for the I2C LCD display

// Initialize the LCD display object with address 0x27 for a 16x2 character display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define constants for the LED pin and fading parameters
const int ledPin = 13; // LED connected to pin 13 or internal
const int maxBrightness = 255; // Maximum brightness level for LED
const int fadeIncrement = 5; // Increment value for fading effect
const int fadeDelay = 30; // Delay in milliseconds for each fade step

void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
  lcd.init(); // Initialize the LCD display
  lcd.backlight(); // Turn on the LCD backlight

  // Display static text on the LCD
  lcd.setCursor(0, 0); // Set cursor to the first character of the first line
  lcd.print("digitallab.hshl.org");
  lcd.setCursor(0, 1); // Set cursor to the first character of the second line
  lcd.print("June 2023");
}

void loop() {
  // Fade the LED in
  for(int brightness = 0; brightness <= maxBrightness; brightness += fadeIncrement) {
    analogWrite(ledPin, brightness);
    delay(fadeDelay);
  }
  
  // Fade the LED out
  for(int brightness = maxBrightness; brightness >= 0; brightness -= fadeIncrement) {
    analogWrite(ledPin, brightness);
    delay(fadeDelay);
  }
}
