# 🌡 Temperature & Humidity Display with LCD I2C and DHT11

This Arduino project reads **temperature** and **humidity** from a DHT11 sensor and displays the values on a **16x2 LCD** using the **I2C interface**.

---

## 🛠 Components Required
- Arduino Uno (or compatible board)
- DHT11 Temperature & Humidity Sensor
- 16x2 LCD with I2C module
- Jumper wires
- Breadboard

---

## ⚡ Wiring Diagram

| Component Pin       | Arduino Pin |
|---------------------|-------------|
| DHT11 VCC           | 5V          |
| DHT11 GND           | GND         |
| DHT11 Data          | D2          |
| LCD I2C VCC         | 5V          |
| LCD I2C GND         | GND         |
| LCD I2C SDA         | A4          |
| LCD I2C SCL         | A5          |

---
🖥 How It Works
1. The DHT11 sensor measures temperature and humidity.

2. Data is sent to the Arduino.

3. Arduino sends the readings to the LCD via I2C.

4. The LCD displays the current temperature and humidity values.
---

📷 Example Output

Temp: 25°C
Hum: 60%


## 💻 Arduino Code
```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 2       // Pin connected to DHT11
#define DHTTYPE DHT11  // Sensor type: DHT11

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address, columns, rows
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.init();           // Initialize LCD
  lcd.backlight();      // Turn on backlight
  dht.begin();          // Start DHT sensor
}

void loop() {
  float temp = dht.readTemperature(); // Read temperature (°C)
  float hum = dht.readHumidity();     // Read humidity (%)

  lcd.clear();

  lcd.setCursor(0, 0); // First row
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print((char)223); // Degree symbol
  lcd.print("C");

  lcd.setCursor(0, 1); // Second row
  lcd.print("Hum: ");
  lcd.print(hum);
  lcd.print("%");

  delay(2000); // Update every 2 seconds
}
