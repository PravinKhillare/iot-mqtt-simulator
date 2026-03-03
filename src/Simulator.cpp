#include "Simulator.hpp"
#include <thread>
#include <chrono>

Simulator::Simulator(const std::string& broker, const std::string& topic)
    : mqtt(broker, "IoTSimulatorClient"),
      sensor("sensor-001"),
      topic(topic),
      running(true)
{}

void Simulator::run() {
    mqtt.connect();

    while (running) {
        std::string payload = sensor.generateData();
        mqtt.publish(topic, payload);
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    mqtt.disconnect();
}

void Simulator::stop() {
    running = false;
}
