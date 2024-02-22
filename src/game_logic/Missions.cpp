#include "../../include/game_logic/Missions.h"

#include <iostream>

Missions::Missions() {
    // Constructor implementation
}

Missions::~Missions() {
    // Destructor implementation
}

void Missions::startMission(int missionID) {
    // Logic to start the mission
    std::cout << "Mission " << missionID << " started!" << std::endl;
    // Add more logic as needed
}

void Missions::completeMission(int missionID) {
    // Logic to complete the mission
    std::cout << "Mission " << missionID << " completed!" << std::endl;
    // Add more logic as needed
}
