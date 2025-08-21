#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 2       // البن الموصل عليه الحساس
#define DHTTYPE DHT11  // نوع الحساس

LiquidCrystal_I2C lcd(0x27, 16, 2); // غيّر 0x27 للعنوان اللي طلع معاك
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.init();      
  lcd.backlight(); 
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print((char)223); // رمز درجة الحرارة
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(hum);
  lcd.print("%");

  delay(2000);
}
