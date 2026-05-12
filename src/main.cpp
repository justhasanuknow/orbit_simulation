#include "core/simulation/simulation.h"

int main() {
    Simulation::getInstance().initializeSimulation();

    Simulation::getInstance().finalizeSimulation();

    return 0;
}