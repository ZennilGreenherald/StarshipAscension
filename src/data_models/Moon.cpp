#include "../../include/data_models/Moon.h"
// Constructor
Moon::Moon(const std::string& name, double distanceFrom, double gravity)
    : m_name(name), m_distanceFrom(distanceFrom), m_gravity(gravity) {}

// Getters
std::string Moon::getName() const { return m_name; }
double Moon::getDistanceFrom() const { return m_distanceFrom; }
double Moon::getGravity() const { return m_gravity; }

// Setters
void Moon::setName(const std::string& name) { m_name = name; }
void Moon::setDistanceFrom(double distanceFrom) { m_distanceFrom = distanceFrom; }
void Moon::setGravity(double gravity) { m_gravity = gravity; }
