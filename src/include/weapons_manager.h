#ifndef WEAPONS_MANAGER_H
#define WEAPONS_MANAGER_H

#include <string>
#include <vector>

#include "StarshipAscension.h"

class Weapon {
public:
    Weapon(std::string name, int damage, int level);

    std::string getName() const;
    int getDamage() const;
    int getLevel() const;

private:
    std::string name_;
    int damage_;
    int level_;
};

class WeaponsManager {
public:
    void addWeapon(std::string name, int damage, int level);
    bool removeWeapon(std::string name);
    Weapon* findWeapon(std::string name);
    std::vector<Weapon*> getAllWeapons() const;
    void updateWeapons(StarshipAscension& spaceship);

private:
    std::vector<Weapon*> weapons_;
};

#endif
