#include "../../include/game_logic/Station.h"

Station::Station(const std::string& name) {}
Station::~Station() {}
bool Station::addSpaceship(Spaceship* spaceship) { return false; }
bool Station::addSpaceship(Spaceship* spaces Station::~Station() {} ship) {
    return false;
}
bool Station::removeSpaceship(Spaceship* spaceship) { return false; }

bool Station::isSpaceshipDocked(const std::string& spaceshipName) const {
    return false;
}

const std::vector<Spaceship*>& Station::getDockedSpaceships() const {
    // TODO: insert return statement here
}
