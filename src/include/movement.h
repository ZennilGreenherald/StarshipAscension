#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "ship.h"
#include "vector2.h"

class Movement {
public:

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

int StarshipAscension::getX() const
{
    return m_x;
}

void StarshipAscension::setX(int x)
{
    m_x = x;
}

int StarshipAscension::getY() const
{
    return m_y;
}

void StarshipAscension::setY(int y)
{
    m_y = y;
}
