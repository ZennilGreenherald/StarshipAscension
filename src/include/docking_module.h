#ifndef DOCKING_MODULE_H
#define DOCKING_MODULE_H

#include <cmath>
#include <iostream>
#include <string>

#include "StarshipAscension.h"
#include "Spaceship.h"
#include "station.h"

class Station;

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
