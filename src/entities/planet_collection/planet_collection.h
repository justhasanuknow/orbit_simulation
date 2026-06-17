#pragma once

#include <memory>
#include <string>
#include <vector>

#include "../planet/planet.h"

class PlanetCollection {
  private:
    std::vector<std::unique_ptr<Planet>> planets{};

  public:
    PlanetCollection();

    void listPlanets() const;

    void addPlanet(std::unique_ptr<Planet> planet);
    void addPlanet(std::string name, float gravityModifier, Coordinate position, int diameter, PlanetColor color);
    void addPlanet(std::string name, float gravityModifier, Coordinate position, int diameter, PlanetColor color, Coordinate orbitCenter,
                   float orbitRadius, float orbitSpeed, float orbitAngle);

    std::vector<std::unique_ptr<Planet>>& getPlanets();
    const std::vector<std::unique_ptr<Planet>>& getPlanets() const;
};
