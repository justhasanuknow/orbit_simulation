#pragma once
#include <string>

class Planet {
  private:
    std::string name = "";
    float gravityModifier = 1.0;

  protected:
  public:
    Planet(std::string name, float gravityModifier);

    const std::string getName() const;
    void setName(std::string newName);

    const float getGravity() const;
};