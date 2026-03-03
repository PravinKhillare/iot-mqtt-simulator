#pragma once
#include "MQTTClientWrapper.hpp"
#include "Sensor.hpp"
#include <atomic>

class Simulator {
public:
    Simulator(const std::string& broker, const std::string& topic);
    void run();
    void stop();

private:
    MQTTClientWrapper mqtt;
    Sensor sensor;
    std::string topic;
    std::atomic<bool> running;
};
