#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "../../include/data_models/Shields.h"  // Include the Shields class for shield functionality
#include "../../include/utils/Vector2D.h"  // Include the Vector2D class for position and velocity
#include "../../include/game_logic/Spaceship.h"
#include "../../include/data_models/Position.h"
#include "../../include/game_logic/Engine.h"
#include "../../include/game_logic/Movement.h"
#include "../../include/ui/PlayingField.h"
#include "../../include/game_logic/Spaceship.h"
#include "../../include/ui/PlayingField.h"

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

    bool isValidNewPosition(const Vector2D& newPosition);
};

#endif  // SPACESHIP_H
