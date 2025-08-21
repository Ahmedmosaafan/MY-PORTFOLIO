#include <LiquidCrystal_I2C.h>

const int buttonPin = 2;
const int motorPin1 = 3;
const int motorPin2 = 4;

bool lastButtonState = HIGH;
bool currentButtonState;
int mode = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2); 
void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  lcd.begin(16,2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("System Starting...");
  delay(1000);
  lcd.clear();
}

void loop() {
  currentButtonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && currentButtonState == LOW) {
    mode++;
    if (mode > 2) mode = 0;
    updateDisplay();
    delay(300);
  }

  lastButtonState = currentButtonState;

  switch (mode) {
    case 0: // OFF
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
      break;

    case 1: // Fan
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
      break;

    case 2: // Suction
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, HIGH);
      break;
  }
}

void updateDisplay() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Mode: ");
  switch (mode) {
    case 0: lcd.print("OFF"); break;
    case 1: lcd.print("Fan"); break;
    case 2: lcd.print("Suction"); break;
  }
}
