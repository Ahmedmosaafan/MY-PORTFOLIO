// HC-SR04 Distance + 3 LEDs + Buzzer + LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// إعداد عنوان الـ LCD وحجمه
LiquidCrystal_I2C lcd(0x27, 16, 2); // لو مش شغال جرّب 0x3F

const int trigPin = 9;
const int echoPin = 10;
const int ledGreen = 3;
const int ledYellow = 4;
const int ledRed = 5;
const int buzzer = 6;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(trigPin, LOW);

  // تشغيل LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Distance Meter");
  delay(1000);
  lcd.clear();
}

long measureDistanceCM() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH, 30000UL); // timeout 30ms
  if (duration == 0) return -1;
  long distance = duration * 0.0343 / 2; // cm
  return distance;
}

void loop() {
  long d = measureDistanceCM();

  if (d == -1) {
    Serial.println("No echo");
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, LOW);
    noTone(buzzer);

    // عرض رسالة على الشاشة
    lcd.setCursor(0, 0);
    lcd.print("No Echo       ");
    lcd.setCursor(0, 1);
    lcd.print("Check sensor  ");

  } else {
    Serial.print("Distance: ");
    Serial.print(d);
    Serial.println(" cm");

    // عرض المسافة على الشاشة
    lcd.setCursor(0, 0);
    lcd.print("Distance:     ");
    lcd.setCursor(0, 1);
    lcd.print(d);
    lcd.print(" cm   ");

    if (d > 50) {
      digitalWrite(ledGreen, HIGH);
      digitalWrite(ledYellow, LOW);
      digitalWrite(ledRed, LOW);
      noTone(buzzer);
    } else if (d > 20) {
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledYellow, HIGH);
      digitalWrite(ledRed, LOW);
      noTone(buzzer);
    } else {
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledYellow, LOW);
      digitalWrite(ledRed, HIGH);
      // صفارة تتكرر أسرع كلما قلّت المسافة
      int period = map(d, 0, 20, 100, 600);
      tone(buzzer, 1000);
      delay(80);
      noTone(buzzer);
      delay(max(0, period - 80));
    }
  }
  delay(150);
}
