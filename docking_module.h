#ifndef DOCKING_MODULE_H
#define DOCKING_MODULE_H

#include <iostream>
#include <string>
#include <cmath>
#include "ship.h"

class Station;

class Spaceship {
public:
    Spaceship(std::string name, int maxHealth, int maxFuel, int maxAmmo)
        : name_{ name }, health_{ maxHealth }, fuel_{ maxFuel }, ammo_{ maxAmmo },
        maxHealth_{ maxHealth }, maxFuel_{ maxFuel }, maxAmmo_{ maxAmmo }
    {
    }

    std::string getName() const;
    int getHealth() const;
    int getFuel() const;
    int getAmmo() const;
    void repair(int amount);
    void refuel(int amount);
    void restock(int amount);
    void dock(Station* station);

private:
    std::string name_;
    int health_;
    int fuel_;
    int ammo_;
    int maxHealth_;
    int maxFuel_;
    int maxAmmo_;

    static constexpr double dockingDistanceThreshold = 1.0;  // Example value, replace with actual value

    double calculateDistance() const;
    void activateDockingClamps();

    static constexpr double dockingPortX = 1.0;  // Example value, replace with actual value
    static constexpr double dockingPortY = 2.0;  // Example value, replace with actual value
    double spaceshipX;
    double spaceshipY;
};

#endif
