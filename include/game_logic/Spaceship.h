#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "../../include/data_models/Shields.h"  // Include the Shields class for shield functionality
#include "../../include/utils/Vector2D.h"  // Include the Vector2D class for position and velocity

class Spaceship {
  public:
    // Constructor
    Spaceship(const Vector2D& initialPosition, const Vector2D& initialVelocity,
              int initialHealth);

    // Getters and setters for position, velocity, and health
    Vector2D getPosition() const;
    void setPosition(const Vector2D& newPosition);
    Vector2D getVelocity() const;
    void setVelocity(const Vector2D& newVelocity);
    int getHealth() const;
    void setHealth(int newHealth);

    // Methods for spaceship actions, such as moving and firing weapons
    void move();
    void fireWeapon();

    // Shield methods
    void raiseShields();
    void lowerShields();
    bool areShieldsUp() const;
    int getShieldHealth() const;

  private:
    Vector2D position;
    Vector2D velocity;
    int health;
    Shields shields;  // Instance of the Shields class
};

#endif  // SPACESHIP_H
