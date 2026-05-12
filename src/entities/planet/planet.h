#pragma once
#include <string>

class Planet {
  private:
    std::string name = "";
    float gravityModifier = 1.0;
    float positionX = 0.0f;
    float positionY = 0.0f;

  protected:
  public:
    Planet(std::string name, float gravityModifier);

    const std::string getName() const;
    void setName(std::string newName);

    const float getGravity() const;

    void setX();
    float getX();

    void setY();
    float getY();
};