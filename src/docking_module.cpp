#include "docking_module.h"

#include "station.h"

std::string Spaceship::getName() const { return name_; }

int Spaceship::getHealth() const { return health_; }

int Spaceship::getFuel() const { return fuel_; }

int Spaceship::getAmmo() const { return ammo_; }

void Spaceship::repair(int amount) {
    health_ = std::min(health_ + amount, maxHealth_);
}

void Spaceship::refuel(int amount) {
    fuel_ = std::min(fuel_ + amount, maxFuel_);
}

void Spaceship::restock(int amount) {
    ammo_ = std::min(ammo_ + amount, maxAmmo_);
}

void Spaceship::dock(Station* station) {
    // Implement the docking logic between the spaceship and the station
    // ...
    // Example: station.dockSpaceship(*this);
}

double Spaceship::calculateDistance() const {
    // Calculate the distance between the spaceship and the docking port
    // ...
    // Example: return std::sqrt(std::pow(spaceshipX - dockingPortX, 2) +
    // std::pow(spaceshipY - dockingPortY, 2));
    return 0.0;
}

void Spaceship::activateDockingClamps() {
    // Activate the docking clamps of the spaceship
    // ...
    // Example: std::cout << "Docking clamps activated!" << std::endl;
}
