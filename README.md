# ☀️ Smart IoT-Based Dual-Axis Solar Tracker & Remote Telemetry System

A smart, low-cost **IoT-enabled dual-axis solar tracking and remote environmental/electrical telemetry system** designed to maximize photovoltaic (PV) energy harvesting [1]. By continuously tracking the sun's trajectory on two axes (East-West / North-South) using 4 LDR light sensors and streaming real-time operational metrics over the **Blynk IoT Cloud**, this system increases PV panel energy output efficiency by **30%–40%** [2-4].

> 🎓 **Academic Graduation Project** — Gaza Community Training College (GTC / UNRWA) — Telecommunications Department [5].  
> 🌟 **Grade Achieved:** 97% (Excellence Award) [6].

---

## 📌 Core Features & Engineering Highlights

* **Dual-Axis Automatic Solar Tracking:** Dynamic orientation on horizontal (North/South) and vertical (East/West) axes driven by 4 LDR sensors (CDS GL5528) positioned at panel corners [2, 3, 7].
* **Dual Operating Modes (Auto / Manual):**
  * 🟢 **Automatic Mode:** Autonomous light-balancing algorithm that adjusts DC motor positions based on differential LDR light levels [8, 9].
  * 🔴 **Manual Mode (Remote Override):** Real-time remote manual directional control (Up, Down, Left, Right) via Blynk IoT virtual buttons during extreme weather or sensor maintenance [8-10].
* **Real-time Remote Telemetry (Blynk IoT & Ethernet):** Live streaming of key environmental and electrical parameters to a mobile app via Wiznet W5100 Ethernet Shield [2, 11-13].
* **On-Board Electrical & Environmental Sensing:**
  * **PV Output Voltage (\\(V_{in}\\)):** Measured via a calibrated resistor voltage divider (\\(R_1=68\text{k}\Omega, R_2=10\text{k}\Omega\\)) [13-15].
  * **PV Output Current (\\(I_{out}\\)):** Measured using an ACS712 Hall-Effect current sensor (up to 30A) [16-18].
  * **Instantaneous Generated Power (\\(P_{out}\\)):** Computed dynamically (\\(P = V \times I\\)) [18].
  * **Ambient Climate Monitoring:** Temperature and relative humidity tracking via DHT11 sensor [13, 17, 19].
* **Automated Safety Alert System:** Triggers an instant email/app notification (`Blynk.logEvent`) when ambient panel temperature exceeds 30°C to prevent thermal degradation [18, 20].

---

## 🛠️ Hardware & Software Specifications

### ⚡ Hardware Stack
* **Microcontroller:** Arduino Mega 2560 (ATmega2560 MCU running at 16MHz) [21, 22].
* **Connectivity Shield:** Arduino Ethernet Shield (Wiznet W5100 with RJ45 connector) [11, 12, 23].
* **Primary Power Generation:** Photovoltaic Solar Panel [12, 24].
* **Light Sensors:** 4× Light Dependent Resistors (LDR GL5528) [7, 25, 26].
* **Climate Sensor:** DHT11 Temperature & Humidity Sensor [17, 19, 27].
* **Current Sensor:** ACS712 Hall-Effect Sensor Module [16, 17, 28].
* **Voltage Sensing:** Custom Resistor Divider Circuit (\\(68\text{k}\Omega / 10\text{k}\Omega\\)) [14, 15].
* **Motor Driver & Actuators:** L298N Dual H-Bridge Motor Driver IC controlling 2× DC Gear Motors [3, 29-31].
* **Frame Construction:** Custom-engineered Heavy-Duty Aluminum Mechanical Rig [32, 33].

### 💻 Software & Simulation Stack
* **Programming Language:** Arduino Embedded C / C++ [34, 35].
* **IoT Cloud Platform:** Blynk IoT Server & Mobile Interface [35-37].
* **Circuit Simulation:** Proteus 8.3 Professional [26, 38].
* **Schematic & PCB Design:** Fritzing Software [39, 40].

---

## 📊 Hardware Telemetry & Mathematical Calculations

1. **Voltage Calculation Formula:**
   \[\text{Analog Value} = \text{analogRead}(A3)\]
   \[V_{out} = \frac{\text{Analog Value} \times 5.0}{1024.0}, \quad V_{in} = V_{out} \times 7.4\] [13, 14]
2. **Current Calculation Formula (ACS712):**
   \[V_{adc} = \frac{\text{ADC} \times 5.0}{1024.0}, \quad I = \frac{V_{adc} - 2.5}{0.066} \text{ (Amperes)}\] [18]
3. **Power Output Calculation:**
   \[P_{out} = V_{in} \times I \text{ (Watts)}\] [18]

---

## 🔧 Engineering Challenges & Practical Solutions

During the prototyping phase, our team encountered and resolved key physical and software engineering obstacles:
1. **Servo Motor Torque Failure:** Standard Servo motors lacked sufficient torque to support the PV panel weight ➔ Replaced with high-torque DC gear motors, integrated an L298N H-Bridge driver, and completely redesigned the motor control algorithms [32, 41].
2. **Structural Rig Stability:** Initial wooden prototype frame warped under load ➔ Redesigned and fabricated a rigid Aluminum structural chassis [32, 33].
3. **IoT Platform Migration:** Cayenne IoT platform failed to reliably drive DC motor state changes ➔ Successfully migrated the entire cloud pipeline to Blynk IoT platform [41].

---

## 📂 Repository Layout

```
IoT-Based-Solar-Tracker/
├── Solar_Tracker.ino         # Main Arduino C Embedded Source Code
├── docs/
│   └── Based Solar Tracker.pdf # Full Official Graduation Project Report
├── schematics/
│   ├── proteus_simulation.png  # Proteus 8.3 Circuit Simulations
│   └── fritzing_circuit.png   # Fritzing Wiring Diagrams
└── README.md                 # System Documentation & Overview

```

---

## 👥 Project Team & Academic Supervision

* **Student Project Leader:** Malak Elyan[1][2]
* **Development Team:** Nour Al-Saidni, Nesma Abu Masameh, Jumanah Abu Taqiyyah, Dima Al-Gharbawi, Samah Salhah[1][3]
* **Academic Supervisors:** Eng. Saad Jumaa, Eng. Mohammad Al-Aydi, Eng. Ashraf Al-Madhoun[4][5]
* **Institution:** Gaza Community Training College (GTC / UNRWA) — Telecommunications Department[1][6]

---

## 🔗 Connect with Me

* 🐙 **GitHub:** [@MalakElyan](https://www.google.com/url?sa=E&q=https%3A%2F%2Fgithub.com%2FMalakElyan)
* 💼 **LinkedIn:** [Malak Elyan](https://www.google.com/url?sa=E&q=https%3A%2F%2Fwww.linkedin.com%2Fin%2Fmalak-elyan)
* 📧 **Email:** [malakelyan02@gmail.com](https://www.google.com/url?sa=E&q=mailto%3Amalakelyan02%40gmail.com)

---

---
```
