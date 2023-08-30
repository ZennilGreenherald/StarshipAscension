#include <iostream>
#include <string>
#include <cmath>
#include "station.h"
#include "docking_module.h"
#include "ship.h"

// Implement the member functions of the Spaceship class here

std::string Spaceship::getName() const
{
    return name_;
}

int Spaceship::getHealth() const
{
    return health_;
}

int Spaceship::getFuel() const
{
    return fuel_;
}

int Spaceship::getAmmo() const
{
    return ammo_;
}

void Spaceship::repair(int amount)
{
    health_ = std::min(health_ + amount, maxHealth_);
}

void Spaceship::refuel(int amount)
{
    fuel_ = std::min(fuel_ + amount, maxFuel_);
}

void Spaceship::restock(int amount)
{
    ammo_ = std::min(ammo_ + amount, maxAmmo_);
}

void Spaceship::dock(Station& station)
{
    double distance = calculateDistance();
    if (distance <= dockingDistanceThreshold)
    {
        activateDockingClamps();
        std::cout << "Starbase Docking Successful!" << std::endl;
    }
    else
    {
        std::cout << "Approach the docking port to activate docking clamps." << std::endl;
    }
}

double Spaceship::calculateDistance() const
{
    // Implementation of calculateDistance function
}

void Spaceship::activateDockingClamps()
{
    // Implementation of activateDockingClamps function
}
