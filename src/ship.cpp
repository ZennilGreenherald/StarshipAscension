#include "./include/ship.h"

#include "./include/player.h"
#include "./include/weapons_manager.h"
#include "iostream"

StarshipAscension::StarshipAscension(std::string name) : name(name), health(100), ammo(100), fuelStatus(100), alertStatus(0) {}

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

std::string StarshipAscension::getName() const {
    return name_;
}

int StarshipAscension::getHealth() const {
    return health_;
}

int StarshipAscension::getAmmo() const {
    return ammo_;
}

int StarshipAscension::getFuelStatus() const {
    return fuelStatus_;
}

int StarshipAscension::getAlertStatus() const {
    return alertStatus_;
}

void StarshipAscension::setHealth(int health) {
    health_ = health;
}

void StarshipAscension::setAmmo(int ammo) {
    ammo_ = ammo;
}

void StarshipAscension::setFuelStatus(int fuelStatus) {
    fuelStatus_ = fuelStatus;
}

void StarshipAscension::setAlertStatus(int alertStatus) {
    alertStatus_ = alertStatus;
}

void StarshipAscension::updateShields() {
    // TODO: Implement shield update logic
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
