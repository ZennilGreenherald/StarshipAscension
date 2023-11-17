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
    return docked_ && spaceship.getPos().x == station_->getX() && spaceship.getPos().y == station_->getY();
}

void DockingModule::dock(Spaceship& spaceship, Station& station) {
    docked_ = true;
    station_ = &station;
    spaceship.setPos(Vector2D(station.getX(), station.getY()));
}

void DockingModule::undock(Spaceship& spaceship) {
    docked_ = false;
    station_ = nullptr;
    spaceship.setPos(spaceship.getPos() + Vector2D(1, 1));
}

#endif
