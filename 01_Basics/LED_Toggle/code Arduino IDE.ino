int buttonPin = 2;
int ledPin = 13;

bool ledState =false;           // الحالة الحالية لليد
bool lastButtonState = HIGH;     // آخر حالة للزرار
bool currentButtonState;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  currentButtonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && currentButtonState == LOW) {
    // الزرار اتضغط دلوقتي
    ledState = !ledState;                  // اقلب حالة الليد
    digitalWrite(ledPin, ledState);        // طبق الحالة
    delay(200);  // Delay بسيط عشان يمنع الاهتزاز (Debounce)
  }

  lastButtonState = currentButtonState;
}