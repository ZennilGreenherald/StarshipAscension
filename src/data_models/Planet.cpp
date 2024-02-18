#include "../data_models/Planet.h"
#include "../utils/Vector2D.h"

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
void Planet::setDistanceFrom(double distanceFrom) { m_distanceFrom = distanceFrom; }
void Planet::setGravity(double gravity) { m_gravity = gravity; }
void Planet::setPosition(const Vector2D& position) { this->position = position; }
void Planet::setMoons(const std::vector<std::string>& moons) { this->moons = moons; }
void Planet::setDayNightCycleLength(double dayNightCycleLength) { this->dayNightCycleLength = dayNightCycleLength; }
void Planet::setOrbitalPeriod(double orbitalPeriod) { this->orbitalPeriod = orbitalPeriod; }
void Planet::setAxialTilt(double axialTilt) { this->axialTilt = axialTilt; }
void Planet::setSeasons(const std::string& seasons) { this->seasons = seasons; }
void Planet::setHabitabilityIndex(double habitabilityIndex) { this->habitabilityIndex = habitabilityIndex; }

// Other methods
bool Planet::isHabitable() const { /* implement this method */ }
bool Planet::isInHabitableZone() const { /* implement this method */ }
bool Planet::hasResourcesAvailable() const { /* implement this method */ }
bool Planet::hasBeenVisited() const { /* implement this method */ }
bool Planet::hasBeenDiscovered() const { /* implement this method */ }
std::string Planet::getAtmosphereComposition() const { /* implement this method */ }
double Planet::getTemperatureVariation() const { /* implement this method */ }
double Planet::getDistanceFromPlayer() const { /* implement this method */ }
