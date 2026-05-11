#include <memory>

#include "core/simulation/simulation.h"
#include "core/solar_system/solar_system.h"

int main() {
    Simulation::getInstance().initializeSimulation();

    const std::unique_ptr<SolarSystem> solarSystem{new SolarSystem()};

    Simulation::getInstance().finalizeSimulation();

    return 0;
}