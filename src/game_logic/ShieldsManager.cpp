#include "../../include/game_logic/ShieldsManager.h"

#include <iostream>

#include "../../include/data_models/Shields.h"

ShieldsManager::ShieldsManager() {
    // Constructor code for ShieldsManager
}

ShieldsManager::~ShieldsManager() {
    // Destructor code for ShieldsManager
}

void ShieldsManager::addShield(Shield* shield) { shields.push_back(shield); }

void ShieldsManager::removeShield(Shield* shield) {
    // Implementation to remove a shield from the manager
}

Shield* ShieldsManager::getShield(int id) {
    // Implementation to get a shield by its ID
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
