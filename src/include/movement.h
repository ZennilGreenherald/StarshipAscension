#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "StarshipAscension.h"
#include "playing_field.h"

class Movement
{
public:
    Movement();

    void moveUp(StarshipAscension& spaceship, int playingField[][PLAYING_FIELD_WIDTH]);
    void moveLeft(StarshipAscension& spaceship, int playingField[][PLAYING_FIELD_WIDTH]);
    void moveDown(StarshipAscension& spaceship, int playingField[][PLAYING_FIELD_WIDTH]);
    void moveRight(StarshipAscension& spaceship, int playingField[][PLAYING_FIELD_WIDTH]);

    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);

private:
    int m_x;
    int m_y;

};

#endif // MOVEMENT_H
