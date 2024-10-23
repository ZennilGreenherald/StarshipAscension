#include "../../include/game_logic/ShieldsManager.h"

#include <iostream>

#include "../../include/data_models/Shields.h"

ShieldsManager::ShieldsManager() {
    // Constructor code for ShieldsManager
}

ShieldsManager::~ShieldsManager() {
    // Destructor code for ShieldsManager
}

void ShieldsManager::addShield(Shields* shield) { shields.push_back(shield); }

void ShieldsManager::removeShield(Shields* shield) {
    // Implementation to remove a shield from the manager
}

Shields* ShieldsManager::getShield(int id) {
    // Implementation to get a shield by its ID
    for (auto shield : shields) {
        if (shield->getId() == id) {
            return shield;
        }
    }
    // If shield not found, throw exception
    throw std::runtime_error("Shield not found");
}

void ShieldsManager::updateShields() {
    // Implementation to update all shields
}

void printShieldsStatus(bool shieldsUp) {
    if (shieldsUp) {
        std::cout << "Shields up!" << std::endl;
    } else {
        std::cout << "Shields down!" << std::endl;
    }
}

void printShieldsHealth(int shieldHealth) {
    std::cout << "Shields health: " << shieldHealth << std::endl;
}
