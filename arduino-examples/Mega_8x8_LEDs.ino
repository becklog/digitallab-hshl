// Define the Arduino Mega pins connected to the rows and columns of the 8x8 LED matrix
#define ROW_PINS {38, 48, 39, 44, 53, 41, 51, 45} // Pins connected to rows R1 to R8
#define COL_PINS {46, 49, 47, 40, 43, 42, 50, 52} // Pins connected to columns C1 to C8

// Initialize arrays to hold the pin numbers for easy iteration
int rowPins[] = ROW_PINS;
int colPins[] = COL_PINS;

void setup() {
  // Set all row and column pins as outputs
  for (int i = 0; i < 8; i++) {
    pinMode(rowPins[i], OUTPUT);
    pinMode(colPins[i], OUTPUT);
  }

  // Initialize all LEDs to be off. Rows are active HIGH, Columns are active LOW.
  for (int i = 0; i < 8; i++) {
    digitalWrite(rowPins[i], LOW); // Turn off all rows
    digitalWrite(colPins[i], HIGH); // Turn off all columns
  }
}

// Function to select a specific row
void selectRow(int rowIndex) {
  // Set the selected row HIGH and all others LOW
  for (int i = 0; i < 8; i++) {
    digitalWrite(rowPins[i], (i == rowIndex) ? HIGH : LOW);
  }
}

// Function to select a specific column
void selectColumn(int colIndex) {
  // Set the selected column LOW (active) and all others HIGH (inactive)
  for (int i = 0; i < 8; i++) {
    digitalWrite(colPins[i], (i == colIndex) ? LOW : HIGH);
  }
}

void loop() {
  // Iterate over each row and column, activating one LED at a time
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      selectRow(row);
      selectColumn(col);
      delay(100); // Delay to visually observe the LED
    }
  }
}
