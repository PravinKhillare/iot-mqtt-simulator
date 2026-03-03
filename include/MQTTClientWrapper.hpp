#pragma once
#include <mqtt/async_client.h>
#include <string>

class MQTTClientWrapper {
public:
    MQTTClientWrapper(const std::string& broker, const std::string& clientId);
    void connect();
    void publish(const std::string& topic, const std::string& payload);
    void disconnect();

private:
    mqtt::async_client client;
    mqtt::connect_options connOpts;
};
