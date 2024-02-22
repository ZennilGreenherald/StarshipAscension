#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "../../include/game_logic/Movement.h"
#include "../../include/game_logic/Engine.h"
#include "../../include/data_models/Position.h"
#include "../../include/utils/Vector2D.h"

class Navigation {
public:
    Navigation();  // Constructor
    ~Navigation(); // Destructor

    void setDestination(Position destination);
    void calculatePath();
    void initiateMovement();

private:
    Movement movement;
    Engine engine;
    Position currentPosition;
    Position destination;
    Vector2D path;
};

#endif
