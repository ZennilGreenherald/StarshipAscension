#include "../../include/game_logic/WeaponsManager.h"

#include <string>

#include "../../include/game_logic/Weapons.h"
#include "../../include/game_logic/WeaponsManager.h"

Weapon::Weapon(std::string name, int damage, int level)
    : name_{name}, damage_{damage}, level_{level} {}

std::string Weapon::getName() const { return name_; }

int Weapon::getDamage() const { return damage_; }

int Weapon::getLevel() const { return level_; }

void WeaponsManager::addWeapon(std::string name, int damage, int level) {
    weapons_.push_back(new Weapon{name, damage, level});
}

bool WeaponsManager::removeWeapon(std::string name) {
    for (auto it = weapons_.begin(); it != weapons_.end(); ++it) {
        if ((*it)->getName() == name) {
            delete (*it);
            weapons_.erase(it);
            return true;
        }
    }
    return false;
}

Weapon* WeaponsManager::findWeapon(std::string name) {
    for (auto it = weapons_.begin(); it != weapons_.end(); ++it) {
        if ((*it)->getName() == name) {
            return (*it);
        }
    }
    return nullptr;
}

std::vector<Weapon*> WeaponsManager::getAllWeapons() const { return weapons_; }

void WeaponsManager::updateWeapons(StarshipAscension& spaceship) {}

void WeaponsManager::dock(Station* station) {}
