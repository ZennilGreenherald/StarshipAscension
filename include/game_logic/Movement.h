#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "StarshipAscension.h"
#include "PlayingField.h"

class Movement
{
public:
    Movement();

    void moveUp(StarshipAscension& spaceship, uint32_t playingField[][PLAYING_FIELD_WIDTH]);
    void moveLeft(StarshipAscension& spaceship, uint32_t playingField[][PLAYING_FIELD_WIDTH]);
    void moveDown(StarshipAscension& spaceship, uint32_t playingField[][PLAYING_FIELD_WIDTH]);
    void moveRight(StarshipAscension& spaceship, uint32_t playingField[][PLAYING_FIELD_WIDTH]);

    uint32_t getX() const;
    void setX(const uint32_t x);
    uint32_t getY() const;
    void setY(const uint32_t y);

private:
    uint32_t m_x;
    uint32_t m_y;

};

#endif // MOVEMENT_H
