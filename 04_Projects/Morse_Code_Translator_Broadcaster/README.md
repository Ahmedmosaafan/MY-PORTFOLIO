🚀 ESP32 Morse Code Translator & Broadcaster
Interactive Morse Code Project with LCD Display & Web Interface
📌 Overview
This project transforms normal text into Morse Code and broadcasts it through both LED light signals and a buzzer sound.
It also features a web-based interface hosted directly on the ESP32, allowing users to input text in real-time, which is then translated and played back as Morse signals.

This project is designed to be:

Educational → A hands-on way to learn about Morse code, IoT, and microcontrollers.
Practical → A polished project ready for portfolio or academic demonstration.
Cool & Feature-Rich → Combines hardware + software + IoT seamlessly.
⚡ Features
✅ Web interface for text input and instant translation to Morse.
✅ LCD (I2C) display showing device status and current word being played.
✅ LED + Buzzer synchronized playback of Morse code (dot/dash).
✅ Word-by-word playback with proper spacing and timing.
✅ Automatic Wi-Fi connection with IP address displayed on the LCD.
✅ Clean, modular code → easy to expand (e.g., SMS/WhatsApp notifications).

🛠 Hardware Requirements
ESP32 Development Board
16x2 I2C LCD Display
Push Buttons (optional for local input, clear, and send)
LED (for visual Morse signals)
Piezo Buzzer (for audio Morse signals)
Breadboard & jumper wires
⚙️ How It Works
Connect to Wi-Fi → ESP32 connects and shows its IP on the LCD.
Open Web Interface → Enter text into the input form.
Translation → The ESP32 translates the text into Morse code.
Playback → Morse is broadcast using LED + buzzer, word by word.
LCD Feedback → Displays current word being played or device status.
🌐 Web Interface Preview
Simple and responsive page:

Text input box
"Translate & Play" button
Real-time feedback
🚀 Future Improvements
Add WhatsApp/SMS integration for remote Morse messages.
Support for special characters & punctuation.
Mobile app to control the ESP32 remotely.
👨‍💻 Author
Developed with ❤️ using ESP32 + Arduino IDE.
