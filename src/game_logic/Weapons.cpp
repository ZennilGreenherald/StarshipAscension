#include "../../include/game_logic/Weapons.h"

Weapons::Weapons(const std::string& name, int id, int ammo, int damage,
                 float range)
    : name(name), id(id), ammo(ammo), damage(damage), range(range) {}

// ... other methods implementations

std::string Weapons::getName() const { return std::string(); }

int Weapons::getAmmo() const { return 0; }

int Weapons::getDamage() const { return 0; }

float Weapons::getRange() const { return 0.0f; }
