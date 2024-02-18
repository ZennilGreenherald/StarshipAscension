#ifndef PLAYING_FIELD_H
#define PLAYING_FIELD_H

#include "../game_logic/Spaceship.h"

#include <vector>
#include <cstdlib>
#include <array>

const uint32_t PLAYING_FIELD_HEIGHT = 50;
const uint32_t PLAYING_FIELD_WIDTH = 100;

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

	void initialize()
	{
    	objects.clear();
	}
	void setPosition(const Vector2D& position);
	void moveObject(GameObj* obj, int dx, int dy) {
    Vector2D newPos = obj->getPos() + Vector2D(dx, dy);
    if (newPos.x < 0 || newPos.x >= PLAYING_FIELD_WIDTH ||
        newPos.y < 0 || newPos.y >= PLAYING_FIELD_HEIGHT) {
        return;
    }
    GameObj* otherObj = getObject(newPos);
    if (otherObj && otherObj != obj) {
        return;
    }
    obj->setPos(newPos);
	}
	bool hasObject(const std::string& name);

    bool addObject(GameObj* obj) {
		objects.push_back(obj);
		return true;
	};

    bool removeObject(const std::string& name);

	bool removeObject(const Vector2D& pos);

	GameObj* getObject(const std::string& name) const;

    GameObj* getObject(const Vector2D& pos) const;

    void display() const;
};

#endif
