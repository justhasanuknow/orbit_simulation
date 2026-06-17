#include "raylib_helper.h"

#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>

#include "../../entities/planet_collection/planet_collection.h"
#include "raylib.h"

void RaylibHelper::initializeWindow() const {
    const int windowWidth = 1600;
    const int windowHeight = 720;

    InitWindow(windowWidth, windowHeight, "Planet Simulation");

    SetTargetFPS(144);

    const std::unique_ptr<PlanetCollection> planets{new PlanetCollection()};
    const Coordinate sunPosition({800.0f, 360.0f});
    float simulationSpeed = 1.0f;

    planets->addPlanet("Sun", 27.94f, sunPosition, 110, PlanetColor{255, 205, 50, 255});
    planets->addPlanet("Mercury", 0.38f, Coordinate({890.0f, 360.0f}), 14, PlanetColor{140, 140, 140, 255}, sunPosition, 90.0f,
                       1.45f, 0.0f);
    planets->addPlanet("Venus", 0.91f, Coordinate({940.0f, 360.0f}), 24, PlanetColor{255, 203, 82, 255}, sunPosition, 140.0f,
                       0.57f, 0.0f);
    planets->addPlanet("Earth", 1.0f, Coordinate({995.0f, 360.0f}), 26, PlanetColor{75, 142, 255, 255}, sunPosition, 195.0f,
                       0.35f, 0.0f);
    planets->addPlanet("Mars", 0.38f, Coordinate({1050.0f, 360.0f}), 18, PlanetColor{225, 80, 60, 255}, sunPosition, 250.0f,
                       0.19f, 0.0f);
    planets->addPlanet("Jupiter", 2.34f, Coordinate({1130.0f, 360.0f}), 58, PlanetColor{218, 154, 91, 255}, sunPosition,
                       330.0f, 0.055f, 0.0f);
    planets->addPlanet("Saturn", 1.06f, Coordinate({1210.0f, 360.0f}), 50, PlanetColor{210, 184, 120, 255}, sunPosition,
                       410.0f, 0.022f, 0.0f);
    planets->addPlanet("Uranus", 0.92f, Coordinate({1300.0f, 360.0f}), 36, PlanetColor{110, 220, 230, 255}, sunPosition,
                       500.0f, 0.0076f, 0.0f);
    planets->addPlanet("Neptune", 1.19f, Coordinate({1390.0f, 360.0f}), 34, PlanetColor{70, 100, 220, 255}, sunPosition,
                       590.0f, 0.0039f, 0.0f);

    planets->listPlanets();

    while (!WindowShouldClose()) {
        const float deltaTime = GetFrameTime();
        this->updatePlanets(*planets, deltaTime, simulationSpeed);

        BeginDrawing();

        ClearBackground(BLACK);

        DrawFPS(10, 10);
        DrawText("Planet Simulation", 620, 40, 36, RAYWHITE);

        this->drawOrbitPaths(*planets);
        this->drawPlanets(*planets);
        simulationSpeed = this->drawSpeedSlider(simulationSpeed);

        EndDrawing();
    }

    CloseWindow();
}

Vector2 RaylibHelper::getRandomCoordinates() const {
    srand(time(0));

    const int width = GetScreenWidth();
    const int height = GetScreenHeight();

    const float randomWidth = rand() % (width + 1);
    const float randomHeight = rand() % (height + 1);

    std::cout << "Random Coordinate: " << randomWidth << " - " << randomHeight << std::endl;

    const Vector2 coordinates{randomWidth, randomHeight};

    return coordinates;
}

void RaylibHelper::updatePlanets(PlanetCollection& planets, float deltaTime, float speedMultiplier) const {
    for (const std::unique_ptr<Planet>& planet : planets.getPlanets()) {
        planet->updateOrbit(deltaTime, speedMultiplier);
    }
}

void RaylibHelper::drawOrbitPaths(const PlanetCollection& planets) const {
    for (const std::unique_ptr<Planet>& planet : planets.getPlanets()) {
        if (!planet->hasOrbit()) {
            continue;
        }

        const Coordinate orbitCenter = planet->getOrbitCenter();
        DrawCircleLines(static_cast<int>(orbitCenter.getX()), static_cast<int>(orbitCenter.getY()), planet->getOrbitRadius(),
                        Color{100, 100, 100, 120});
    }
}

void RaylibHelper::drawPlanets(const PlanetCollection& planets) const {
    for (const std::unique_ptr<Planet>& planet : planets.getPlanets()) {
        const float radius = planet->getDiameter() / 2.0f;
        const float x = planet->getX();
        const float y = planet->getY();
        const Color planetColor = this->getRaylibColor(planet->getColor());

        DrawCircle(static_cast<int>(x), static_cast<int>(y), radius, planetColor);
        DrawCircleLines(static_cast<int>(x), static_cast<int>(y), radius, RAYWHITE);

        const std::string label = planet->getName();
        const float labelWidth = MeasureText(label.c_str(), 16);

        DrawText(label.c_str(), static_cast<int>(x - labelWidth / 2), static_cast<int>(y + radius + 12), 16, RAYWHITE);
    }
}

float RaylibHelper::drawSpeedSlider(float currentSpeed) const {
    const Rectangle track{40.0f, 660.0f, 260.0f, 8.0f};
    const float minSpeed = 0.0f;
    const float maxSpeed = 100.0f;
    const Vector2 mousePosition = GetMousePosition();

    float normalizedValue = (currentSpeed - minSpeed) / (maxSpeed - minSpeed);

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePosition, Rectangle{track.x - 12, track.y - 18, track.width + 24, 44})) {
        normalizedValue = (mousePosition.x - track.x) / track.width;

        if (normalizedValue < 0.0f) {
            normalizedValue = 0.0f;
        }
        if (normalizedValue > 1.0f) {
            normalizedValue = 1.0f;
        }
    }

    const float newSpeed = minSpeed + normalizedValue * (maxSpeed - minSpeed);
    const float knobX = track.x + normalizedValue * track.width;

    DrawText("Speed", static_cast<int>(track.x), static_cast<int>(track.y - 34), 18, RAYWHITE);
    DrawRectangleRounded(track, 0.5f, 8, Color{85, 85, 85, 255});
    DrawRectangleRounded(Rectangle{track.x, track.y, knobX - track.x, track.height}, 0.5f, 8, Color{255, 205, 50, 255});
    DrawCircle(static_cast<int>(knobX), static_cast<int>(track.y + track.height / 2), 11, RAYWHITE);

    const std::string speedText = TextFormat("%.1fx", newSpeed);
    DrawText(speedText.c_str(), static_cast<int>(track.x + track.width + 18), static_cast<int>(track.y - 7), 18, RAYWHITE);

    return newSpeed;
}

Color RaylibHelper::getRaylibColor(PlanetColor planetColor) const {
    return Color{planetColor.r, planetColor.g, planetColor.b, planetColor.a};
}
