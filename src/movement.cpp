#include "./include/movement.h"

#include "./include/StarshipAscension.h"
#include "./include/playing_field.h"
#include "./include/vector2d.h"

Movement::Movement()
    : m_x(0), m_y(0)
{
}

void Movement::moveUp(StarshipAscension& spaceship,
                      int playingField[][PLAYING_FIELD_WIDTH]) {
    if (spaceship.getY() > 0) {
        spaceship.setY(spaceship.getY() - 1);
    }
}

void Movement::moveLeft(StarshipAscension& spaceship,
                        int playingField[][PLAYING_FIELD_WIDTH]) {
    if (spaceship.getX() > 0) {
        spaceship.setX(spaceship.getX() - 1);
    }
}

void Movement::moveDown(StarshipAscension& spaceship,
                        int playingField[][PLAYING_FIELD_WIDTH]) {
    if (spaceship.getY() < PLAYING_FIELD_HEIGHT - 1) {
        spaceship.setY(spaceship.getY() + 1);
    }
}

void Movement::moveRight(StarshipAscension& spaceship,
                         int playingField[][PLAYING_FIELD_WIDTH]) {
    if (spaceship.getX() < PLAYING_FIELD_WIDTH - 1) {
        spaceship.setX(spaceship.getX() + 1);
    }
}
int Movement::getX() const
{
    return m_x;
}

void Movement::setX(int x)
{
    m_x = x;
}

int Movement::getY() const
{
    return m_y;
}

void Movement::setY(int y)
{
    m_y = y;
}