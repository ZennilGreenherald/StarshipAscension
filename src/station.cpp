#include "./include/station.h"
#include "./include/ship.h"
#include "./include/docking_module.h"

Station::Station(std::string name, int maxHealth, int maxFuel, int maxAmmo)
    : name_{name},
      health_{maxHealth},
      fuel_{maxFuel},
      ammo_{maxAmmo},
      maxHealth_{maxHealth},
      maxFuel_{maxFuel},
      maxAmmo_{maxAmmo} {}

std::string Station::getName() const { return name_; }

int Station::getHealth() const { return health_; }

int Station::getFuel() const { return fuel_; }

int Station::getAmmo() const { return ammo_; }

void Station::repair(StarshipAscension* spaceship, int amount) {
    StarshipAscension->repair(amount);
}

void Station::repair(int amount) {
    health_ += amount;
    if (health_ > maxHealth_) {
        health_ = maxHealth_;
    }
}

void Station::refuel(Spaceship* spaceship, int amount) {
    spaceship->refuel(amount);
}

void Station::refuel(int amount) {
    fuel_ += amount;
    if (fuel_ > maxFuel_) {
        fuel_ = maxFuel_;
    }
}

void Station::restock(StarshipAscension* spaceship, int amount) {
    spaceship->restock(amount);
}

void Station::restock(int amount) {
    ammo_ += amount;
    if (ammo_ > maxAmmo_) {
        ammo_ = maxAmmo_;
    }
}
