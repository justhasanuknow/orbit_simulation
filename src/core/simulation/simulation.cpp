#include "simulation.h"

#include <iostream>

#include "../../helpers/raylib/raylib_helper.h"

void Simulation::initializeSimulation() const {
    std::cout << "\nStarting the simulation...\n" << std::endl;
    RaylibHelper::getInstance().initializeWindow();
}

void Simulation::finalizeSimulation() const {
    std::cout << "\nEnding the simulation..." << std::endl;
}