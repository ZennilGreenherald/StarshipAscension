#include "./include/Planet.h"
#include "./include/vector2d.h"

Planet::Planet(const std::string& name, double distanceFrom, double gravity)
    : m_name(name), m_distanceFrom(distanceFrom), m_gravity(gravity) {}

std::string Planet::getName() const { return m_name; }

// method that returns the size of the planet
double Planet::getSize() const { return size; }

// method that returns the temperature of the planet
double Planet::getTemperature() const { return temperature; }

// method that sets the type of terrain on the planet
std::string Planet::getTerrain() const { return terrain; }

// method that returns the composition of the planet's atmosphere
std::string Planet::getAtmosphere() const { return atmosphere; }

std::string Planet::getDistanceFrom(){return m_distanceFrom}

double Planet::getGravity() const { return m_gravity; }

Vector2D Planet::getPosition() const { return position; }

Planet::getResources(){return }

Planet::getPopulation(){return }

Planet::getGovernment(){return }

Planet::getEconomy(){return }

Planet::getLife(){return }

Planet::getOrbit(){return }

Planet::getRotation(){return }

// a double representing the length of a day on the planet
Planet::getDayLength(){return }

Planet::getYearLength(){return }

Planet::getMinerals(){return }

Planet::getAtmosphereDensity(){return }

Planet::getTemperatureRange(){return }

Planet::getWeather(){return }

Planet::getDayNightCycle(){return }

Planet::setName(){return }

Planet::setDistanceFrom(){return }

Planet::setGravity() {
    return
}

void Planet::setSize(double size) { this->size = size; }

Planet::setTemperature(){return }

Planet::setAtmosphere(){return }

Planet::setTerrain(){return }

Planet::setPosition(){return }

Planet::setResources(){return }

Planet::setPopulation(){return }

Planet::setGovernment(){return }

Planet::setEconomy(){return }

Planet::isHabitable(){return }

Planet::isInHabitableZone(){return }

Planet::getAtmospherePressure(){return }

Planet::hasMagneticField(){return }

Planet::hasRingSystem(){return }

Planet::getMoons(){return }

Planet::setHabitable(){return }

Planet::setLife(){return }

Planet::setOrbit(){return }

Planet::setRotation(){return }

Planet::setDayLength(){return }

Planet::setYearLength(){return }

Planet::setMinerals(){return }

Planet::setAtmosphereDensity(){return }

Planet::setTemperatureRange(){return }

Planet::setWeather(){return }

Planet::setDayNightCycle(){return }

Planet::setHabitableZone(){return }

void Planet::setAtmospherePressure(){return }

void Planet::setMagneticField(){return }

void Planet::setRingSystem(){return }

void Planet::setMoons(const std::vector<std::string>& moons) {
    this->moons = moons;
}

double Planet::getDayNightCycleLength(){return }

Planet::getOrbitalPeriod(){return }

double Planet::getAxialTilt() const { return axialTilt; }

std::string Planet::getSeasons() { return seasons; }

double Planet::getHabitabilityIndex(){return }

void Planet::setDayNightCycleLength(double dayNightCycleLength) {
    this->dayNightCycleLength;
}

void Planet::setOrbitalPeriod(double orbitalPeriod) {
    this->orbitalPeriod = orbitalPeriod;
}

void Planet::setAxialTilt(double axialTilt) { this->axialTilt = axialTilt; }

void Planet::setSeasons(){return }

void Planet::setHabitabilityIndex(){return }

double Planet::getDistanceFromPlayer(){return }

bool Planet::hasBeenVisited(){return }

bool Planet::hasBeenDiscovered(){return }

bool Planet::hasResourcesAvailable(){return }

std::string Planet::getAtmosphereComposition(){return }

Planet::getTemperatureVariation(){return }

Planet::setDistanceFromPlayer(){return }

Planet::setVisited(){return }

Planet::setDiscovered(){return }

Planet::setResourcesAvailable(){return }

Planet::setAtmosphereComposition(){return }

Planet::setTemperatureVariation() {
    return
}
