cmake_minimum_required(VERSION 3.10)
project(IoTMQTTSimulator)

set(CMAKE_CXX_STANDARD 17)

find_package(PahoMqttCpp REQUIRED)

include_directories(include)

add_executable(simulator
    src/main.cpp
    src/MQTTClientWrapper.cpp
    src/Sensor.cpp
    src/Simulator.cpp
)

target_link_libraries(simulator PahoMqttCpp::paho-mqttpp3)
