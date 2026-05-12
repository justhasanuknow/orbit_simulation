#pragma once

#include "raylib.h"

class RaylibHelper {
  private:
    RaylibHelper() = default;
    ~RaylibHelper() = default;
    const float ballRadius = 20;

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