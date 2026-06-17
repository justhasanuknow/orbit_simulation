#pragma once

struct Position {
  public:
    float x;
    float y;
};

class Coordinate {
  private:
    Position position;

  public:
    Coordinate(Position initPosition);

    void setX(float newX);
    float getX() const;

    void setY(float newY);
    float getY() const;

    void setPosition(Position newPosition);
    Position getPosition() const;
};
