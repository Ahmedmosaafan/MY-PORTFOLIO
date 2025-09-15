/*
  مشروع مترجم شفرة مورس - نسخة ESP32
  (إصدار مستقر للتشخيص)
*/

#include <WiFi.h>
#include <WebServer.h>
#include <HTTPClient.h>
#include <UrlEncode.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// --- 1. إعدادات الشبكة والخدمات (عدّل هنا بعناية فائقة) ---
const char* ssid = "";         // <<<-- اكتب اسم شبكة الواي فاي هنا (تأكد من الحروف الكبيرة والصغيرة)
const char* password = "";   // <<<-- اكتب كلمة سر الواي فاي هنا (تأكد من الحروف والرموز)


// --- 2. إعدادات المكونات المادية ---
WebServer server(80);
LiquidCrystal_I2C lcd(0x27, 16, 2);

// --- إعدادات الأرجل (Pins) للـ ESP32 ---
const int buttonPin = 27;
const int clearButtonPin = 32;
const int sendButtonPin = 33;
const int ledPin = 12;
const int buzzerPin = 14;

// --- 3. متغيرات شفرة مورس (لا تعدل هنا) ---
const int dotTime = 250;
const int dashTime = dotTime * 3;
const int letterGap = dotTime * 3;
const int wordGap = dotTime * 7;
unsigned long pressTime = 0, releaseTime = 0, lastPressTime = 0, clearPressTime = 0;
String currentMorse = "", translatedText = "";
const int debounceDelay = 50, longPressDuration = 500;
char* morseLetters[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char* morseNumbers[] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};
char numbers[] = "0123456789";


// --- الدوال الأساسية ---
void setup() {
  Serial.begin(115200);
  delay(1000); // تأخير بسيط لبدء التشغيل
  Serial.println("\nStarting Morse Translator Project...");

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi network: ");
  Serial.println(ssid);

  int attempt = 0;
  while (WiFi.status() != WL_CONNECTED && attempt < 20) { // حاول لمدة 10 ثواني
    delay(500);
    Serial.print(".");
    attempt++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi Connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nFailed to connect to WiFi. Please check SSID and Password.");
  }

  Wire.begin(26, 25);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(clearButtonPin, INPUT_PULLUP);
  pinMode(sendButtonPin, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();
  if (WiFi.status() == WL_CONNECTED) {
    lcd.setCursor(0, 0);
    lcd.print(WiFi.localIP());
    lcd.setCursor(0, 1);
    lcd.print("Ready.");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("WiFi Error");
    lcd.setCursor(0, 1);
    lcd.print("Check Serial Mon");
  }

  server.on("/", handleRoot);
  server.on("/translate", handleTranslate);
  server.begin();
  Serial.println("Web Server started.");
}

void loop() {
  server.handleClient();
  // باقي وظائف الأزرار سيتم تجاهلها مؤقتاً للتركيز على المشكلة الأساسية
  // handleClearButton();
  // handleSendButton();
  // handleMorseInput();
}

// دالة لمعالجة طلب الترجمة من الويب (كلمة بكلمة)
void handleTranslate() {
  if (server.hasArg("text")) {
    String inputText = server.arg("text");
    Serial.println("Received sentence to translate: " + inputText);
    server.send(200, "text/html", "<h1>Playing your message...</h1><a href='/'>Go Back</a>");

    int startIndex = 0;
    bool lastWord = false;

    while (!lastWord) {
      int spaceIndex = inputText.indexOf(' ', startIndex);
      String currentWord;

      if (spaceIndex == -1) {
        currentWord = inputText.substring(startIndex);
        lastWord = true;
      } else {
        currentWord = inputText.substring(startIndex, spaceIndex);
      }
      startIndex = spaceIndex + 1;
      currentWord.trim();
      if (currentWord.length() > 0) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Playing:");
        lcd.setCursor(0, 1);
        lcd.print(currentWord);
        String morseForWord = textToMorse(currentWord);
        playMorse(morseForWord);
        if (!lastWord) {
          delay(wordGap);
        }
      }
    }
    delay(1500);
    updateDisplay();
  } else {
    server.send(400, "text/plain", "Bad Request");
  }
}

// دالة لعرض الصفحة الرئيسية مع فورم الإدخال
void handleRoot() {
  String html = "<!DOCTYPE html><html><head><title>ESP32 Morse</title>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
  html += "<style>body{font-family: sans-serif; text-align: center;} form{margin: 20px auto; max-width: 400px;}";
  html += "input[type=text]{width: 90%; padding: 10px; margin-bottom: 10px;}";
  html += "input[type=submit]{width: 95%; padding: 10px; background-color: #28a745; color: white; border: none;}</style></head><body>";
  html += "<h1>Translate Text to Morse</h1>";
  html += "<form action='/translate' method='GET'>";
  html += "<input type='text' name='text' placeholder='Enter text here...' required>";
  html += "<input type='submit' value='Translate & Play'>";
  html += "</form></body></html>";
  server.send(200, "text/html", html);
}

// --- الدوال المساعدة (بدون تغيير) ---
void playMorse(String morseCode) {
    for (int i = 0; i < morseCode.length(); i++) {
        char c = morseCode.charAt(i);
        if (c == '.') {
            digitalWrite(ledPin, HIGH);
            tone(buzzerPin, 1000, dotTime);
            delay(dotTime);
            digitalWrite(ledPin, LOW);
            delay(dotTime);
        } else if (c == '-') {
            digitalWrite(ledPin, HIGH);
            tone(buzzerPin, 1000, dashTime);
            delay(dashTime);
            digitalWrite(ledPin, LOW);
            delay(dotTime);
        } else if (c == ' ') {
            delay(letterGap);
        } else if (c == '/') {
            delay(wordGap);
        }
    }
}
String textToMorse(String text) {
  String morseResult = "";
  text.toUpperCase();
  for (int i = 0; i < text.length(); i++) {
    char character = text.charAt(i);
    if (character == ' ') { morseResult += "/ "; }
    else if (character >= 'A' && character <= 'Z') { morseResult += morseLetters[character - 'A']; morseResult += " "; }
    else if (character >= '0' && character <= '9') { morseResult += morseNumbers[character - '0']; morseResult += " "; }
  }
  return morseResult;
}
void updateDisplay() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(WiFi.localIP());
  lcd.setCursor(0, 1);
  lcd.print("Ready.");
}
// باقي الدوال غير مستخدمة حالياً للتركيز على التشخيص
void sendWhatsAppMessage(String message) {}
void handleClearButton() {}
void handleSendButton() {}
void handleMorseInput() {}
void translateMorse() {}