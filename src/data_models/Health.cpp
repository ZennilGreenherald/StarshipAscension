#include "../../include/data_models/Health.h"

Health::Health(int initialHealth) : health(initialHealth) {}

int Health::getHealth() const { return health; }

void Health::setHealth(int newHealth) { health = newHealth; }

void Health::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;  // Ensure health does not go below  0
    }
}
