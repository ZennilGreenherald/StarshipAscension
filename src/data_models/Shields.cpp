#include "../../include/data_models/Shields.h"

int Shields::lastId_ = 0;

Shields::Shields(int initialHealth)
    : health(initialHealth), shieldId_(++lastId_) {}

Shields::~Shields() {}

int Shields::getId() const {
    return shieldId_;  // Assuming shieldId_ is a member variable
}

bool Shields::areUp() const { return health > 0; }

void Shields::raise() {
    if (health < 100) {  // Assuming  100 is the maximum health
        health = 100;
    }
}

void Shields::lower() {
    if (health > 0) {
        health = 0;
    }
}

void Shields::repair(int amount) {
    health += amount;
    if (health > 100) {  // Assuming  100 is the maximum health
        health = 100;
    }
}

void Shields::takeDamage(int amount) {
    health -= amount;
    if (health < 0) {
        health = 0;
    }
}

int Shields::getHealth() const { return health; }

std::string Shields::getStatus() const {
    return areUp() ? "Shields up!" : "Shields down!";
}
