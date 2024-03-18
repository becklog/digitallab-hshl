# Fritzing and Wiring Diagrams

## Arduino UNO

<div>
<p align="center">
  <a href="https://becklog.github.io/digitallab-hshl/tasks/1">
    <img src="https://raw.githubusercontent.com/becklog/digitallab-hshl/main/docs/wiring_diagrams/UNO-Simple-RGB-LED.png" alt="Fritzing" style="width: 50%;">
  </a>
</p>
</div>

```C
const int pinRed = 13;       //220 ohm 
const int pinYellow = 12;    //220 ohm
const int pinGreen = 8;      //220 ohm
```

---

<div>
<p align="center">
  <a href="https://becklog.github.io/digitallab-hshl/tasks/1">
    <img src="https://raw.githubusercontent.com/becklog/digitallab-hshl/main/docs/wiring_diagrams/UNO-DHT11-Temperature_Humidity.png" alt="Fritzing" style="width: 50%;">
  </a>
</p>
</div>

```C
const int dht = 2; // signal
```

---

<div>
<p align="center">
  <a href="https://becklog.github.io/digitallab-hshl/tasks/1">
    <img src="https://raw.githubusercontent.com/becklog/digitallab-hshl/main/docs/wiring_diagrams/UNO-Ultrasonic-Distance.png" alt="Fritzing" style="width: 50%;">
  </a>
</p>
</div>


```C
const int ultrasonic_trigger = 6;
const int ultrasonic_echo = 5; 
```

---

<div>
<p align="center">
  <a href="https://becklog.github.io/digitallab-hshl/tasks/1">
    <img src="https://raw.githubusercontent.com/becklog/digitallab-hshl/main/docs/wiring_diagrams/UNO-Servo-Motor.png" alt="Fritzing" style="width: 50%;">
  </a>
</p>
</div>

```C
const int servo_pin = 9;
```
---

<div>
<p align="center">
  <a href="https://becklog.github.io/digitallab-hshl/tasks/1">
    <img src="https://raw.githubusercontent.com/becklog/digitallab-hshl/main/docs/wiring_diagrams/UNO-LCD-Display.png" alt="Fritzing" style="width: 50%;">
  </a>
</p>
</div>

---


```C
const int lcd_scl = A4;
const int lcd_sda = A5
```

<div>
<p align="center">
  <a href="https://becklog.github.io/digitallab-hshl/tasks/1">
    <img src="https://raw.githubusercontent.com/becklog/digitallab-hshl/main/docs/wiring_diagrams/UNO-ColorSensor.png" alt="Fritzing" style="width: 50%;">
  </a>
</p>
</div>

```C
// UNO-2
const int out = 2;
const int s2 = 4;
const int s3 = 3;
const int s1 = 5;
const int s0 = 6;
```

---
---

## Arduino MEGA
<div>
<p align="center">
  <a href="https://becklog.github.io/digitallab-hshl/tasks/1">
    <img src="https://raw.githubusercontent.com/becklog/digitallab-hshl/main/docs/wiring_diagrams/MEGA_7-segment.png" alt="Fritzing" style="width: 50%;">
  </a>
</p>
  
```C
// MEGA-1
const int segmentPins[] = {2, 3, 4, 5, 6, 7, 8};   // For segments A-G
const int displayPins[] = {9, 10, 11, 12};         // For the 4 displays
```

```C
// MEGA-X
// optional  MAX7219 LED controller
#include <LedControl.h>

// Parameters: (DataIn, CLK, LOAD, number of devices)
LedControl lc=LedControl(11,13,10,1);

void setup() {
  lc.shutdown(0,false);       // Wake up displays
  lc.setIntensity(0,8);       // Set brightness level (0 is min, 15 is max)
  lc.clearDisplay(0);         // Clear display register
}

void loop() {
  // Your code to control the matrix here
}

```


---

<div>
<p align="center">
  <a href="https://becklog.github.io/digitallab-hshl/tasks/1">
    <img src="https://raw.githubusercontent.com/becklog/digitallab-hshl/main/docs/wiring_diagrams/MEGA_8x8_LED-matrices.png" alt="Fritzing" style="width: 50%;">
  </a>
</p>
</div>

```C
// First 8x8 matrix
#define C8 52
#define C7 50
#define R2 48
#define C1 46
#define R4 44
#define C6 42
#define C4 40
#define R1 38

#define R3 39
#define R6 41
#define C5 43
#define R8 45
#define C3 47
#define C2 49
#define R7 51
#define R5 53

// Second 8x8 matrix

#define C8 37
#define C7 35
#define R2 33
#define C1 34
#define R4 32
#define C6 30
#define C4 28
#define R1 26

#define R3 14
#define R6 15
#define C5 16
#define R8 17
#define C3 18
#define C2 19
#define R7 22
#define R5 24

void setup() {
   pinMode(R1, OUTPUT);
   pinMode(R2, OUTPUT);
   pinMode(R3, OUTPUT);
   pinMode(R4, OUTPUT);
   pinMode(R5, OUTPUT);
   pinMode(R6, OUTPUT);
   pinMode(R7, OUTPUT);
   pinMode(R8, OUTPUT);
   pinMode(C1, OUTPUT);
   pinMode(C2, OUTPUT);
   pinMode(C3, OUTPUT);
   pinMode(C4, OUTPUT);
   pinMode(C5, OUTPUT);
   pinMode(C6, OUTPUT);
   pinMode(C7, OUTPUT);
   pinMode(C8, OUTPUT);

// Turning all the LEDs off at the start of the sketch
  digitalWrite(R1,HIGH);
  digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);
  digitalWrite(R4,HIGH);
  digitalWrite(R5,HIGH);
  digitalWrite(R6,HIGH);
  digitalWrite(R7,HIGH);
  digitalWrite(R8,HIGH);
  digitalWrite(C1,LOW);
  digitalWrite(C2,LOW);
  digitalWrite(C3,LOW);
  digitalWrite(C4,LOW);
  digitalWrite(C5,LOW);
  digitalWrite(C6,LOW);
  digitalWrite(C7,LOW);
  digitalWrite(C8,LOW);
}
```

```C
// Alternative Declaration for One:

// Pin assignments organized in arrays
int rows[] = {26, 33, 14, 32, 24, 15, 22, 17}; // R1, R2, R3, R4, R5, R6, R7, R8
int cols[] = {34, 19, 18, 28, 16, 30, 35, 37}; // C1, C2, C3, C4, C5, C6, C7, C8

void setup() {
  // Initialize row pins
  for (int i = 0; i < sizeof(rows)/sizeof(rows[0]); i++) {
    pinMode(rows[i], OUTPUT);
    digitalWrite(rows[i], HIGH); // Assuming HIGH turns LEDs off
  }

  // Initialize column pins
  for (int i = 0; i < sizeof(cols)/sizeof(cols[0]); i++) {
    pinMode(cols[i], OUTPUT);
    digitalWrite(cols[i], LOW); // Assuming LOW turns LEDs off
  }
}

```
--- 


