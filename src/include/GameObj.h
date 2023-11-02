#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include "vector2d.h"
#include "Serializer.h"

#include <string>

class GameObj
{
private:
    std::string name;
    Vector2D pos;

public:
    GameObj();

    GameObj(std::string name);

	GameObj(Serializer& ser);

    GameObj(GameObj&& obj) noexcept;

    GameObj(const GameObj& obj);

    GameObj& operator=(GameObj&& obj) noexcept;

    GameObj& operator=(const GameObj& obj);

	bool operator==(const GameObj& other) const;

	bool operator==(const GameObj& other);

	bool operator!=(const GameObj& other);

	bool operator==(const std::string& otherName);

	bool operator!=(const std::string& otherName);

	bool operator==(const Vector2D& otherPos);

	bool operator!=(const Vector2D& otherPos);

	virtual void serialize(Serializer& ser);

	virtual void deserialize(Serializer& ser);

    void setName(std::string newName);

    std::string getName() const;

    void setPos(const Vector2D& newPos);

    Vector2D getPos() const;

	virtual std::string getDisplay() const;

	virtual GameObj* Clone() const;
};

#endif
