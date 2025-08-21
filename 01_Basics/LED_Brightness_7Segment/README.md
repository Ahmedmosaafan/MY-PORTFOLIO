# LED Brightness with Potentiometer and 7-Segment Display (Arduino)

This project controls the brightness of an LED using a potentiometer and displays the brightness level on a 7-segment display.

## 🔧 Components Used
- Arduino Uno (or compatible board)
- LED
- 3300Ω resistor
- Potentiometer (10kΩ)
- 7-Segment Display (Common Cathode)
- Breadboard and jumper wires

## ⚡ How It Works
- The potentiometer is connected to analog pin `A0`.
- The analog value (0–1023) is read using `analogRead()`.
- This value is mapped to:
  - A PWM value (0–255) to control the LED brightness using `analogWrite()`.
  - A number (0–9) to display on the 7-segment based on brightness level.
- The 7-segment is controlled manually by turning on/off the required pins.

## 🧠 Arduino Code (Example)
```cpp
const int potPin = A0;
const int ledPin = 9;

// Pins for 7-Segment Display (Common Cathode)
const int segPins[7] = {2, 3, 4, 5, 6, 7, 8}; // a, b, c, d, e, f, g

// Segment values for digits 0–9 (common cathode)
const byte digits[10][7] = {
  {1,1,1,1,1,1,0},  // 0
  {0,1,1,0,0,0,0},  // 1
  {1,1,0,1,1,0,1},  // 2
  {1,1,1,1,0,0,1},  // 3
  {0,1,1,0,0,1,1},  // 4
  {1,0,1,1,0,1,1},  // 5
  {1,0,1,1,1,1,1},  // 6
  {1,1,1,0,0,0,0},  // 7
  {1,1,1,1,1,1,1},  // 8
  {1,1,1,1,0,1,1}   // 9
};

void setup() {
  pinMode(ledPin, OUTPUT);
  for (int i = 0; i < 7; i++) {
    pinMode(segPins[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin);
  int ledValue = map(potValue, 0, 1023, 0, 255);
  int digit = map(potValue, 0, 1023, 0, 9);

  analogWrite(ledPin, ledValue);

  // Display digit on 7-segment
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], digits[digit][i]);
  }

  Serial.print("Pot Value: ");
  Serial.print(potValue);
  Serial.print(" -> LED PWM: ");
  Serial.print(ledValue);
  Serial.print(" -> Displayed Digit: ");
  Serial.println(digit);

  delay(100);
}
