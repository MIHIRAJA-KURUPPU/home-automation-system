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

- **Temperature & Humidity**: Real-time graphs and data.
- **Light Levels**: Current ambient light intensity.
- **Controls**: Buttons/sliders for fan speed and light brightness.

# ESP32 Environmental Monitoring and Control System
### Software

- Arduino IDE (with ESP32 Board Support installed).
- Required Libraries:
  - **Wire.h** (for I2C communication).
  - **BH1750.h** (for light sensor control).
  - **WiFi.h** (for WiFi connectivity).
  - **PubSubClient.h** (for MQTT communication).
  - **DHT.h** (for DHT sensor control).

---

## Steps to Set Up

### 1. Install Required Libraries

Install the required libraries in the Arduino IDE:

### 2. Configure the Code

1. Open the provided code in the Arduino IDE.
2. Update the following variables with your WiFi credentials:
   ```cpp
   const char* ssid = "Your_WiFi_SSID";
   const char* password = "Your_WiFi_Password";


### 3. Connect the Hardware

#### Pin Connections:

| Component       | ESP32 Pin |
|------------------|-----------|
| **BH1750 SDA**  | GPIO 5    |
| **BH1750 SCL**  | GPIO 4    |
| **DHT-22 Signal** | GPIO 15   |
| **Fan Control** | GPIO 18   |

### 4. Upload the Code

1. Connect your ESP32 to your computer via a USB cable.
2. Open the Arduino IDE and load the project code.
3. Select the correct board and port:
   - **Tools > Board > ESP32 Dev Module**.
   - **Tools > Port > Select the appropriate COM port**.
4. Click the **Upload** button to flash the code onto the ESP32.


### 5. Monitor Serial Output

1. Open the Serial Monitor in the Arduino IDE (**Tools > Serial Monitor**).
2. Set the baud rate to **115200**.
3. Check for the following messages:
   - Successful WiFi connection.
   - MQTT connection established.
   - Sensor data being published to MQTT topics.


### 6. Test MQTT Communication

Use an MQTT client such as [MQTT.fx](https://mqttfx.jensd.de/), [MQTT Explorer](http://mqtt-explorer.com/), or an online dashboard to communicate with the ESP32.

#### Topics and Messages:

##### Subscribe:
- **Topic:** `/SensorData/Environment`
- **Data:** Environmental data (e.g., temperature, humidity, light intensity).

##### Publish:
- **Topic:** `/FanControl`
  - **Message:** `1` (to turn the fan ON).
  - **Message:** `2` (to turn the fan OFF).


### 7. Light Control (Optional)

- Use the MQTT topic to adjust light intensity.
- **Topic:** `/LightControl`
- **Message:** Send a value between `0` and `255` to control brightness


> “Automate your home, embrace the future.” 🚀
