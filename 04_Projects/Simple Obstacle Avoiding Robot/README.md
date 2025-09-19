# 🦾 Simple Obstacle Avoiding Robot  

An autonomous robot built with Arduino that can detect and avoid obstacles using an ultrasonic sensor. The robot moves forward, avoids collisions by reversing and turning, and keeps navigating smoothly without human control.  

---

# 🚀 Features  
- Forward movement with adjustable speed for each motor.  
- Obstacle detection using **HC-SR04 ultrasonic sensor**.  
- Automatic maneuvers: reverse, turn left/right, and stop.  
- Debugging messages via **Serial Monitor**.  

---

# 🛠️ Components Required  
- Arduino UNO (or compatible board)  
- L298N Motor Driver (or dual H-bridge driver)  
- 2 DC Motors with wheels  
- HC-SR04 Ultrasonic Sensor  
- Robot chassis & power supply (battery pack)  
- Jumper wires  

---

# 🔌 Circuit Connections  

| Component            | Arduino Pin |
|----------------------|-------------|
| Motor A (IN1, IN2)   | 9, 10       |
| Motor B (IN3, IN4)   | 11, 12      |
| Motor A Enable (ENA) | 5 (PWM)     |
| Motor B Enable (ENB) | 6 (PWM)     |
| Ultrasonic TRIG      | 7           |
| Ultrasonic ECHO      | 8           |

---

# 💻 How to Use  
1. Connect the components as per the circuit above.  
2. Upload the code to your Arduino using the Arduino IDE.  
3. Open **Serial Monitor** at 9600 baud to view status messages.  
4. Place the robot on the ground — it will start moving forward and avoid obstacles.  

---

# ⚙️ Code Overview  
- **`measureDistance()`** → Reads distance from ultrasonic sensor.  
- **`performAvoidanceManeuver()`** → Reverses and turns to avoid obstacles.  
- **`moveForward() / moveBackward() / turnLeft() / turnRight() / stopMoving()`** → Motor control functions.  
- **`loop()`** → Main logic:
  - If obstacle is detected → Avoidance maneuver.  
  - Else → Keep moving forward.  

---

# 📈 Future Improvements  
- Add **IR sensor** for edge detection.  
- Add servo motor to rotate ultrasonic sensor for wider detection.  
- Implement PID control for smoother motor speed.  
- Use rechargeable Li-ion batteries with TP4056 charging module.  
- Add Bluetooth/Wi-Fi for manual control option.


## 📸 Demo
![Robot Demo](REAL_LIFE%20PHOTO.jpg)
