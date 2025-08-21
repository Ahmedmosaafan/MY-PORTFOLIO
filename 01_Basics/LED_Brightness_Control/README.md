# LED Brightness Control with Potentiometer (Arduino)

This simple Arduino project allows you to control the brightness of an LED using a potentiometer.

## 🔧 Components Used
- Arduino Uno (or any compatible board)
- LED
- 220Ω resistor
- Potentiometer (10kΩ)
- Breadboard and jumper wires

## ⚡ How It Works
- The potentiometer is connected to analog pin `A0`.
- The LED is connected to PWM pin `9` through a resistor.
- The Arduino reads the analog value from the potentiometer (0–1023).
- This value is then mapped to the PWM range (0–255).
- `analogWrite()` is used to adjust the LED brightness accordingly.
- The values are printed to the Serial Monitor for debugging.

## 🧠 Arduino Code
```cpp
const int potPin = A0;
const int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin);
  int ledValue = map(potValue, 0, 1023, 0, 255);

  analogWrite(ledPin, ledValue);

  Serial.print("Pot Value: ");
  Serial.print(potValue);
  Serial.print(" -> LED PWM Value: ");
  Serial.println(ledValue);

  delay(10);
}
