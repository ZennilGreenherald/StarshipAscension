#include "../../include/game_logic/Weapons.h"

Weapons::Weapons(const std::string& name, int id, int ammo, int damage,
                 float range)
    : name(name), id(id), ammo(ammo), damage(damage), range(range) {}

// ... other methods implementations
