#include "raylib_helper.h"

#include <cstdlib>
#include <iostream>
#include <memory>

#include "../../entities/solar_system/solar_system.h"

void RaylibHelper::initializeWindow() const {
    const int windowWidth = 1600;
    const int windowHeight = 720;

    InitWindow(windowWidth, windowHeight, "Solar Simulation");

    Vector2 ballSpeed = {5.0f, 4.0f};

    float gravity = 0.2f;

    bool useGravity = true;
    bool pause = 0;

    SetTargetFPS(144);

    const std::unique_ptr<SolarSystem> solarSystem{new SolarSystem()};

    solarSystem->listPlanets();

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(DARKGRAY);

        DrawFPS(10, 10);

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