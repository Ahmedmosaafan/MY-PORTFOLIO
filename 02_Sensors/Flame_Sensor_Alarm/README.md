# 🔥 Flame Sensor Alarm System with LCD & Buzzer

## 📜 Project Description
This Arduino project detects flame using a **Flame Sensor** and provides a visual and audible alert.  
When flame is detected, the system:
- Turns on **LCD backlight** and displays an alert message.
- Activates a **buzzer**.
- Makes an **LED blink**.
- Keeps the alarm active for **5 seconds**, even if the flame disappears.

After 10 seconds, the system resets and goes back to monitoring mode.

---

## 🛠 Components Used
- **Arduino UNO / Nano**  
- **Flame Sensor** (Analog Output)  
- **16x2 LCD** with I2C interface (address: `0x27`)  
- **Buzzer**  
- **LED**  
- **Wires & Breadboard**

---

## ⚙ Circuit Connections

| Component          | Arduino Pin |
|--------------------|-------------|
| Flame Sensor (A0)  | A0          |
| Buzzer             | D3          |
| LED                | D4          |
| LCD I2C SDA        | A4          |
| LCD I2C SCL        | A5          |
| LCD VCC            | 5V          |
| LCD GND            | GND         |

---

## 📌 How It Works
1. The flame sensor continuously reads analog values.
2. If the analog value drops below the **threshold** (`80` by default), a flame is detected.
3. The system:
   - Displays **"Flame Detected"** on the LCD (centered text).
   - Turns on the **buzzer**.
   - Makes the **LED blink** every 500 ms.
   - Keeps this state for **10 seconds**.
4. After 10 seconds, the system:
   - Turns off the **buzzer** and LED.
   - Turns off LCD backlight and clears the screen.
5. The system goes back to monitoring mode.

---

## 🖥 Code Features
- **Centered LCD Text** function for better UI.
- Adjustable **flame detection threshold**.
- Non-blocking **LED blinking** using `millis()` (no delay interference).
- Serial Monitor output for debugging.

---

## 🔧 Adjustable Parameters
- **`threshold`** → Flame sensitivity (`80` works for most cases, lower = more sensitive).
- **`blinkInterval`** → LED blink speed (default `500 ms`).
- **Alarm duration** → Change `5000` in the code for different alert durations.

---
