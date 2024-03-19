int led_pin = 3; // PWM pin connected to the LED

void setup() {
  pinMode(led_pin, OUTPUT); // Set the LED pin as OUTPUT
}

void loop() {
  // Ramp up brightness
  for (int i = 0; i <= 255; i++) {
    analogWrite(led_pin, i);
    delay(10); // Faster ramp up
  }
  
  // Short pause at maximum brightness
  delay(500);
  
  // Ramp down brightness
  for (int i = 255; i >= 0; i--) {
    analogWrite(led_pin, i);
    delay(30); // Slower ramp down for effect
  }
  
  // Short pause at minimum brightness
  delay(500);
}
