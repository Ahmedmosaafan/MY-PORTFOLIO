

// ---  Robot Settings ---
const int OBSTACLE_DISTANCE = 15; 
const int FORWARD_SPEED_A = 200;  // Right motor speed
const int FORWARD_SPEED_B = 190;  // Left motor speed (adjust for calibration)
const int TURN_SPEED = 150;
const int REVERSE_DURATION = 400;
const int TURN_DURATION = 450;


// --- Pin Definitions ---
#define IN1 9   // Right motor
#define IN2 10  // Right motor
#define IN3 11  // Left motor
#define IN4 12  // Left motor
#define ENA 5   // Right motor speed (PWM)
#define ENB 6   // Left motor speed (PWM)
#define TRIG_PIN 7
#define ECHO_PIN 8


void setup() {
  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT); pinMode(ENB, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT); pinMode(ECHO_PIN, INPUT); 

  Serial.begin(9600);
  stopMoving();
  Serial.println("Robot Ready. Place on ground to start.");
  delay(2000);
}


void loop() {
  int distance = measureDistance();
  
  if (distance <= OBSTACLE_DISTANCE && distance > 0) {
    Serial.print("Obstacle Detected at ");
    Serial.print(distance);
    Serial.println(" cm. Maneuvering...");
    performAvoidanceManeuver();
  } else {
    Serial.println("Path clear. Moving forward.");
    moveForward();
  }
  
  delay(100);
}


// --- Functions ---
int measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH, 25000);
  return duration * 0.034 / 2;
}

void performAvoidanceManeuver() {
  stopMoving();
  delay(300);
  moveBackward();
  delay(REVERSE_DURATION);
  stopMoving();
  delay(300);
  turnLeft(); 
  delay(TURN_DURATION);
  stopMoving();
  delay(300);
}

void moveForward() {
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); 
  digitalWrite(IN4, LOW);
  analogWrite(ENA, FORWARD_SPEED_A);
  analogWrite(ENB, FORWARD_SPEED_B);
}

void moveBackward() {
  digitalWrite(IN1, HIGH); 
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, TURN_SPEED);
  analogWrite(ENB, TURN_SPEED);
}

void turnRight() {
  digitalWrite(IN1, HIGH); 
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); 
  digitalWrite(IN4, LOW);
  analogWrite(ENA, TURN_SPEED);
  analogWrite(ENB, TURN_SPEED);
}

void turnLeft() {
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, TURN_SPEED);
  analogWrite(ENB, TURN_SPEED);
}

void stopMoving() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
