#include <Wire.h>
#include <BH1750.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"

#if defined(ESP32)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif 

// BH1750 light sensor initialization
BH1750 lightMeter;

// DHT-22 sensor initialization
#define FanPin 18   
#define DHTPIN 15    // Pin where the DHT sensor is connected
#define DHTTYPE DHT22 // Define the type of DHT sensor
DHT dht(DHTPIN, DHTTYPE);

// WiFi and MQTT Configuration
const char* ssid = "Chandi";                // Change to your WiFi SSID
const char* password = "12345678";          // Change to your WiFi Password
const char* mqtt_server = "test.mosquitto.org"; // MQTT Broker URL

WiFiClient espClient;
PubSubClient client(espClient);

// MQTT topics
const char* sensorTopic = "/SensorData/Environment";
const char* fanControlTopic = "/FanControl";
const char* sliderTopic = "/LightControl"; 

// Define min and max lux values for normalization
const float minLux = 0.0;   // Minimum expected lux (darkness)
const float maxLux = 50.0; // Maximum expected lux (bright light)

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void mqttCallback(char* topic, byte* payload, unsigned int length) { 
    // Convert payload to string
    String message;
    for (unsigned int i = 0; i < length; i++) {
        message += (char)payload[i];
    }
    message.trim(); // Remove any trailing whitespace

    //Serial.print("Message arrived [");
    //Serial.print(topic);
    //Serial.print("]: ");
    //Serial.println(message);

    // Handle messages based on topic
    if (strcmp(topic, fanControlTopic) == 0) {
        // Fan Control Logic
        if (message == "1") { 
            digitalWrite(FanPin, HIGH); 
            //Serial.println("Fan turned ON");
        }
        else if (message == "2") { 
            digitalWrite(FanPin, LOW); 
            //Serial.println("Fan turned OFF");
        }
        else {
            //Serial.println("Unknown command for FanControl");
        }
    }
    else if (strcmp(topic, sliderTopic) == 0) {
        // Light Control via Slider
        int sliderValue = message.toInt();  // Convert the string to an integer
        if (sliderValue >= 0 && sliderValue <= 100) {
            //Serial.print("Received slider value: ");
            Serial.println(sliderValue);
       
        else {
            //Serial.println("Slider value out of range (0-100)");
        }
    }
    else {
        //Serial.println("Received message on unknown topic");
    }
}

void reconnect() {
  while (!client.connected()) {
    //Serial.println("Attempting MQTT connection...");

    // Attempt to connect
    if (client.connect("ESP_LightSensor")) {
      //Serial.println("Connected to MQTT broker");
      // Subscribe to necessary topics
      client.subscribe(fanControlTopic);
      client.subscribe(sliderTopic);
    } else {
      //Serial.print("Failed, rc=");
      //Serial.print(client.state());
      //Serial.println(" trying again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  Serial.begin(9600);
  // No need for 'while (!Serial);' on most boards, it can block indefinitely
  pinMode(FanPin, OUTPUT);
  digitalWrite(FanPin, LOW); // Ensure fan is off initially
  delay(100);

  // Initialize I2C
  Wire.begin(5, 4); // SDA=5, SCL=4
  delay(100);

  // Initialize BH1750
  if (lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE, 0x23)) {
    //Serial.println(F("BH1750 initialized successfully"));
  } else {
    //Serial.println(F("Error initializing BH1750. Check wiring or I2C address."));
  }

  // Initialize DHT sensor
  dht.begin(); // Initialize the DHT sensor

  // Set up WiFi and MQTT
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(mqttCallback); // Set the unified callback
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Read light level from BH1750
  float lux = lightMeter.readLightLevel();

  // Read temperature and humidity from DHT-22
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    //Serial.println("Failed to read from DHT sensor!");
    return;
  }

  if (lux >= 0) {
    // Normalize lux to a percentage
    float normalizedPercentage = ((lux - minLux) / (maxLux - minLux)) * 100.0;
    normalizedPercentage = constrain(normalizedPercentage, 0.0, 100.0);

    // Print the values to Serial Monitor
    //Serial.print("Light: ");
    //Serial.print(lux);
    //Serial.println(" lx");
    //Serial.print("Normalized Percentage: ");
    //Serial.print(normalizedPercentage);
    //Serial.println(" %");
    //Serial.print("Humidity: ");
    //Serial.print(humidity);
    //Serial.print(" %\t");
    //Serial.print("Temperature: ");
    //Serial.print(temperature);
    //Serial.println(" *C");

    // Create JSON payload
    char jsonPayload[150]; // Increased size for safety
    snprintf(jsonPayload, sizeof(jsonPayload), 
             "{\"light\": %.2f, \"percentage\": %.2f, \"temperature\": %.2f, \"humidity\": %.2f}", 
             lux, normalizedPercentage, temperature, humidity);

    // Publish JSON to MQTT
    if (client.publish(sensorTopic, jsonPayload)) {
      //Serial.println("Sensor data published successfully");
    } else {
      //Serial.println("Failed to publish sensor data");
    }
  } else {
    //Serial.println("Error reading light level");
  }

  // Delay for 1 second
  delay(1000); // Use delay instead of vTaskDelay for simplicity
}
