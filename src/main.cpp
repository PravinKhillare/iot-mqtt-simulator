#include "Simulator.hpp"
#include <csignal>
#include <memory>

std::unique_ptr<Simulator> simulator;

void signalHandler(int) {
    if (simulator)
        simulator->stop();
}

int main() {
    signal(SIGINT, signalHandler);

    simulator = std::make_unique<Simulator>(
        "tcp://localhost:1883",
        "iot/sensor/data"
    );

    simulator->run();

    return 0;
}
