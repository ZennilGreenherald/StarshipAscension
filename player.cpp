#include "player.h"

Player::Player() {
    score = 0;
}

int Player::getScore() const {
    return score;
}

void Player::setScore(int score) {
    this->score = score;
}
