# IoT based Home Automation System

Home Automation System - IoT-based Smart Control
Overview
This project focuses on developing a smart home automation system that uses IoT (Internet of Things) technology to monitor environmental parameters such as room temperature and light levels. It automatically controls appliances like fans and lights to optimize energy usage and enhance comfort.

The system provides remote access to users through a web-based interface, where they can control devices, monitor data, and receive notifications.

Objectives
The objectives of this project are as follows:

Monitor Room Temperature: Use a temperature sensor (DHT22) to track the room's temperature.
Fan Control: Automatically adjust the fan's speed based on the room's temperature. (Controlled on the manual user inputs)
Light Control: Adjust the brightness of the bulb based on ambient light levels detected by a light sensor. (Controlled on the manual user inputs)
Remote Control: Enable remote access to the system via an IoT platform for real-time monitoring and control.
Real-Time Notifications: Send notifications when the room temperature or light levels exceed predefined thresholds.

System Architecture
The system architecture includes various components that communicate via IoT protocols. The central control is managed by an ESP32 microcontroller, which connects wirelessly to a web dashboard (Node-RED). The sensors collect environmental data, and actuators (relays) control the fan and light based on that data.

Components:
ESP32 Microcontroller: Core component responsible for communication and control.
Sensors:
DHT22 / AM2302 Digital Temperature And Humidity Sensor Module (MD0229) : Measures temperature and humidity
BH1750FVI Digital Light Intensity Sensor Module 3-5V (MD0250): Measures ambient light levels.
Optimus 4-Channel AC Dimmer Module 3.3/5VDC 230VAC (OP0137): Used for controlling the light and fan, switching them on/off as needed.
Power Supply: Provides 5V DC for the microcontroller and sensors.
Node-RED Dashboard: Web-based interface for monitoring and control.

Working Principle
The ESP32 microcontroller interfaces with sensors to monitor environmental conditions with WIFI(temperature and light).
Based on sensor data, the microcontroller controls devices such as fans and bulbs through relays.
The user can interact with the system via a web interface, making real-time adjustments and receiving notifications about the room’s conditions.
Additionally Aruino Uno board is used to controlled the user inputs to control the light intensity level.

Components and Communication Protocols

Hardware Components:
Microcontroller: ESP32 for sensor and device control.

Sensors:
DHT22: For temperature and humidity readings.
BH1750FVI: For light intensity measurements.

Actuators: 
Optimus 4-Channel AC Dimmer Module 3.3/5VDC 230VAC (OP0137)  for controlling the fan and bulb.

Software Components:
Arduino IDE: For programming the ESP32­WROOM­32 micro controller chip.
MQTT Protocol: For real-time communication between sensors, microcontroller, and the IoT platform.
IoT Platform: Adafruit IO or Blynk for remote control and data visualization.

System Design and Functionality
1. Temperature and Fan Control:
The DHT22 sensor measures the room’s temperature.
If the temperature exceeds a preset threshold, the system automatically send a notification to the user. Then the user can change the fan's speed manually. Also the user can see the temperature and humidity levels using the Node-Red dashboard.
PWM (Pulse Width Modulation) is used for controlling the fan’s speed proportionally based on the temperature.

3. Light Control:
The BH1750FVI sensor measures ambient light levels.
If the light intensity drops below a specific threshold, the system automatically automatically send a notification to the user. Then the user can change the brightness of the bulb manually. Also the user can see light levels of the environment using the Node-Red dashboard. PWM is used to control the brightness level using an Arduino Uno board.

5. IoT Communication:
The system uses MQTT protocol to communicate sensor data and control commands between devices and the IoT platform.
The ESP32 subscribes to relevant topics, allowing it to adjust devices based on real-time inputs from users or sensors.
MQTT topics are used for publishing sensor data (temperature, light levels) and receiving commands from the web dashboard.
The microcontroller subscribes to topics related to fan and light control to implement the user's commands.

How to Use
Set Up Hardware: Connect the ESP32 microcontroller to the temperature and light sensors, ac dimmer, and power supply.
Program the ESP32: Use the Arduino IDE to load the code to the ESP8266 for device control and communication via MQTT.

Conclusion
This smart home automation system is a fully functional IoT-based solution that automates temperature and light control in homes. With the ability to monitor and control devices remotely, the system ensures convenience, comfort, and energy efficiency.
