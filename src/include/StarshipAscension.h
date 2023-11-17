#ifndef SHIP_H
#define SHIP_H

#include <cstdint>
#include <string>

class Station;

class StarshipAscension {
public:
    StarshipAscension(std::string name, std::string captain, std::string firstOfficer);

    uint32_t getX() const;

    void setX(const uint32_t x);

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

private:
    std::string name;
    std::string captain;
    std::string firstOfficer;
    int maxHealth;
    int health;
    int maxAmmo;
    int ammo;
    int maxFuel;
    int fuel;
    int alertStatus;
    int m_x;
    int m_y;
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
    // Add member variables here
};

#endif // SHIP_H
