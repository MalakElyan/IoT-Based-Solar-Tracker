# ☀️ Smart IoT-Based Dual-Axis Solar Tracker & Remote Telemetry System

A smart, low-cost **IoT-enabled dual-axis solar tracking and remote environmental/electrical telemetry system** designed to maximize photovoltaic (PV) energy harvesting. By continuously tracking the sun's trajectory on two axes (East-West / North-South) using 4 LDR light sensors and streaming real-time operational metrics over the **Blynk IoT Cloud**, this system increases PV panel energy output efficiency by **30%–40%**.

> 🎓 **Academic Graduation Project** — Gaza Community Training College (GTC / UNRWA) — Telecommunications Department  
> 🌟 **Grade Achieved:** 97% (Excellence Award)

---

## 📌 Core Features & Engineering Highlights

* **Dual-Axis Automatic Solar Tracking:** Dynamic orientation on horizontal (North/South) and vertical (East/West) axes driven by 4 LDR sensors (CDS GL5528) positioned at panel corners.
  
* **Dual Operating Modes (Auto / Manual):**
  * 🟢 **Automatic Mode:** Autonomous light-balancing algorithm that adjusts DC motor positions based on differential LDR light levels.
  * 🔴 **Manual Mode (Remote Override):** Real-time remote manual directional control (Up, Down, Left, Right) via Blynk IoT virtual buttons during extreme weather or sensor maintenance.
    
* **Real-time Remote Telemetry (Blynk IoT & Ethernet):** Live streaming of key environmental and electrical parameters to a mobile app via Wiznet W5100 Ethernet Shield.
  
* **On-Board Electrical & Environmental Sensing:**
  * **PV Output Voltage ($V_{in}$):** Measured via a calibrated resistor voltage divider ($R_1=68\text{k}\Omega, R_2=10\text{k}\Omega$).
  * **PV Output Current ($I_{out}$):** Measured using an ACS712 Hall-Effect current sensor (up to 30A).
  * **Instantaneous Generated Power ($P_{out}$):** Computed dynamically ($P = V \times I$).
  * **Ambient Climate Monitoring:** Temperature and relative humidity tracking via DHT11 sensor.
* **Automated Safety Alert System:** Triggers an instant email/app notification (`Blynk.logEvent`) when ambient panel temperature exceeds 30°C to prevent thermal degradation.

---

## 🛠️ Hardware & Software Specifications

### ⚡ Hardware Stack
* **Microcontroller:** Arduino Mega 2560 (ATmega2560 MCU running at 16MHz)
* **Connectivity Shield:** Arduino Ethernet Shield (Wiznet W5100 with RJ45 connector)
* **Primary Power Generation:** Photovoltaic Solar Panel
* **Light Sensors:** 4× Light Dependent Resistors (LDR GL5528)
* **Climate Sensor:** DHT11 Temperature & Humidity Sensor
* **Current Sensor:** ACS712 Hall-Effect Sensor Module
* **Voltage Sensing:** Custom Resistor Divider Circuit ($68\text{k}\Omega / 10\text{k}\Omega$)
* **Motor Driver & Actuators:** L298N Dual H-Bridge Motor Driver IC controlling 2× DC Gear Motors
* **Frame Construction:** Custom-engineered Heavy-Duty Aluminum Mechanical Rig

### 💻 Software & Simulation Stack
* **Programming Language:** Arduino Embedded C / C++
* **IoT Cloud Platform:** Blynk IoT Server & Mobile Interface
* **Circuit Simulation:** Proteus 8.3 Professional
* **Schematic & PCB Design:** Fritzing Software

---

## 📊 Hardware Telemetry & Mathematical Calculations

### 1. Voltage Calculation Formula
$$\text{Analog Value} = \text{analogRead}(A3)$$
$$V_{out} = \frac{\text{Analog Value} \times 5.0}{1024.0}, \quad V_{in} = V_{out} \times 7.4$$

### 2. Current Calculation Formula (ACS712)
$$V_{adc} = \frac{\text{ADC} \times 5.0}{1024.0}, \quad I = \frac{V_{adc} - 2.5}{0.066} \text{ (Amperes)}$$

### 3. Power Output Calculation
$$P_{out} = V_{in} \times I \text{ (Watts)}$$

---

## 🔧 Engineering Challenges & Practical Solutions

During the prototyping phase, our team encountered and resolved key physical and software engineering obstacles:

1. **Servo Motor Torque Failure:** Standard Servo motors lacked sufficient torque to support the PV panel weight $\rightarrow$ Replaced with high-torque DC gear motors, integrated an L298N H-Bridge driver, and completely redesigned the motor control algorithms.
2. **Structural Rig Stability:** Initial wooden prototype frame warped under load $\rightarrow$ Redesigned and fabricated a rigid Aluminum structural chassis.
3. **IoT Platform Migration:** Cayenne IoT platform failed to reliably drive DC motor state changes $\rightarrow$ Successfully migrated the entire cloud pipeline to Blynk IoT platform.

---

## 📂 Repository Layout

```text
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

* **Student Project Leader:** Malak Elyan
* **Development Team:** Nour Al-Saidni, Nesma Abu Masameh, Jumanah Abu Taqiyyah, Dima Al-Gharbawi, Samah Salhah
* **Academic Supervisors:** Eng. Saad Jumaa, Eng. Mohammad Al-Aydi, Eng. Ashraf Al-Madhoun.
* **Institution:** Gaza Community Training College (GTC / UNRWA) — Telecommunications Department

---

## 🔗 Connect with Me

* 🐙 **GitHub:** [@MalakElyan](https://github.com/MalakElyan)
* 💼 **LinkedIn:** [Malak Elyan](https://www.linkedin.com/in/malak-elyan)

---

© 2026 Smart IoT Solar Tracker Project. All rights reserved.

