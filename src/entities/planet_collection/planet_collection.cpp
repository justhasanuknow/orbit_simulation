#include "planet_collection.h"

#include <iostream>

PlanetCollection::PlanetCollection() = default;

void PlanetCollection::listPlanets() const {
    std::cout << std::endl;
    std::cout << "==============================" << std::endl;

    if (this->planets.empty()) {
        std::cout << "No planets available." << std::endl;

        return;
    }

    for (const std::unique_ptr<Planet>& planet : planets) {
        std::cout << planet->getName() << " - Gravity: " << planet->getGravity()
                  << " - Diameter: " << planet->getDiameter() << std::endl;
    }

    std::cout << "==============================" << std::endl;
    std::cout << std::endl;
}

void PlanetCollection::addPlanet(std::unique_ptr<Planet> planet) {
    this->planets.push_back(std::move(planet));
}

void PlanetCollection::addPlanet(std::string name, float gravityModifier, Coordinate position, int diameter, PlanetColor color) {
    this->addPlanet(std::make_unique<Planet>(name, gravityModifier, position, diameter, color));
}

void PlanetCollection::addPlanet(std::string name, float gravityModifier, Coordinate position, int diameter, PlanetColor color,
                                 Coordinate orbitCenter, float orbitRadius, float orbitSpeed, float orbitAngle) {
    this->addPlanet(std::make_unique<Planet>(name, gravityModifier, position, diameter, color, true, orbitCenter, orbitRadius,
                                             orbitSpeed, orbitAngle));
}

std::vector<std::unique_ptr<Planet>>& PlanetCollection::getPlanets() {
    return this->planets;
}

const std::vector<std::unique_ptr<Planet>>& PlanetCollection::getPlanets() const {
    return this->planets;
}
