#include "planet.h"

Planet::Planet(std::string name, float gravityModifier)
    : name(name), gravityModifier(gravityModifier) {};

const std::string Planet::getName() const {
    return this->name;
}

void Planet::setName(std::string newName) {
    this->name = newName;
}

const float Planet::getGravity() const {
    return this->gravityModifier;
}