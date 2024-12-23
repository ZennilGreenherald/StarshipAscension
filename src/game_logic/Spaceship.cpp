#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "../../include/game_logic/Spaceship.h"

#include "../../include/data_models/Position.h"
#include "../../include/game_logic/Engine.h"
#include "../../include/game_logic/Movement.h"
#include "../../include/ui/PlayingField.h"
#include "../../include/utils/Vector2D.h"

class Spaceship {
  public:
    Spaceship();   // Constructor
    ~Spaceship();  // Destructor

    void move(Vector2D direction);
    void updatePosition();

  private:
    Position position;
    Engine engine;
    Movement movement;
};

#endif
