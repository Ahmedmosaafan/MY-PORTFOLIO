int potPin = A0;
int ledPin = 11;

// الترتيب حسب الصورة اللي بعتها
int segmentPins[] = {2, 3, 4, 5, 6, 7, 8};  // a, b, c, d, e, f, g

// تمثيل الأرقام من 0 إلى 9 على 7-Segment
byte digits[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

void setup() {
  pinMode(ledPin, OUTPUT);
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop() {
  int potValue = analogRead(potPin);       // 0 to 1023
  int brightness = map(potValue, 0, 1023, 0, 255);  // PWM for LED
  int displayValue = map(potValue, 0, 1023, 0, 9);  // Number to display

  analogWrite(ledPin, brightness);         // Control LED brightness
  displayDigit(displayValue);              // Show number on 7-segment

  delay(100);
}

void displayDigit(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digits[num][i]);
  }
}
