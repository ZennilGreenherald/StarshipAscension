#ifndef STARSHIP_ASCENSION_H
#define STARSHIP_ASCENSION_H

#include <string>
#include "Station.h"
#include "Weapons.h"
#include "WeaponsManager.h"

class StarshipAscension {
public:
    StarshipAscension(std::string name, std::string captain, std::string firstOfficer);

    void setX(const uint32_t x);
    uint32_t getX() const;
    uint32_t getY() const;
    void setY(const uint32_t y);
    int getMaxHealth() const;
    int getHealth() const;
    int getDamage() const;
    std::string getName() const;
    int getFuel() const;
    int getAmmo() const;
    void repair(int amount);
    void refuel(int amount);
    void restock(int amount);
    void dock(Station* station);
    double calculateDistance() const;
    void activateDockingClamps();
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

private:
    std::string name;
    std::string captain;
    std::string firstOfficer;
    int maxHealth;
    int health;
    int ammo;
    int fuel;
    int alertStatus;
    uint32_t m_x;
    uint32_t m_y;
    // Add any other private member variables as needed
};

#endif // STARSHIP_ASCENSION_H