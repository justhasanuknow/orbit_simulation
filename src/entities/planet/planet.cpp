#include "planet.h"

#include <cmath>

Planet::Planet(std::string name, float gravityModifier, Coordinate position, int diameter, PlanetColor color, bool orbitEnabled,
               Coordinate orbitCenter, float orbitRadius, float orbitSpeed, float orbitAngle)
    : name(name), gravityModifier(gravityModifier), diameter(diameter), position(position), color(color), orbitEnabled(orbitEnabled),
      orbitCenter(orbitCenter), orbitRadius(orbitRadius), orbitSpeed(orbitSpeed), orbitAngle(orbitAngle) {};

const std::string Planet::getName() const {
    return this->name;
}

void Planet::setName(std::string newName) {
    this->name = newName;
}

const float Planet::getGravity() const {
    return this->gravityModifier;
}

void Planet::setDiameter(int newDiameter) {
    this->diameter = newDiameter;
}

int Planet::getDiameter() const {
    return this->diameter;
}

void Planet::setColor(PlanetColor newColor) {
    this->color = newColor;
}

PlanetColor Planet::getColor() const {
    return this->color;
}

void Planet::setX(float newX) {
    this->position.setX(newX);
}

float Planet::getX() const {
    return this->position.getX();
}

void Planet::setY(float newY) {
    this->position.setY(newY);
}

float Planet::getY() const {
    return this->position.getY();
}

void Planet::setPosition(Coordinate newPosition) {
    this->position = newPosition;
}

Coordinate Planet::getPosition() const {
    return this->position;
}

void Planet::setOrbit(Coordinate center, float radius, float speed, float angle) {
    this->orbitEnabled = true;
    this->orbitCenter = center;
    this->orbitRadius = radius;
    this->orbitSpeed = speed;
    this->orbitAngle = angle;
}

void Planet::setOrbitCenter(Coordinate center) {
    this->orbitCenter = center;
}

bool Planet::hasOrbit() const {
    return this->orbitEnabled;
}

Coordinate Planet::getOrbitCenter() const {
    return this->orbitCenter;
}

float Planet::getOrbitRadius() const {
    return this->orbitRadius;
}

float Planet::getOrbitSpeed() const {
    return this->orbitSpeed;
}

void Planet::updateOrbit(float deltaTime, float speedMultiplier) {
    if (!this->orbitEnabled) {
        return;
    }

    this->orbitAngle += this->orbitSpeed * speedMultiplier * deltaTime;

    const float x = this->orbitCenter.getX() + std::cos(this->orbitAngle) * this->orbitRadius;
    const float y = this->orbitCenter.getY() + std::sin(this->orbitAngle) * this->orbitRadius;

    this->setPosition(Coordinate({x, y}));
}
