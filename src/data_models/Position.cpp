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

// Calculate the distance between this position and another position
float Position::distanceTo(const Position& other) const {
    return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2) + std::pow(z - other.z, 2));
}

// Add two positions together (component-wise)
Position Position::operator+(const Position& other) const {
    return Position(x + other.x, y + other.y, z + other.z);
}

// Subtract one position from another (component-wise)
Position Position::operator-(const Position& other) const {
    return Position(x - other.x, y - other.y, z - other.z);
}

// Compare two positions for equality
bool Position::operator==(const Position& other) const {
    return (x == other.x && y == other.y && z == other.z);
}

// Translate the position by a given offset in each direction
void Position::translate(float dx, float dy, float dz) {
    x += dx;
    y += dy;
    z += dz;
}

// Reset the position to the origin (0, 0, 0)
void Position::reset() {
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}
