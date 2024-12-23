#include "../../include/data_models/Player.h"

#include "../../include/data_models/Planet.h"
#include "../../include/utils/Vector2D.h"
#include "../../include/ui/PlayingField.h"
Player::Player(std::string name, const Vector2D& position) {}

Player::~Player() {
    // Clean up player state
}

void Player::moveUp() {
    Vector2D newPosition = m_position;
    newPosition.y += 1;
    setPosition(newPosition);
}

void Player::moveDown() {
    Vector2D newPosition = getPosition();
    newPosition.y += 1;  // Move down
    setPosition(newPosition);
}

void Player::moveLeft() {
    Vector2D newPosition = getPosition();
    newPosition.x -= 1;  // Move left
    setPosition(newPosition);
}

void Player::moveRight() {
    Vector2D newPosition = getPosition();
    newPosition.x += 1;  // Move right
    setPosition(newPosition);
}
