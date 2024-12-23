// include/ui/PlayingField.h

#ifndef PLAYING_FIELD_H
#define PLAYING_FIELD_H

#include <array>
#include <cstdlib>
#include <vector>
#include <cstdint>

#include "../../include/game_logic/GameObj.h"
#include "../../include/game_logic/Spaceship.h"
#include "../../include/utils/Vector2D.h"

static constexpr int HEIGHT = 50;
static constexpr int WIDTH = 100;

static constexpr PLAYING_FIELD_BORDER = '#';
static constexpr PLAYING_FIELD_EMPTY = ' ';
static constexpr PLAYING_FIELD_SHIP = 'S';
static constexpr PLAYING_FIELD_PLANET = 'P';
static constexpr PLAYING_FIELD_STARBASE = 'B';
static constexpr PLAYING_FIELD_MOON = 'M';
static constexpr PLAYING_FIELD_ENEMY_SHIP = 'E';

class PlayingField {
  private:
    std::vector<GameObj*> objects;
    std::vector<std::vector<char>> field;  // Declare field variable

  public:
    PlayingField();
    void initialize() { objects.clear(); }
    void initializeField(int width, int height);  // Declare initializeField function
    void setPosition(const Vector2D& position);
    void moveObject(GameObj* obj, int dx, int dy);
    bool hasObject(const std::string& name);
    bool addObject(GameObj* obj);
    bool removeObject(const std::string& name);
    bool removeObject(const Vector2D& pos);
    GameObj* getObject(const std::string& name) const;
    GameObj* getObject(const Vector2D& pos) const;
    void display() const;
};

#endif
