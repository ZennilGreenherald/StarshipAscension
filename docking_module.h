#ifndef DOCKING_MODULE_H
#define DOCKING_MODULE_H

#include <string>

class Spaceship {
public:
    Spaceship(std::string name, int maxHealth, int maxFuel, int maxAmmo);

    std::string getName() const;
    int getHealth() const;
    int getFuel() const;
    int getAmmo() const;

    void repair(int amount);
    void refuel(int amount);
    void restock(int amount);

private:
    std::string name_;
    int health_;
    int fuel_;
    int ammo_;
    int maxHealth_;
    int maxFuel_;
    int maxAmmo_;
};

class Station {
public:
    Station(std::string name, int maxHealth, int maxFuel, int maxAmmo);

    std::string getName() const;
    int getHealth() const;
    int getFuel() const;
    int getAmmo() const;

    void repair(Spaceship& spaceship, int amount);
    void refuel(Spaceship& spaceship, int amount);
    void restock(Spaceship& spaceship, int amount);

private:
    std::string name_;
    int health_;
    int fuel_;
    int ammo_;
    int maxHealth_;
    int maxFuel_;
    int maxAmmo_;
};

#endif  // DOCKING_MODULE_H
