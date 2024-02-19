#include "../../include/game_logic/Movement.h"

#include "../../include/ui/PlayingField.h"
#include "../../include/game_logic/StarshipAscension.h"
#include "../../include/utils/Vector2D.h"

Movement::Movement()
	: m_x(0), m_y(0)
{
}

void Movement::moveUp(StarshipAscension &spaceship,
					  uint32_t playingField[][PLAYING_FIELD_WIDTH])
{
	if (spaceship.getY() > 0)
	{
		spaceship.setY(spaceship.getY() - 1);
	}
}

void Movement::moveLeft(StarshipAscension &spaceship,
						uint32_t playingField[][PLAYING_FIELD_WIDTH])
{
	if (spaceship.getX() > 0)
	{
		spaceship.setX(spaceship.getX() - 1);
	}
}

void Movement::moveDown(StarshipAscension &spaceship,
						uint32_t playingField[][PLAYING_FIELD_WIDTH])
{
	if (spaceship.getY() < PLAYING_FIELD_HEIGHT - 1)
	{
		spaceship.setY(spaceship.getY() + 1);
	}
}

void Movement::moveRight(StarshipAscension &spaceship,
						 uint32_t playingField[][PLAYING_FIELD_WIDTH])
{
	if (spaceship.getX() < PLAYING_FIELD_WIDTH - 1)
	{
		spaceship.setX(spaceship.getX() + 1);
	}
}

uint32_t Movement::getX() const
{
	return m_x;
}

void Movement::setX(const uint32_t x)
{
	m_x = x;
}

uint32_t Movement::getY() const
{
	return m_y;
}

void Movement::setY(const uint32_t y)
{
	m_y = y;
}
