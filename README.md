🚀 Features

Simulates temperature & humidity sensors

Publishes JSON payloads

Configurable broker, topic, interval

Graceful shutdown

Thread-safe publishing

🛠 Requirements

C++17

CMake 3.10+

Eclipse Paho MQTT C++ Library

Install on Ubuntu: sudo apt install libpaho-mqttpp3-dev

▶️ Build Instructions
mkdir build
cd build
cmake ..
make
./simulator

🧪 Test with Mosquitto

Run broker:mosquitto

Subscribe to topic:mosquitto_sub -h localhost -t iot/sensor/data

📈 Sample Output
{
  "sensor_id": "sensor-001",
  "temperature": 25.4,
  "humidity": 52.1
}
🧠 Architecture Overview

MQTTClientWrapper → Handles broker connection

Sensor → Generates simulated data

Simulator → Orchestrates publishing loop

main → Entry point and signal handling

🔐 Future Improvements

TLS support

Config file parsing

Multiple device simulation

QoS configuration

Docker support

Unit testing (GoogleTest)
