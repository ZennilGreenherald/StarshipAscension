#ifndef PLAYING_FIELD_H
#define PLAYING_FIELD_H

#include "Spaceship.h"

#include <vector>
#include <cstdlib>
#include <array>

const uint32_t PLAYING_FIELD_HEIGHT = 20;
const uint32_t PLAYING_FIELD_WIDTH = 40;

const std::string PLAYING_FIELD_EMPTY = " ";
const std::string PLAYING_FIELD_BORDER = "#";
const std::string PLAYING_FIELD_SHIP = "S";
const std::string PLAYING_FIELD_PLANET = "P";
const std::string PLAYING_FIELD_STARBASE = "B";
const std::string PLAYING_FIELD_MOON = "M";
const std::string PLAYING_FIELD_ENEMY_SHIP = "E";

class PlayingField
{
private:
	std::vector<GameObj*> objects;

public:
    PlayingField();

	bool hasObject(const std::string& name);

    bool addObject(GameObj* obj);

    bool removeObject(const std::string& name);

	bool removeObject(const Vector2D& pos);

	GameObj* getObject(const std::string& name) const;

    GameObj* getObject(const Vector2D& pos) const;

    void display() const;
};

#endif
