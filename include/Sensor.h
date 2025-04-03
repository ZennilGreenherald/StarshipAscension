#ifndef SENSOR_H
#define SENSOR_H

#include "../../include/data_models/Position.h"

class Sensor {
  public:
    Sensor();   // Constructor
    ~Sensor();  // Destructor

    bool detectObstacle(Position currentPosition, Position destination);
};

#endif
