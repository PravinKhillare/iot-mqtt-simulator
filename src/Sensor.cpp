#include "Sensor.hpp"
#include <random>
#include <sstream>

Sensor::Sensor(const std::string& id) : sensorId(id) {}

std::string Sensor::generateData() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> temp(20.0, 30.0);
    std::uniform_real_distribution<> humidity(40.0, 60.0);

    std::ostringstream oss;
    oss << "{"
        << "\"sensor_id\":\"" << sensorId << "\","
        << "\"temperature\":" << temp(gen) << ","
        << "\"humidity\":" << humidity(gen)
        << "}";

    return oss.str();
}
