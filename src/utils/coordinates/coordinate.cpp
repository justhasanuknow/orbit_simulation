#include "coordinate.h"

Coordinate::Coordinate(Position initPosition) : position(initPosition) {}

void Coordinate::setX(float newX) {
    this->position.x = newX;
}

float Coordinate::getX() const {
    return this->position.x;
}

void Coordinate::setY(float newY) {
    this->position.y = newY;
}

float Coordinate::getY() const {
    return this->position.y;
}

void Coordinate::setPosition(Position newPosition) {
    this->position = newPosition;
}

Position Coordinate::getPosition() const {
    return this->position;
}
