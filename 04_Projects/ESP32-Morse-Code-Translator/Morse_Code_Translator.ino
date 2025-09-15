
/*
  مشروع مترجم شفرة مورس - نسخة ESP32
  (الإصدار النهائي مع Web Server - كود كامل وغير مختصر)
*/

#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// --- إعدادات الواي فاي ---
const char* ssid = "";       //  <<<-- اكتب اسم شبكة الواي فاي هنا
const char* password = ""; //  <<<-- اكتب باسورد الشبكة هنا

// --- إعدادات الويب سيرفر ---
WebServer server(80);

// --- إعدادات الشاشة ---
LiquidCrystal_I2C lcd(0x27, 16, 2);

// --- إعدادات الأرجل (Pins) للـ ESP32 ---
const int buttonPin = 27;
const int clearButtonPin = 32;
const int ledPin = 12;
const int buzzerPin = 14;

// --- تعريفات توقيت شفرة مورس (بالمللي ثانية) ---
const int dotTime = 200; 
const int dashTime = 400;
const int letterGap = dotTime * 3;
const int wordGap = dotTime * 10;

// --- متغيرات لتتبع الحالة ---
unsigned long pressTime = 0, releaseTime = 0, lastPressTime = 0, clearPressTime = 0;
String currentMorse = "", translatedText = "";
const int debounceDelay = 50, longPressDuration = 500;

// --- جدول شفرة مورس (القاموس) ---
char* morseLetters[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// دالة خاصة بالويب سيرفر: تقوم بإنشاء صفحة الويب
void handleRoot() {
  String html = "<!DOCTYPE html><html><head><title>ESP32 Morse Translator</title>";
  html += "<meta http-equiv='refresh' content='5'>";
  html += "<style>body{font-family: Arial, sans-serif; text-align: center; background-color: #282c34; color: white;}";
  html += "h1{color: #61dafb;} .text-box{border: 2px solid #61dafb; padding: 20px; margin: 20px; font-size: 2em; min-height: 50px;}</style>";
  html += "</head><body><h1>ESP32 Morse Code Translator</h1>";
  html += "<h3>Translated Text:</h3><div class='text-box'>" + translatedText + "</div>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  Wire.begin(26, 25);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(clearButtonPin, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(WiFi.localIP());
  lcd.setCursor(0, 1);
  lcd.print("Connected!");

  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();
  handleClearButton();
  handleMorseInput();
}

void handleClearButton() {
  bool clearButtonPressed = (digitalRead(clearButtonPin) == LOW);
  if (clearButtonPressed) {
    if (clearPressTime == 0) { clearPressTime = millis(); }
  } else {
    if (clearPressTime > 0) {
      unsigned long duration = millis() - clearPressTime;
      if (duration >= longPressDuration) { translatedText = ""; } 
      else { if (translatedText.length() > 0) { translatedText = translatedText.substring(0, translatedText.length() - 1); } }
      updateDisplay();
      clearPressTime = 0;
    }
  }
}

void handleMorseInput() {
  bool buttonPressed = (digitalRead(buttonPin) == LOW);
  if (buttonPressed) {
    if (pressTime == 0 && (millis() - lastPressTime) > debounceDelay) {
      pressTime = millis();
      digitalWrite(ledPin, HIGH);
      tone(buzzerPin, 440);
    }
  } else {
    if (pressTime > 0) {
      unsigned long duration = millis() - pressTime;
      digitalWrite(ledPin, LOW); noTone(buzzerPin);
      if (duration < dashTime) { currentMorse += "."; } else { currentMorse += "-"; }
      pressTime = 0; releaseTime = millis(); lastPressTime = millis();
    }
  }
  if (!buttonPressed && releaseTime > 0) {
    unsigned long idleTime = millis() - releaseTime;
    if (idleTime >= letterGap) {
      if (currentMorse.length() > 0) {
        char letter = translateMorse(currentMorse);
        if (letter != ' ') {
          if (translatedText.length() >= 32) translatedText = "";
          translatedText += letter;
          updateDisplay();
        }
        currentMorse = "";
      }
    }
    if (idleTime >= wordGap) {
       if (translatedText.length() > 0 && !translatedText.endsWith(" ")) {
          if (translatedText.length() >= 32) translatedText = "";
          translatedText += " ";
          updateDisplay();
       }
    }
  }
}

void updateDisplay() {
  lcd.clear();
  if (translatedText.length() <= 16) {
    lcd.setCursor(0, 0);
    lcd.print(translatedText);
  } else {
    String line1 = translatedText.substring(0, 16);
    String line2 = translatedText.substring(16);
    lcd.setCursor(0, 0); lcd.print(line1);
    lcd.setCursor(0, 1); lcd.print(line2);
  }
}

char translateMorse(String morseCode) {
  for (int i = 0; i < 26; i++) {
    if (morseCode == morseLetters[i]) { return alphabet[i]; }
  }
  return ' ';
}