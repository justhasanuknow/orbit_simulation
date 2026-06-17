#pragma once
#include <string>

#include "../../utils/coordinates/coordinate.h"

struct PlanetColor {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

class Planet {
  private:
    std::string name = "";
    float gravityModifier = 1.0;
    int diameter = 1;
    Coordinate position;
    PlanetColor color{255, 255, 255, 255};
    bool orbitEnabled = false;
    Coordinate orbitCenter{Position{0.0f, 0.0f}};
    float orbitRadius = 0.0f;
    float orbitSpeed = 0.0f;
    float orbitAngle = 0.0f;

  protected:
  public:
    Planet(std::string name, float gravityModifier, Coordinate position = Coordinate({0.0f, 0.0f}), int diameter = 1,
           PlanetColor color = PlanetColor{255, 255, 255, 255}, bool orbitEnabled = false,
           Coordinate orbitCenter = Coordinate({0.0f, 0.0f}), float orbitRadius = 0.0f, float orbitSpeed = 0.0f,
           float orbitAngle = 0.0f);

    const std::string getName() const;
    void setName(std::string newName);

    const float getGravity() const;

    void setX(float newX);
    float getX() const;

    void setY(float newY);
    float getY() const;

    void setDiameter(int newDiameter);
    int getDiameter() const;

    void setColor(PlanetColor newColor);
    PlanetColor getColor() const;

    void setPosition(Coordinate newPosition);
    Coordinate getPosition() const;

    void setOrbit(Coordinate center, float radius, float speed, float angle);
    void setOrbitCenter(Coordinate center);
    bool hasOrbit() const;
    Coordinate getOrbitCenter() const;
    float getOrbitRadius() const;
    float getOrbitSpeed() const;
    void updateOrbit(float deltaTime, float speedMultiplier);
};
