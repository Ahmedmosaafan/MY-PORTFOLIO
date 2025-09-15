# ESP32 Morse Code Translator & Broadcaster

This project converts normal text into **Morse Code** and broadcasts it using a **buzzer + LED**.  
It also provides a **web interface** hosted on the ESP32 for real-time input and translation.  

---

## ⚡ Features
- Web interface for entering text  
- LCD display (I2C) shows current word and device status  
- LED + Buzzer playback of Morse code (dot/dash)  
- Wi-Fi connection with IP shown on the LCD  
- Easy to expand (e.g., WhatsApp/SMS integration)  

---

## 🛠 Hardware Used
- ESP32 Development Board  
- 16x2 I2C LCD Display  
- LED  
- Piezo Buzzer  
- Breadboard + jumper wires  

---

## 🚀 How to Run
1. Clone the project or copy the `.ino` file into Arduino IDE  
2. Update your Wi-Fi **SSID** and **Password** in the code  
3. Upload the code to your ESP32 board  
4. Open Serial Monitor or LCD to see the ESP32 IP  
5. Visit the IP in your browser → type a message → watch it play in Morse code!  


---

## 👨‍💻 Author
Developed with ❤️ using **ESP32 + Arduino IDE**  
