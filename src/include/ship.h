#ifndef SHIP_H
#define SHIP_H

#include <string>

class StarshipAscension {
public:
    StarshipAscension(std::string name, std::string captain, std::string firstOfficer);
    // Add member functions for weapons, shields, crew, communications, engine status, away missions, transporters, shuttlecraft, fuel status, health, ammo, docking functions, life support status, damage control, astrometrics, science, alert status, hailing frequencies, radio and viewscreen controls, sickbay status, etc.

private:
    std::string name;
    std::string captain;
    std::string firstOfficer;
	std::string name;
    int health;
    int ammo;
    int fuelStatus;
    int alertStatus;
	void updateShields();
    void updateEngineStatus();
    void updateLifeSupportStatus();
    void updateDamageControl();
    void updateAstrometrics();
    void updateScience();
    void updateHailingFrequencies();
    void updateRadio();
    void updateViewscreens();
    void updateSickbayStatus();
    // Add member variables for weapons, shields, crew, communications, engine status, away missions, transporters, shuttlecraft, fuel status, health, ammo, docking functions, life support status, damage control, astrometrics, science, alert status, hailing frequencies, radio and viewscreen controls, sickbay status, etc.
};

#endif // SHIP_H
