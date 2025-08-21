#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

const int flameAnalog = A0;
const int buzzerPin = 3;
const int ledPin = 4;

int threshold = 80; 
unsigned long alarmStartTime = 0;
bool alarmActive = false;

unsigned long previousBlinkTime = 0;
const unsigned long blinkInterval = 500; 

bool ledState = false;

void printCentered(String text, int row) {
  int len = text.length();
  int pos = (16 - len) / 2;
  lcd.setCursor(pos, row);
  lcd.print(text);
}

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);

  lcd.init();
  lcd.noBacklight();

  Serial.begin(9600);
}

void loop() {
  int analogValue = analogRead(flameAnalog);
  Serial.print("Analog Value: ");
  Serial.println(analogValue);

  unsigned long currentTime = millis();

  if (!alarmActive && analogValue < threshold) {
    alarmActive = true;
    alarmStartTime = currentTime;

    lcd.backlight();
    lcd.clear();
    printCentered("WARNING", 0);
    printCentered("Flame Detected", 1);
  }

  if (alarmActive) {
    digitalWrite(buzzerPin, HIGH);

    if (currentTime - previousBlinkTime >= blinkInterval) {
      previousBlinkTime = currentTime;
      ledState = !ledState;
      digitalWrite(ledPin, ledState ? HIGH : LOW);
    }

    if (currentTime - alarmStartTime >= 5000) {
      alarmActive = false;
      digitalWrite(buzzerPin, LOW);
      digitalWrite(ledPin, LOW);

      lcd.clear();
      lcd.noBacklight();
    }
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
  }

  delay(50);
}
