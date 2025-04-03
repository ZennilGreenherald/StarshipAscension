#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "../../include/data_models/Position.h"
#include "../../include/game_logic/Engine.h"
#include "../../include/game_logic/Movement.h"
#include "../../include/utils/Vector2D.h"
#include "../../include/data_models/Sensor.h"  // Assuming you have a Sensor class

class Navigation {
  public:
    Navigation();   // Constructor
    ~Navigation();  // Destructor

    void setDestination(Position destination);
    void calculatePath();
    void initiateMovement();
    void scanForObstacles(); // Method to scan for obstacles using sensors

  private:
    Movement movement;
    Engine engine;
    Position currentPosition;
    Position destination;
    Vector2D path;
    Sensor sensor;  // New sensor object to detect obstacles
};

#endif
