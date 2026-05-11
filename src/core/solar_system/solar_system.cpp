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

    // this->addPlanet(std::make_unique<Planet>("Pluto", 0.06));
    // this->addPlanet(std::make_unique<Planet>("Ceres", 0.03));
    // this->addPlanet(std::make_unique<Planet>("Eris", 0.08));

    // this->addPlanet(std::make_unique<Planet>("Moon", 0.17));
    // this->addPlanet(std::make_unique<Planet>("Titan", 0.14));
    // this->addPlanet(std::make_unique<Planet>("Europa", 0.13));

    // this->addPlanet(std::make_unique<Planet>("Tatooine", 0.85));
    // this->addPlanet(std::make_unique<Planet>("Arrakis", 0.9));
    // this->addPlanet(std::make_unique<Planet>("Pandora", 0.8));
    // this->addPlanet(std::make_unique<Planet>("Krypton", 7.5));
    // this->addPlanet(std::make_unique<Planet>("Vulcan", 1.4));

    this->listPlanets();
};

void SolarSystem::listPlanets() const {
    if (this->planets.empty()) {
        std::cout << "No planets available for the system." << std::endl;

        return;
    }

    for (const std::unique_ptr<Planet>& planet : planets) {
        std::cout << planet->getName() << " - Gravity: " << planet->getGravity() << std::endl;
    }
}

void SolarSystem::addPlanet(std::unique_ptr<Planet> planet) {
    this->planets.push_back(std::move(planet));
}