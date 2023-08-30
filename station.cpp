#include "station.h"
#include "docking_module.h" // Include the ship.h header file
#include "ship.h"

Station::Station(std::string name, int maxHealth, int maxFuel, int maxAmmo)
    : name_{name}, health_{maxHealth}, fuel_{maxFuel}, ammo_{maxAmmo},
      maxHealth_{maxHealth}, maxFuel_{maxFuel}, maxAmmo_{maxAmmo} {}

std::string Station::getName() const { return name_; }

int Station::getHealth() const { return health_; }

int Station::getFuel() const { return fuel_; }

int Station::getAmmo() const { return ammo_; }

void Station::repair(int amount) {
    health_ = std::min(health_ + amount, maxHealth_);
}

void Station::refuel(int amount) { fuel_ = std::min(fuel_ + amount, maxFuel_); }

void Station::restock(int amount) {
    ammo_ = std::min(ammo_ + amount, maxAmmo_);
}

void Station::dockSpaceship(Spaceship &spaceship) {
    // Implement the docking logic between the station and the spaceship
    // ...
    // Example: spaceship.dock(*this);
}
