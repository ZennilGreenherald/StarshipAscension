#ifndef SHIP_H
#define SHIP_H

#include <string>

class Station;

class StarshipAscension {
public:
    StarshipAscension(std::string name, std::string captain, std::string firstOfficer);

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

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
