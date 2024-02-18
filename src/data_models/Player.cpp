#include "./include/player.h"

#include <string>

Player::Player(std::string name)
	: m_name(name),
	  m_health(100),
	  m_score(0),
	  m_damage(10),
	  m_level(1),
	  m_experience(0) {}

std::string Player::getName() const { return m_name; }

void Player::setName(std::string name) { m_name = name; }
