#include "../../include/data_models/Planet.h"

#include "../../include/ui/PlayingField.h"
#include "../../include/utils/Vector2D.h"

// Constructor
Planet::Planet(const std::string& name, double distanceFrom, double gravity)
    : m_name(name), m_distanceFrom(distanceFrom), m_gravity(gravity) {}

// Getters
std::string Planet::getName() const { return m_name; }
double Planet::getSize() const { return size; }
double Planet::getDistanceFrom() const { return m_distanceFrom; }
double Planet::getGravity() const { return m_gravity; }
Vector2D Planet::getPosition() const { return position; }
std::vector<std::string> Planet::getMoons() const { return moons; }
double Planet::getDayNightCycleLength() const { return dayNightCycleLength; }
double Planet::getOrbitalPeriod() const { return orbitalPeriod; }
double Planet::getAxialTilt() const { return axialTilt; }
std::string Planet::getSeasons() { return seasons; }
double Planet::getHabitabilityIndex() const { return habitabilityIndex; }

// Setters
void Planet::setName(const std::string& name) { m_name = name; }
void Planet::setSize(double size) { this->size = size; }
void Planet::setDistanceFrom(double distanceFrom) {
    m_distanceFrom = distanceFrom;
}
void Planet::setGravity(double gravity) { m_gravity = gravity; }
void Planet::setPosition(const Vector2D& newPosition) {
    position = newPosition;
}
void Planet::setMoons(const std::vector<std::string>& moons) {
    this->moons = moons;
}
void Planet::setDayNightCycleLength(double dayNightCycleLength) {
    this->dayNightCycleLength = dayNightCycleLength;
}
void Planet::setOrbitalPeriod(double orbitalPeriod) {
    this->orbitalPeriod = orbitalPeriod;
}
void Planet::setAxialTilt(double axialTilt) { this->axialTilt = axialTilt; }
void Planet::setSeasons(const std::string& seasons) { this->seasons = seasons; }
void Planet::setHabitabilityIndex(double habitabilityIndex) {
    this->habitabilityIndex = habitabilityIndex;
}

// Other methods
bool Planet::isHabitable() const {
    // Example logic: return true if habitabilityIndex is above a certain
    // threshold
    return habitabilityIndex > 0.5;  // Replace with your actual logic
}
bool Planet::isInHabitableZone() const {
    // Example logic: return true if distanceFrom is within a certain range
    return m_distanceFrom >= 100.0 &&
           m_distanceFrom <= 200.0;  // Replace with your actual logic
}

bool Planet::hasResourcesAvailable() const {
    // Example logic: return true if the planet has resources
    return resourceCount > 0;  // Replace with your actual logic
}

bool Planet::hasBeenVisited() const {
    // Example logic: return true if the planet has been visited
    return visited;  // Replace with your actual logic
}
bool Planet::hasBeenDiscovered() const {
    // Example logic: return true if the planet has been discovered
    return discovered;  // Replace with your actual logic
}
std::string Planet::getAtmosphereComposition() const {
    // Example logic: return a string describing the atmosphere composition
    return atmosphereComposition;  // Replace with your actual logic
}
double Planet::getTemperatureVariation() const {
    // Example logic: return the temperature variation
    return temperatureVariation;  // Replace with your actual logic
}
double Planet::getDistanceFromPlayer() const {
    // Example logic: return the distance from the player
    return distanceFromPlayer;  // Replace with your actual logic
}
