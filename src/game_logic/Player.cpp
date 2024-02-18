#include "../../include/data_models/Player.h"

#include "../../include/data_models/Planet.h"
#include "../../include/utils/Vector2D.h"

Player::Player(const std::string& name, const Vector2D& position)
    : GameObj(name, position){
          // Initialize player state
};

Player::~Player() {
    // Clean up player state
}

void Player::moveUp() {
    // Logic to move the player up
    Vector2D newPosition = getPosition();
    newPosition.y -= 1;  // Assuming y-axis is inverted
    setPosition(newPosition);
}

void Player::moveDown() {
    // Logic to move the player down
    Vector2D newPosition = getPosition();
    newPosition.y += 1;  // Assuming y-axis is inverted
    setPosition(newPosition);
}

void Player::moveLeft() {
    // Logic to move the player left
    Vector2D newPosition = getPosition();
    newPosition.x -= 1;
    setPosition(newPosition);
}

void Player::moveRight() {
    // Logic to move the player right
    Vector2D newPosition = getPosition();
    newPosition.x += 1;
    setPosition(newPosition);
}