#include "solar_system.h"

#include <iostream>

SolarSystem::SolarSystem() {
    this->initializeSolarSystem();
}

void SolarSystem::initializeSolarSystem() {
    this->addPlanet(std::make_unique<Planet>("Mercury", 0.38));
    this->addPlanet(std::make_unique<Planet>("Venus", 0.91));
    this->addPlanet(std::make_unique<Planet>("Earth", 1.0));
    this->addPlanet(std::make_unique<Planet>("Mars", 0.38));
    this->addPlanet(std::make_unique<Planet>("Jupiter", 2.34));
    this->addPlanet(std::make_unique<Planet>("Saturn", 1.06));
    this->addPlanet(std::make_unique<Planet>("Uranus", 0.92));
    this->addPlanet(std::make_unique<Planet>("Neptune", 1.19));
};

void SolarSystem::listPlanets() const {
    std::cout << std::endl;
    std::cout << "==============================" << std::endl;

    if (this->planets.empty()) {
        std::cout << "No planets available for the system." << std::endl;

        return;
    }

    for (const std::unique_ptr<Planet>& planet : planets) {
        std::cout << planet->getName() << " - Gravity: " << planet->getGravity() << std::endl;
    }

    std::cout << "==============================" << std::endl;
    std::cout << std::endl;
}

void SolarSystem::addPlanet(std::unique_ptr<Planet> planet) {
    this->planets.push_back(std::move(planet));
}
