#include "./include/shields_manager.h"

#include "./include/StarshipAscension.h"

ShieldsManager::ShieldsManager()
    : shield_(nullptr)
{
}

void ShieldsManager::addShield(std::string name, int defense, int level) {
    shield_ = new Shield(name, defense, level);
}

bool ShieldsManager::removeShield(std::string name) {
    if (shield_ != nullptr && shield_->getName() == name) {
        delete shield_;
        shield_ = nullptr;
        return true;
    }
    return false;
}

Shield* ShieldsManager::findShield(std::string name) {
    if (shield_ != nullptr && shield_->getName() == name) {
        return shield_;
    }
    return nullptr;
}

void ShieldsManager::updateShields(StarshipAscension& spaceship) {
    if (shield_ != nullptr) {
        int damage = spaceship.getDamage();
        int defense = shield_->getDefense();
        int level = shield_->getLevel();
        int remainingDefense = defense - damage;
        if (remainingDefense < 0) {
            remainingDefense = 0;
        }
        shield_ = new Shield(shield_->getName(), remainingDefense, level);
    }
}
