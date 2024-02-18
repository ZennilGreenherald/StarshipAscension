// Weapons.h
#ifndef WEAPONS_H
#define WEAPONS_H

#include <string>

class Weapons {
public:
    Weapons(const std::string& name, int id, int ammo, int damage, float range);
    // ... other properties and methods

    std::string getName() const;
    int getAmmo() const;
    int getDamage() const;
    float getRange() const;

private:
    std::string name;
    int id;
    int ammo;
    int damage;
    float range;
};

#endif // WEAPONS_H
