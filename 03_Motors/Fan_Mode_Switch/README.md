# Arduino Fan Mode Switch Project

This is a simple Arduino project that simulates the **mode switching** feature of a typical exhaust fan . It allows switching between three modes using a **single push button**:

- **Mode 1**: Fan ON (Clockwise rotation)
- **Mode 2**: Fan ON (Counter-Clockwise rotation)
- **Mode 3**: Fan OFF

> ⚠️ Note: This project **does not control fan speed**, it only changes the mode (like an exhaust fan). No potentiometer is used.

## 🧰 Components Used

- Arduino Uno
- L298N Motor Driver
- DC Motor
- Push Button
- Lithium 9V Battery
- Jumper Wires
- Breadboard

## ⚙️ How It Works

- The push button is used to cycle through 3 modes:
  1. Motor rotates in one direction.
  2. Motor rotates in the opposite direction.
  3. Motor stops.
- Each time the button is pressed, the mode changes.
- The DC motor is connected to **Output 3 and 4** of the L298N driver.
- The motor driver is controlled via **Arduino digital pins 3 and 4**.
- Power is supplied using a **9V Lithium battery**.

## 🧾 Code Example

The full code is included in the repository under `fan_modes.ino`.

## 🔋 Power Info

The project is powered using a **Lithium 9V battery**, which is suitable for small DC motors. Make sure the battery is charged for reliable performance.


## 📦 Future Ideas

- Add speed control using PWM and a potentiometer.
- Display the current mode on an LCD.
- Add a remote control for mode switching.

---
