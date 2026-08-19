# 🚗 Obstacle Avoiding Car

A microcontroller-based **Obstacle Avoiding Car** designed and simulated in **Proteus** using an Arduino, ultrasonic distance sensor, servo motor, and L298N motor driver.

The main objective of this project is to make the car automatically detect obstacles and choose a safer direction without requiring manual control.

## 🛠️ Components

* Arduino UNO
* HC-SR04 Ultrasonic Sensor
* SG90 Servo Motor
* L298N Motor Driver
* 4 × DC Motors
* Battery Supply
* Jumper Wires
* Proteus Design Suite

## ⚙️ Working Principle

The ultrasonic sensor measures the distance between the car and an obstacle.

The Arduino continuously checks the measured distance:

1. The car moves forward when the path is clear.
2. When an obstacle is detected, the car stops.
3. The servo motor rotates the ultrasonic sensor toward different directions.
4. The Arduino measures the distance on the left and right sides.
5. The controller compares the available distances.
6. The car turns toward the direction with more available space.
7. The car continues moving forward.

### Basic Flow

```text
          Start
            │
            ▼
      Measure Distance
            │
            ▼
     Is Path Clear?
       /          \
     Yes           No
      │             │
      ▼             ▼
   Move Forward   Stop Car
                    │
                    ▼
              Scan Left/Right
                    │
                    ▼
             Compare Distances
                    │
                    ▼
             Choose Direction
                    │
                    ▼
                  Turn
                    │
                    ▼
              Move Forward
```

## 🔌 Main Connections

### Ultrasonic Sensor

| HC-SR04 Pin | Arduino UNO |
| ----------- | ----------- |
| VCC         | 5V          |
| GND         | GND         |
| TRIG        | Digital Pin |
| ECHO        | Digital Pin |

### Servo Motor

| Servo Wire | Connection                      |
| ---------- | ------------------------------- |
| VCC        | 5V                              |
| GND        | GND                             |
| Signal     | Arduino PWM-capable Digital Pin |

### L298N Motor Driver

The L298N controls the four DC motors through its two H-bridge channels.

* ENA → Arduino
* IN1 → Arduino
* IN2 → Arduino
* IN3 → Arduino
* IN4 → Arduino
* ENB → Arduino
* Motor Supply → External motor supply
* GND → Common GND

> The exact Arduino pin assignments are defined in the Arduino source code.

## 🧪 Proteus Simulation

The complete circuit was first developed and tested in **Proteus** before considering physical implementation.

The simulation is used to verify:

* Motor control
* Ultrasonic distance measurement
* Servo scanning
* Obstacle detection
* Automatic turning logic
* Overall control algorithm



```text
Proteus/
├── proteus-schematic.png
├── simulation-running.png
├
```

## 💻 Software

* Arduino IDE
* Proteus Design Suite
* C/C++ (Arduino)

## 📁 Project Structure

```text
Obstacle-Avoiding-Car/
│
├── Proteus/
│   ├── proteus-schematic.png
│   ├── simulation-running.png
│
├── Arduino/
│   └── obstacle_avoiding_car.ino
│
└── README.md
```

## 🎯 Project Goals

* Learn Arduino-based embedded control
* Understand ultrasonic distance measurement
* Interface a servo motor with Arduino
* Control DC motors using an L298N
* Develop basic autonomous navigation logic
* Practice circuit simulation using Proteus

## 🚀 Future Improvements

* Add Bluetooth/Wi-Fi remote control
* Replace L298N with a more efficient motor driver
* Add battery voltage monitoring
* Improve obstacle detection algorithm
* Add multiple sensors for better navigation
* Build and test the physical prototype

## 👨‍💻 Author

**Solangi**

Electrical Engineering Student
Pakistan

---

⭐ This project is part of my practical learning journey in **Embedded Systems, Electronics, Arduino, and Robotics**.
