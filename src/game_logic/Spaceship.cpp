#include "../../include/game_logic/Spaceship.h"

#include "../../include/data_models/Position.h"
#include "../../include/game_logic/Engine.h"
#include "../../include/game_logic/Movement.h"
#include "../../include/ui/PlayingField.h"
#include "../../include/utils/Vector2D.h"

Spaceship::Spaceship() : position(), engine(), movement() {}

Spaceship::~Spaceship() {}

void Spaceship::move(Vector2D direction) {
    if (!isValidNewPosition(position + direction)) {
        return;  // Invalid move, do nothing
    }

    position += direction;
}

bool Spaceship::isValidNewPosition(const Vector2D& newPosition) {
    const PlayingField* field = PlayingField::getInstance();
    if (!field || !field->isWithinBounds(newPosition)) {
        return false;
    }

    // Additional checks could be added here, e.g., collision detection
    return true;
}

void Spaceship::updatePosition() {
    Vector2D direction = movement.getDirection();
    move(direction);
}
