#pragma once

#include "raylib.h"

class PlanetCollection;
class Planet;
struct PlanetColor;

class RaylibHelper {
  private:
    RaylibHelper() = default;
    ~RaylibHelper() = default;
    const float ballRadius = 20;
    void updatePlanets(PlanetCollection& planets, float deltaTime, float speedMultiplier) const;
    void drawPlanets(const PlanetCollection& planets) const;
    void drawOrbitPaths(const PlanetCollection& planets) const;
    float drawSpeedSlider(float currentSpeed) const;
    Color getRaylibColor(PlanetColor planetColor) const;

  public:
    static RaylibHelper& getInstance() {
        static RaylibHelper instance;
        return instance;
    }

    RaylibHelper(const RaylibHelper&) = delete;
    RaylibHelper& operator=(const RaylibHelper&) = delete;

    void initializeWindow() const;
    Vector2 getRandomCoordinates() const;
};
