# 📏 HC-SR04 Distance Meter with 3 LEDs + Buzzer + LCD

This Arduino project measures distance using the **HC-SR04 Ultrasonic Sensor** and gives **visual and audio alerts** based on the distance, while showing readings on an **I2C LCD**.

---

## Components
- Arduino UNO
- HC-SR04 Ultrasonic Sensor
- 3 LEDs (Green, Yellow, Red)
- Buzzer
- LCD 16x2 with I2C module
- Jumper wires
- Breadboard

---

## Connections

| Component | Pin |
|-----------|-----|
| Trig (HC-SR04) | 9 |
| Echo (HC-SR04) | 10 |
| Green LED | 3 |
| Yellow LED | 4 |
| Red LED | 5 |
| Buzzer | 6 |
| LCD SDA | A4 |
| LCD SCL | A5 |
| VCC & GND | 5V & GND |

---

## How it Works
- The HC-SR04 measures the distance to an object.  
- Based on the measured distance:
  - **>50 cm** → Green LED ON, no buzzer  
  - **20–50 cm** → Yellow LED ON, no buzzer  
  - **<20 cm** → Red LED ON, buzzer beeps faster as object gets closer  
- Distance is displayed on the **LCD**.  
- If no echo is detected, LCD shows **"No Echo"**.

---

## Features
- Visual alert with **3 LEDs**.  
- Audio alert with **buzzer**.  
- LCD shows real-time distance readings.  
- Adjustable buzzer speed using `map()` function according to distance.

---

## Author
- **Ahmed Mosaafan**  
  Mechatronics Engineering Student ⚙️  
  Interested in Robotics & Automation 🤖
