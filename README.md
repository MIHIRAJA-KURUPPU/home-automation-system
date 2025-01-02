# 🌟 IoT-Based Home Automation System

![IoT](https://img.shields.io/badge/IoT-Enabled-blue) ![Platform](https://img.shields.io/badge/Platform-Node--RED-red) ![Microcontroller](https://img.shields.io/badge/Microcontroller-ESP32-orange) ![Sensors](https://img.shields.io/badge/Sensors-DHT22%2C%20BH1750-green)

## Overview 📖
This project focuses on building a **smart home automation system** using **IoT technology** to monitor and control:

- **Room Temperature**: Automatically or manually control fan speed based on temperature.
- **Light Intensity**: Adjust the brightness of lights based on ambient light levels.

The system offers a **web-based interface** for remote monitoring and control while also sending **real-time notifications** for predefined thresholds.

---

## Objectives 🎯

- **Monitor Room Temperature**: Track the temperature using the **DHT22 sensor**.
- **Fan Control**: Adjust fan speed manually through user inputs.
- **Light Control**: Manually control brightness using ambient light data from the **BH1750 sensor**.
- **Remote Access**: Control and monitor devices via an IoT platform.
- **Real-Time Notifications**: Notify users when thresholds for temperature or light levels are exceeded.

---

## System Architecture 🏗️
The system comprises:

- **ESP32 Microcontroller**: Handles communication, control, and data processing.
- **Sensors**: Monitors environmental parameters.
- **Actuators**: Controls appliances like fans and lights.
- **Node-RED Dashboard**: Provides a web interface for monitoring and control.
- **Arduino Uno**: Manages manual user inputs for light intensity control.

### Components

| **Hardware**         | **Functionality**                                          |
|----------------------|----------------------------------------------------------|
| ESP32               | Core microcontroller for sensor and device control.       |
| DHT22               | Measures temperature and humidity.                       |
| BH1750FVI           | Measures ambient light levels.                           |
| Optimus AC Dimmer   | Controls the fan speed and bulb brightness.              |
| Power Supply        | Provides 5V DC for components.                           |

| **Software**          | **Purpose**                                              |
|----------------------|----------------------------------------------------------|
| Arduino IDE         | Programming the ESP32.                                   |
| Node-RED Dashboard  | Web-based interface for monitoring and control.          |
| MQTT Protocol       | Real-time communication between devices.                 |
| IoT Platform        | Data visualization and remote control.                   |

---

## Working Principle ⚙️

1. **Sensors**:
   - The **DHT22** measures temperature and humidity.
   - The **BH1750** measures ambient light intensity.

2. **Data Processing**:
   - The ESP32 collects data from sensors.
   - Sensor data is sent to the IoT platform via MQTT.

3. **Actuation**:
   - Users receive notifications if thresholds are crossed.
   - Fans and lights are controlled manually through the Node-RED dashboard.

4. **Communication**:
   - MQTT protocol ensures seamless data exchange and control.

---

## Features 🌟

- **Real-Time Monitoring**: View temperature, humidity, and light intensity levels.
- **Manual Control**: Adjust fan speed and light brightness through the dashboard.
- **Notifications**: Receive alerts when conditions exceed thresholds.
- **Remote Access**: Control devices from anywhere using IoT platforms.
- **Energy Efficiency**: Optimizes appliance usage to save energy.

---

## How to Use 🛠️

1. **Set Up Hardware**:
   - Connect sensors (DHT22, BH1750) and actuators (AC Dimmer) to the ESP32.
   - Use Arduino Uno to manage light brightness control inputs.

2. **Program the ESP32**:
   - Write and upload the code using the Arduino IDE.

3. **Configure Node-RED**:
   - Create a web-based dashboard for monitoring and control.

4. **Connect to IoT Platform**:
   - Use MQTT to communicate between devices and the platform.

---

## Communication Protocols 📡

- **MQTT**: Facilitates real-time data exchange between sensors, actuators, and the IoT platform.
- **Node-RED**: Provides an interactive and intuitive dashboard for users.

### Example MQTT Topics:

| **Topic**               | **Purpose**                    |
|-------------------------|--------------------------------|
| `home/temperature`     | Publishes temperature data.    |
| `home/light`           | Publishes light intensity.     |
| `home/fan/control`     | Subscribes to fan commands.    |
| `home/light/control`   | Subscribes to light commands.  |

---

## System Design and Functionality 🧩

### 1. Temperature and Fan Control:
- **Sensor**: DHT22 for temperature readings.
- **Action**: Notify users if temperature exceeds threshold; manual fan speed adjustment via PWM.

### 2. Light Control:
- **Sensor**: BH1750 for ambient light measurement.
- **Action**: Notify users if light drops below threshold; manual light brightness adjustment via PWM.

---

## Node-RED Dashboard 🖥️
![Node-RED Dashboard](https://via.placeholder.com/800x400.png?text=Node-RED+Dashboard+Preview)

- **Temperature & Humidity**: Real-time graphs and data.
- **Light Levels**: Current ambient light intensity.
- **Controls**: Buttons/sliders for fan speed and light brightness.

---

## Conclusion 🏁

The **IoT-Based Home Automation System** offers a comprehensive solution for smart homes, providing:

- **Convenience** through remote control.
- **Comfort** with automated and manual adjustments.
- **Energy Efficiency** by optimizing appliance usage.

---

> “Automate your home, embrace the future.” 🚀
