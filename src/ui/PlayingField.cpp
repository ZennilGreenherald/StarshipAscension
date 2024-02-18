#include "./include/playing_field.h"

#include <iostream>

PlayingField::PlayingField()
{
}

bool PlayingField::hasObject(const std::string &name)
{
	for (size_t i = 0; i < objects.size(); ++i)
		if (*objects[i] == name)
			return true;

	return false;
}

bool PlayingField::addObject(GameObj *obj)
{
	if (hasObject(obj->getName()) || getObject(obj->getPos()))
		return false;

	objects.push_back(obj);

	return true;
}

bool PlayingField::removeObject(const std::string &name)
{
	for (size_t i = 0; i < objects.size(); ++i)
	{
		if (*objects[i] != name)
			continue;

		std::swap(objects[i], objects[objects.size() - 1]);
		objects.pop_back();

		return true;
	}

	return false;
}

bool PlayingField::removeObject(const Vector2D &pos)
{
	for (size_t i = 0; i < objects.size(); ++i)
	{
		if (*objects[i] != pos)
			continue;

		std::swap(objects[i], objects[objects.size() - 1]);
		objects.pop_back();

		return true;
	}

	return false;
}

GameObj *PlayingField::getObject(const std::string &name) const
{
	for (size_t i = 0; i < objects.size(); ++i)
		if (*objects[i] == name)
			return objects[i];

	return nullptr;
}

GameObj *PlayingField::getObject(const Vector2D &pos) const
{
	for (size_t i = 0; i < objects.size(); ++i)
		if (*objects[i] == pos)
			return objects[i];

	return nullptr;
}

void PlayingField::display() const
{
	std::string field;

	for (int i = 0; i < PLAYING_FIELD_HEIGHT; i++)
	{
		for (int j = 0; j < PLAYING_FIELD_WIDTH; j++)
		{
			if (i == 0 || i == PLAYING_FIELD_HEIGHT - 1 || j == 0 || j == PLAYING_FIELD_WIDTH - 1)
			{
				field += PLAYING_FIELD_BORDER + "\n";
			}
			else
			{
				GameObj *obj = getObject(Vector2D(j, i));
				if (!obj)
					field += PLAYING_FIELD_EMPTY;
				else
					field += obj->getDisplay();
			}
		}
	}

	std::cout << field;
}
