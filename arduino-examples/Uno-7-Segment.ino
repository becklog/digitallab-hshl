#include <TimerOne.h>

// Define pin assignments for segments and digits in a clear, organized manner
const int SEGMENT_A = 9;
const int SEGMENT_B = 13;
const int SEGMENT_C = 4;
const int SEGMENT_D = 6;
const int SEGMENT_E = 7;
const int SEGMENT_F = 10;
const int SEGMENT_G = 3;
const int SEGMENT_DP = 5; // Decimal point
const int DIGIT_1 = 8;
const int DIGIT_2 = 11;
const int DIGIT_3 = 12;
const int DIGIT_4 = 2;

long displayValue = 0; // Value displayed on the 4-digit 7-segment display
const int delayTime = 5; // Delay time in milliseconds for segment transition
int counter = 0; // Counter increases every 0.1 second; 1 second is counted when the value is 10

void setup() {
  // Set segment and digit pins as outputs
  int segments[] = {SEGMENT_A, SEGMENT_B, SEGMENT_C, SEGMENT_D, SEGMENT_E, SEGMENT_F, SEGMENT_G, SEGMENT_DP};
  for (int segment : segments) pinMode(segment, OUTPUT);

  int digits[] = {DIGIT_1, DIGIT_2, DIGIT_3, DIGIT_4};
  for (int digit : digits) pinMode(digit, OUTPUT);

  // Initialize timer with a 0.1 second period (100000 microseconds)
  TimerOne.initialize(100000);
  TimerOne.attachInterrupt(timerInterrupt);
}

void loop() {
  displayNumber();
}

void displayNumber() {
  // Display each digit with a slight delay
  for (int digit = 0; digit < 4; digit++) {
    clearLEDs();
    selectDigit(digit);
    displayDigit((displayValue / int(pow(10, 3 - digit))) % 10);
    delay(delayTime);
  }
}

void selectDigit(int digit) {
  // Activate the correct digit by setting its pin LOW and others HIGH
  digitalWrite(DIGIT_1, digit == 0 ? LOW : HIGH);
  digitalWrite(DIGIT_2, digit == 1 ? LOW : HIGH);
  digitalWrite(DIGIT_3, digit == 2 ? LOW : HIGH);
  digitalWrite(DIGIT_4, digit == 3 ? LOW : HIGH);
}

void displayDigit(int number) {
  // Define an array representing the state of each segment for numbers 0-9
  bool numbers[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
  };
  
  // Update segments to display the current number
  int segments[] = {SEGMENT_A, SEGMENT_B, SEGMENT_C, SEGMENT_D, SEGMENT_E, SEGMENT_F, SEGMENT_G};
  for (int i = 0; i < 7; i++) digitalWrite(segments[i], numbers[number][i]);
}

void clearLEDs() {
  // Turn off all segments (including decimal point)
  digitalWrite(SEGMENT_A, LOW);
  digitalWrite(SEGMENT_B, LOW);
  digitalWrite(SEGMENT_C, LOW);
  digitalWrite(SEGMENT_D, LOW);
  digitalWrite(SEGMENT_E, LOW);
  digitalWrite(SEGMENT_F, LOW);
  digitalWrite(SEGMENT_G, LOW);
  digitalWrite(SEGMENT_DP, LOW);
}

void timerInterrupt() {
  // Increment counter every 0.1 seconds; update displayValue every second
  counter++;
  if (counter >= 10) {
    counter = 0;
    displayValue++;
    if (displayValue >= 10000) displayValue = 0; // Reset after reaching 9999
  }
}
