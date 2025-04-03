#include "../../include/sensors/Sensor.h"

Sensor::Sensor() {
    // Constructor implementation
}

Sensor::~Sensor() {
    // Destructor implementation
}

bool Sensor::detectObstacle(Position currentPosition, Position destination) {
    // Basic check for obstacles (this could be more advanced with raycasting, etc.)
    // For example, check if there's an object between the current position and the destination.
    // Let's assume a simple example where it returns true if distance < threshold

    float distance = currentPosition.distanceTo(destination);
    if (distance < 50.0f) {  // Just an arbitrary threshold for demonstration
        return true;  // Obstacle detected
    }
    return false;  // No obstacle
}
