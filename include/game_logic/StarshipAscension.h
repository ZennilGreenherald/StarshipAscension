#ifndef STARSHIP_ASCENSION_H
#define STARSHIP_ASCENSION_H

#include <cstdint>
#include <string>

#include "../../include/game_logic/Station.h"
#include "../../include/game_logic/Weapons.h"

class StarshipAscension {
  public:
    StarshipAscension(std::string name, std::string captain,
                      std::string firstOfficer);

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
    int getShields() const;

    void repair(int amount);
    void refuel(int amount);
    void restock(int amount);
    void dock(Station* station);
    double calculateDistance() const;
    void activateDockingClamps();
    void updateShields();
    void updateEngineStatus();
    void updateAlertStatus();
    void updateWeaponStatus();
    void updateLifeSupportStatus();
    void updateDamageControl();
    void updateAstrometrics();
    void updateScience();
    void updateHailingFrequencies();
    void updateRadio();
    void updateViewscreens();
    void updateSickbayStatus();
    void updateTransporterStatus();

  private:
    std::string name;
    std::string captain;
    std::string firstOfficer;
    std::string connOfficer;     // Added missing officer
    std::string weaponsOfficer;  // Added missing officer

    int maxHealth;
    int health;
    int ammo;
    int fuel;
    int shields;  // Added shields
    int alertStatus;
    int engine;  // Added engine status
    int weapon;  // Added weapon status

    uint32_t m_x;
    uint32_t m_y;

  public:
    int maxAmmo;
    int maxFuel;
};

#endif
