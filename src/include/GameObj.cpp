#include "GameObj.h"

GameObj::GameObj()
{
}

GameObj::GameObj(std::string name)
	: name(std::move(name))
{
}

GameObj::GameObj(Serializer& ser)
	: name(ser.readStr()), pos(ser.readVec2D())
{
}

GameObj::GameObj(GameObj&& obj) noexcept
	: name(std::move(obj.name)), pos(obj.pos)
{
	obj.pos = {};
}

GameObj::GameObj(const GameObj& obj)
	: name(obj.name), pos(obj.pos)
{
}

GameObj& GameObj::operator=(GameObj&& obj) noexcept
{
	if (this == &obj)
		return *this;

	name = std::move(obj.name);
	pos = obj.pos;

	obj.pos = {};

    return *this;
}

GameObj& GameObj::operator=(const GameObj& obj)
{
	if (this == &obj)
		return *this;

	name = obj.name;
	pos = obj.pos;

    return *this;
}

bool GameObj::operator==(const GameObj& other)
{
	return name == other.name;
}

bool GameObj::operator!=(const GameObj& other)
{
	return name != other.name;
}

bool GameObj::operator==(const std::string& otherName)
{
	return name == otherName;
}

bool GameObj::operator!=(const std::string& otherName)
{
	return name != otherName;
}

bool GameObj::operator==(const Vector2D& otherPos)
{
	return pos == otherPos;
}

bool GameObj::operator!=(const Vector2D& otherPos)
{
	return pos != otherPos;
}

void GameObj::serialize(Serializer& ser)
{
	ser.writeStr(name);
	ser.writeVec2D(pos);
}

void GameObj::deserialize(Serializer& ser)
{
	name = ser.readStr();
	pos = ser.readVec2D();
}

void GameObj::setName(std::string newName)
{
    name = std::move(newName);
}

std::string GameObj::getName() const
{
    return name;
}

void GameObj::setPos(const Vector2D& newPos)
{
    pos = newPos;
}

Vector2D GameObj::getPos() const
{
    return pos;
}

std::string GameObj::getDisplay() const
{
	return " ";
}

GameObj* GameObj::Clone() const
{
	return new GameObj(*this);
}
