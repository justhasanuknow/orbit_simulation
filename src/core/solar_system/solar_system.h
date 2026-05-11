#pragma once

#include <memory>
#include <string>
#include <vector>

#include "../planet/planet.h"

class SolarSystem {
  private:
    std::vector<std::unique_ptr<Planet>> planets{};

  public:
    SolarSystem();
    void initializeSolarSystem();
    void listPlanets() const;

    void addPlanet(std::unique_ptr<Planet> planet);
};