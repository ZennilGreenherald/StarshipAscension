#include "../../include/game_logic/GameObj.h"

GameObj::GameObj(const std::string& name, const Vector2D& position,
                 double size) {}

GameObj::~GameObj() {}

std::string GameObj::getName() const { return std::string(); }

Vector2D GameObj::getPosition() const { return Vector2D(); }

double GameObj::getSize() const { return 0.0; }

void GameObj::setName(const std::string& name) {}

void GameObj::setPosition(const Vector2D& position) {}

void GameObj::setSize(double size) {}
