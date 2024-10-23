// include/game_logic/Movement.h

#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "../../include/game_logic/StarshipAscension.h"
#include "../../include/game_logic/Station.h"
#include "../../include/ui/PlayingField.h"

class Movement {
  public:
    Movement();

    void moveUp(StarshipAscension& spaceship, uint32_t* playingField, uint32_t width, uint32_t height);
    void moveLeft(StarshipAscension& spaceship, uint32_t* playingField, uint32_t width, uint32_t height);
    void moveDown(StarshipAscension& spaceship, uint32_t* playingField, uint32_t width, uint32_t height);
    void moveRight(StarshipAscension& spaceship, uint32_t* playingField, uint32_t width, uint32_t height);

    uint32_t getX() const;
    void setX(const uint32_t x);
    uint32_t getY() const;
    void setY(const uint32_t y);

  private:
    uint32_t m_x;
    uint32_t m_y;
};

#endif // MOVEMENT_H
