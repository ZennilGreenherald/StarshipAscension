#include "./include/ship.h"

#include "./include/player.h"
#include "./include/weapons_manager.h"
#include <iostream>
#include <string>

StarshipAscension::StarshipAscension(std::string name, std::string captain, std::string firstOfficer) : captain(captain), firstOfficer(firstOfficer), health(100), ammo(100), fuelStatus(100), alertStatus(0), name(name) {}

void StarshipAscension::setX(int x)
{
    m_x = x;
}

int StarshipAscension::getX() const
{
    return m_x;
}

int StarshipAscension::getY() const
{
    return m_y;
}

void StarshipAscension::setY(int y)
{
    m_y = y;
}

void enterShipInfo(std::string& name, std::string& captain,
                   std::string& firstOfficer) {
    std::cout << "Enter Ship Name: ";
    std::getline(std::cin, name);
    std::cout << "Enter Captain: ";
    std::getline(std::cin, captain);
    std::cout << "Enter First Officer: ";
    std::getline(std::cin, firstOfficer);
}

void printShipInfo(std::string name, std::string captain,
                   std::string firstOfficer) {
    std::cout << "Ship Name: " << name << std::endl;
    std::cout << "Captain: " << captain << std::endl;
    std::cout << "First Officer: " << firstOfficer << std::endl;
}

void StarshipAscension::updateShields() {
    // Access the captain member variable
    std::cout << "Captain " << captain << ", raising shields!" << std::endl;
    // Access the firstOfficer member variable
    std::cout << "First Officer " << firstOfficer << ", report status!" << std::endl;
    // Access the name member variable
    std::cout << "Ship name: " << name << std::endl;
    // Update the shields
    // ...
}

void StarshipAscension::updateEngineStatus() {
    // TODO: Implement engine status update logic
}

void StarshipAscension::updateLifeSupportStatus() {
    // TODO: Implement life support status update logic
}

void StarshipAscension::updateDamageControl() {
    // TODO: Implement damage control update logic
}

void StarshipAscension::updateAstrometrics() {
    // TODO: Implement astrometrics update logic
}

void StarshipAscension::updateScience() {
    // TODO: Implement science update logic
}

void StarshipAscension::updateHailingFrequencies() {
    // TODO: Implement hailing frequencies update logic
}

void StarshipAscension::updateRadio() {
    // TODO: Implement radio update logic
}

void StarshipAscension::updateViewscreens() {
    // TODO: Implement viewscreen update logic
}

void StarshipAscension::updateSickbayStatus() {
    // TODO: Implement sickbay status update logic
}
