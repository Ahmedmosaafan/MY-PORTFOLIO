#include <PS4Controller.h>

// تعريف أطراف المحركات
#define ENA 33
#define IN1 14
#define IN2 27
#define ENB 12
#define IN3 26
#define IN4 25

#define LED_BUILTIN 2

// متغيرات المعايرة لضبط السرعة
float rightMotorCalibration = 0.95;  // عامل تصحيح المحرك الأيمن (1.0 = 100%)
float leftMotorCalibration = 1.0;   // عامل تصحيح المحرك الأيسر (1.0 = 100%)

// --- دوال الحركة التي طلبتها أنت بالضبط ---
void goForward() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void goBackward() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}

void turnLeft() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}

void turnRight() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void stopMotors() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
}
// --- نهاية دوال الحركة الخاصة بك ---


void setup() {
  Serial.begin(115200);
  
  pinMode(ENA, OUTPUT); pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT); pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  PS4.begin("D8:BC:38:FA:98:9E"); 
  Serial.println("Ready to connect to PS4 Controller.");
}

void loop() {
  if (PS4.isConnected()) {
    digitalWrite(LED_BUILTIN, HIGH);

    int stickY = PS4.LStickY();
    int stickX = PS4.LStickX();

    // حساب السرعة بناءً على مدى ميل العصا
    int forwardSpeed = map(stickY, 0, 127, 100, 255);
    int backwardSpeed = map(abs(stickY), 0, 128, 100, 255);
    int turnSpeed = map(abs(stickX), 0, 128, 150, 255);

    // تطبيق المعايرة على السرعات
    analogWrite(ENA, 255 * rightMotorCalibration);
    analogWrite(ENB, 255 * leftMotorCalibration);


    // منطق التحكم المباشر الذي يستدعي دوالك الخاصة
    if (stickY > 50) {
      goForward();
    } 
    else if (stickY < -50) {
      goBackward();
    }
    else if (stickX < -50) {
      turnLeft();
    }
    else if (stickX > 50) {
      turnRight();
    }
    else {
      stopMotors();
    }
  } 
  else {
    digitalWrite(LED_BUILTIN, LOW);
    stopMotors();
  }
  delay(50);
}