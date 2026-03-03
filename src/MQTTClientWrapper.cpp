#include "MQTTClientWrapper.hpp"

MQTTClientWrapper::MQTTClientWrapper(const std::string& broker, const std::string& clientId)
    : client(broker, clientId)
{
    connOpts.set_clean_session(true);
}

void MQTTClientWrapper::connect() {
    client.connect(connOpts)->wait();
}

void MQTTClientWrapper::publish(const std::string& topic, const std::string& payload) {
    auto msg = mqtt::make_message(topic, payload);
    msg->set_qos(1);
    client.publish(msg)->wait();
}

void MQTTClientWrapper::disconnect() {
    client.disconnect()->wait();
}
