// HC-SR04 Ultrasonic Sensor Example Code
// This example demonstrates basic usage of the HC-SR04 Ultrasonic Sensor
// for distance measurement. The HC-SR04 sensor measures distances by emitting
// an ultrasonic sound wave and timing how long it takes to bounce back.

// Define pin connections & constants
#define echoPin 5 // Echo Pin of HC-SR04 connected to pin 5 on Arduino
#define trigPin 6 // Trigger Pin of HC-SR04 connected to pin 6 on Arduino

// Variables for the duration of the echo pulse and the calculated distance
long duration; // Duration taken for the echo pulse to return to the sensor
int distance; // Calculated distance based on the duration of the echo

void setup() {
  // Pin configurations
  pinMode(trigPin, OUTPUT); // Set the trigger pin as output (sends ultrasonic waves)
  pinMode(echoPin, INPUT);  // Set the echo pin as input (receives the bounced ultrasonic waves)
  Serial.begin(9600);       // Start serial communication at 9600 baud rate
  
  // Initial message displayed on the Serial Monitor
  Serial.println("Ultrasonic Sensor HC-SR04 Test");
  Serial.println("with Arduino UNO R3");
}

void loop() {
  // Ensure trigger pin is low for a clean high pulse later
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // Short delay to ensure low signal clears
  
  // Generate a short 10-microsecond pulse to the trigger input
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // HC-SR04 requires a pulse of at least 10 microseconds
  digitalWrite(trigPin, LOW);

  // Measure the duration of the incoming echo pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance based on the duration of the echo.
  // Sound speed in air (343 meters per second or 0.034 cm/microsecond)
  // The sound travels to the object and back, so we divide the duration by 2
  // Result is in centimeters
  distance = duration * 0.034 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Brief pause before next measurement
  delay(1000); // Delay of 1 second
}
