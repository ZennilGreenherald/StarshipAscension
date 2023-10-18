#ifndef DOCKING_MODULE_H
#define DOCKING_MODULE_H

#include <iostream>
#include <string>
#include <cmath>
#include "ship.h"
#include "station.h"

class Station;

class Spaceship {
public:
    Spaceship();
    Spaceship(std::string name, int maxHealth, int maxFuel, int maxAmmo)
        : name_{ name }, health_{ maxHealth }, fuel_{ maxFuel }, ammo_{ maxAmmo },
        maxHealth_{ maxHealth }, maxFuel_{ maxFuel }, maxAmmo_{ maxAmmo }
    {
    }

    // Add the missing field declarations
    std::string name_;
    int health_;
    int fuel_;
    int ammo_;
    int maxHealth_;
    int maxFuel_;
    int maxAmmo_;
    int x_;
    int y_;

    int getX() const { return x_; }
    int getY() const { return y_; }
    void setX(int x) { x_ = x; }
    void setY(int y) { y_ = y_; }

};

class DockingModule {
public:
    DockingModule();
    bool isDocked(Spaceship& spaceship);
    void dock(Spaceship& spaceship, Station& station);
    void undock(Spaceship& spaceship);

private:
    bool docked_;
    Station* station_;
};

DockingModule::DockingModule() : docked_{ false }, station_{ nullptr } {}

bool DockingModule::isDocked(Spaceship& spaceship) {
    return docked_ && spaceship.getX() == station_->getX() && spaceship.getY() == station_->getY();
}

void DockingModule::dock(Spaceship& spaceship, Station& station) {
    docked_ = true;
    station_ = &station;
    spaceship.setX(station.getX());
    spaceship.setY(station.getY());
}

void DockingModule::undock(Spaceship& spaceship) {
    docked_ = false;
    station_ = nullptr;
    spaceship.setX(spaceship.getX() + 1);
    spaceship.setY(spaceship.getY() + 1);
}

#endif
