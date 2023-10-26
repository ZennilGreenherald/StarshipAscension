#include "./include/docking_module.h"
#include "./include/ship.h"
#include "./include/station.h"

std::string StarshipAscension::getName() const { return name; }

int StarshipAscension::getHealth() const { return health; }

int StarshipAscension::getFuel() const { return fuel; }

int StarshipAscension::getAmmo() const { return ammo; }

void StarshipAscension::repair(int amount) {
    health = std::min(health + amount, maxHealth);
}

void StarshipAscension::refuel(int amount) {
    fuel = std::min(fuel + amount, maxFuel_);
}

void StarshipAscension::restock(int amount) {
    ammo = std::min(ammo + amount, maxAmmo);
}

void StarshipAscension::dock(Station* station) {
    // Implement the docking logic between the StarshipAscension and the station
    // ...
    // Example: station.dockStarshipAscension(*this);
}

double StarshipAscension::calculateDistance() const {
    // Calculate the distance between the StarshipAscension and the docking port
    // ...
    // Example: return std::sqrt(std::pow(StarshipAscensionX - dockingPortX, 2) +
    // std::pow(StarshipAscensionY - dockingPortY, 2));
    return 0.0;
}

void StarshipAscension::activateDockingClamps() {
    // Activate the docking clamps of the StarshipAscension
    // ...
    // Example: std::cout << "Docking clamps activated!" << std::endl;
}
