#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// ===== LCD =====
LiquidCrystal_I2C lcd(0x27, 16, 2); // لو الشاشة ما ظهرتش جرّب 0x3F

// ===== Keypad =====
const byte ROWS = 4; 
const byte COLS = 4; 

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// توصيل الأرجل  (R1..R4, C1..C4) 

byte rowPins[ROWS] = {2 ,3,4,5}; 
byte colPins[COLS] = { 6 ,7, 8 ,9 };
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// ===== Variables =====
String op1 = "";
String op2 = "";
char oper = '\0';
bool hasResult = false;

long toLongSafe(const String &s) {
  if (s.length() == 0) return 0;
  return s.toInt();
}

void clearAll() {
  op1 = ""; op2 = ""; oper = '\0'; hasResult = false;
  lcd.clear();
  lcd.setCursor(0,0); lcd.print("Calculator Ready");
  lcd.setCursor(0,1); lcd.print("Enter:");
}

void showCurrent() {
  String top = op1;
  if (oper != '\0') top += String(" ") + oper + String(" ") + op2;
  if (top.length() == 0) top = "Enter:";
  lcd.clear();
  lcd.setCursor(0,0); lcd.print("Calculator");
  lcd.setCursor(0,1); lcd.print(top);
}

long applyOp(long a, long b, char op, bool &ok) {
  ok = true;
  switch(op){
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
      if (b == 0) { ok = false; return 0; }
      return a / b;
  }
  ok = false; return 0;
}

void setOperator(char newOper) {
  if (op1.length() == 0) op1 = "0";
  if (oper != '\0' && op2.length() > 0) {
    bool ok; long a = toLongSafe(op1); long b = toLongSafe(op2);
    long r = applyOp(a, b, oper, ok);
    if (!ok) { lcd.clear(); lcd.print("Error"); delay(1200); clearAll(); return; }
    op1 = String(r); op2 = "";
  }
  oper = newOper; hasResult = false;
  showCurrent();
}

void doEqual() {
  if (oper == '\0' || op2.length() == 0) {
    showCurrent();
    return;
  }
  bool ok; long a = toLongSafe(op1); long b = toLongSafe(op2);
  long r = applyOp(a, b, oper, ok);
  if (!ok) { lcd.clear(); lcd.print("Div by zero"); delay(1500); clearAll(); return; }
  lcd.clear(); 
  lcd.setCursor(0,0); lcd.print("Result:");
  lcd.setCursor(0,1); lcd.print(String(r));
  op1 = String(r); op2 = ""; oper = '\0'; hasResult = true;
}

void appendDigit(char d) {
  if (hasResult && oper == '\0') {
    op1 = ""; hasResult = false;
  }
  if (oper == '\0') {
    if (op1.length() < 10) op1 += d;
  } else {
    if (op2.length() < 10) op2 += d;
  }
  showCurrent();
}

void setup() {
  lcd.init();
  lcd.backlight();
  clearAll();
}

void loop() {
  char key = keypad.getKey();
  if (!key) return;

  // خريطة الأزرار:
  if (key == 'A') { clearAll(); return; } // A = مسح
  if (key == 'B') { setOperator('+'); return; } // B = جمع
  if (key == 'C') { setOperator('-'); return; } // C = طرح
  if (key == 'D') { setOperator('*'); return; } // D = ضرب
  if (key == '*') { setOperator('/'); return; } // * = قسمة
  if (key == '#') { doEqual(); return; }       // # = يساوي

  if (key >= '0' && key <= '9') {
    appendDigit(key);
    return;
  }
}
