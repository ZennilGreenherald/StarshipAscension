#include "../../include/data_models/Position.h"

Position::Position() : x(0.0f), y(0.0f), z(0.0f) {
    // Default constructor implementation
}

Position::Position(float x, float y, float z) : x(x), y(y), z(z) {
    // Custom constructor implementation
}

Position::~Position() {
    // Destructor implementation
}

float Position::getX() const { return x; }

float Position::getY() const { return y; }

float Position::getZ() const { return z; }

void Position::setX(float x) { this->x = x; }

void Position::setY(float y) { this->y = y; }

void Position::setZ(float z) { this->z = z; }
