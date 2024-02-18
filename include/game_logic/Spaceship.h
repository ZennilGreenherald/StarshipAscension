#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "../../include/Shields.h"
#include "../../include/GameObj.h" // Assuming GameObj is the base class for game objects

class Spaceship : public GameObj {
public:
    Spaceship();
    ~Spaceship();

    // Other methods...

private:
    Shields shields; // Include the Shields class
};

#endif // SPACESHIP_H
