#ifndef SHIP_H
#define SHIP_H

#include <string>

class StarshipAscension {
public:
    StarshipAscension(std::string name, std::string captain, std::string firstOfficer);
    // Add member functions for weapons, shields, crew, communications, engine status, away missions, transporters, shuttlecraft, fuel status, health, ammo, docking functions, life support status, damage control, astrometrics, science, alert status, hailing frequencies, radio and viewscreen controls, sickbay status, etc.

private:
    std::string name_;
    std::string captain_;
    std::string firstOfficer_;
    // Add member variables for weapons, shields, crew, communications, engine status, away missions, transporters, shuttlecraft, fuel status, health, ammo, docking functions, life support status, damage control, astrometrics, science, alert status, hailing frequencies, radio and viewscreen controls, sickbay status, etc.
};

#endif // SHIP_H
