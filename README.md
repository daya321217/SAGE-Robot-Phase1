# SAGE-Robot-Phase1
# 🤖 SAGE: The Robot with a Mission
### (Situational Awareness & Geolocation Entity)

Welcome to the **SAGE** project! This repository marks the completion of **Phase 1**, where we’ve successfully built the "nervous system" for our autonomous defense robot. 

## 🕹️ See it in Action
I've built the entire hardware prototype in Wokwi so you can test it without needing a soldering iron. 
👉 **[Launch the Live Wokwi Simulation](https://wokwi.com/projects/463287308364428289)**

---

## 🧠 How the "Brain" Works
Instead of overloading one chip, I used a **Dual-Board Architecture**:

*   **The Muscle (Arduino Uno):** Handles the "gritty" work. It pings the sensors every few milliseconds to ensure we aren't about to hit a wall.
*   **The Voice (ESP32):** Acts as our bridge. It takes the data from the Arduino and gets it ready for the **AWS Cloud Dashboard**.

### The "Senses" (Agents)
1.  **Navigator Agent:** Uses those two ultrasonic "eyes" (front and back) to map out distances. 
2.  **EMBER/Sentinel Agent:** This is the "empathy" side. Using a PIR heat sensor, it detects when a human enters the room.
3.  **The IoT Link:** It packages all that sensor data into a neat message and sends it from the Arduino to the ESP32.

---

## 🛠️ The Tech Stack
*   **Microcontrollers:** Arduino Uno + ESP32 DevKit V1.
*   **Sensors:** 2x HC-SR04 (Ultrasonic) + 1x PIR (Motion).
*   **Communication:** UART Serial Link.

**Next Up for Phase 2:** Adding the motor drivers to get this robot moving! 🚀
