#include "../../include/data_models/Player.h"  // Include the Player header

#include <algorithm>
#include <string>  // Include string for std::string
#include <vector>  // Include vector for std::vector

#include "../../include/utils/Vector2D.h"

std::string Player::getName() const { return m_name; }

void Player::setName(std::string name) { m_name = name; }

int Player::getHealth() const { return m_health; }

int Player::getScore() const { return m_score; }

int Player::getDamage() const { return m_damage; }

std::vector<std::string> Player::getInventory() const { return m_inventory; }

int Player::getLevel() const { return m_level; }

int Player::getExperience() const { return m_experience; }

std::vector<std::string> Player::getAbilities() const { return m_abilities; }

std::vector<std::string> Player::getEquipment() const { return m_equipment; }

void Player::addItemToInventory(std::string item) {
    m_inventory.push_back(item);
}

void Player::removeItemFromInventory(std::string item) {
    m_inventory.erase(std::remove(m_inventory.begin(), m_inventory.end(), item),
                      m_inventory.end());
}

void Player::setHealth(int newHealth) {
    m_health = newHealth;  // or apply bounds checking
}

void Player::setScore(int score) { m_score = score; }

void Player::setDamage(int damage) { m_damage = damage; }

void Player::setLevel(int level) { m_level = level; }

void Player::setExperience(int experience) { m_experience = experience; }

void Player::addAbility(std::string ability) { m_abilities.push_back(ability); }

void Player::removeAbility(std::string ability) {
    m_abilities.erase(
        std::remove(m_abilities.begin(), m_abilities.end(), ability),
        m_abilities.end());
}

void Player::addEquipment(std::string equipment) {
    m_equipment.push_back(equipment);
}

void Player::removeEquipment(std::string equipment) {
    m_equipment.erase(
        std::remove(m_equipment.begin(), m_equipment.end(), equipment),
        m_equipment.end());
}

void Player::moveUp() { m_position.y += 1; }

void Player::moveDown() { m_position.y -= 1; }

void Player::moveLeft() { m_position.x -= 1; }

void Player::moveRight() { m_position.x += 1; }

Vector2D Player::getPosition() const { return m_position; }

void Player::setPosition(const Vector2D& position) { m_position = position; }
