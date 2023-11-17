#include "./include/StarshipAscension.h"

#include <iostream>
#include <string>

#include "./include/player.h"
#include "./include/weapons_manager.h"
#include "./include/station.h"

StarshipAscension::StarshipAscension(std::string name, std::string captain, std::string firstOfficer)
    : name(std::move(name)), captain(std::move(captain)),
      firstOfficer(std::move(firstOfficer)), maxHealth(100), health(100),
      ammo(100), fuel(100), alertStatus(0)
{
}

void StarshipAscension::setX(const uint32_t x)
{
    m_x = x;
}

uint32_t StarshipAscension::getX() const
{
    return m_x;
}

uint32_t StarshipAscension::getY() const
{
    return m_y;
}

void StarshipAscension::setY(const uint32_t y)
{
    m_y = y;
}

int StarshipAscension::getMaxHealth() const
{
    return maxHealth;
}

int StarshipAscension::getHealth() const
{
    return health;
}

int StarshipAscension::getDamage() const
{
    return maxHealth - health;
}

std::string StarshipAscension::getName() const
{
    return name;
}

int StarshipAscension::getFuel() const
{
    return fuel;
}

int StarshipAscension::getAmmo() const { return ammo; }

void StarshipAscension::repair(int amount) {
    health = std::min(health + amount, maxHealth);
}

void StarshipAscension::refuel(int amount) {
    fuel = std::min(fuel + amount, maxFuel);
}

void StarshipAscension::restock(int amount) {
    ammo = std::min(ammo + amount, maxAmmo);
}

void StarshipAscension::dock(Station* station) {
    // Implement the docking logic between the StarshipAscension and the station
    // ...
    // Example: station.dockStarshipAscension(*this);
}

double StarshipAscension::calculateDistance() const {
    // Calculate the distance between the StarshipAscension and the docking port
    // ...
    // Example: return std::sqrt(std::pow(StarshipAscensionX - dockingPortX, 2) +
    // std::pow(StarshipAscensionY - dockingPortY, 2));
    return 0.0;
}

void StarshipAscension::activateDockingClamps() {
    // Activate the docking clamps of the StarshipAscension
    // ...
    // Example: std::cout << "Docking clamps activated!" << std::endl;
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
