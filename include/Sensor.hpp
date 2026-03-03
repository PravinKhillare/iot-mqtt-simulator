#pragma once
#include <string>

class Sensor {
public:
    Sensor(const std::string& id);
    std::string generateData();

private:
    std::string sensorId;
};
