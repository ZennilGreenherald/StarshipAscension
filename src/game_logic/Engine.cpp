#include "include/Engine.h"

// Constructor
Engine::Engine(int thrust, int fuelConsumptionRate, int maxFuelLevel)
    : m_thrust(thrust),
      m_fuelConsumptionRate(fuelConsumptionRate),
      m_maxFuelLevel(maxFuelLevel),
      m_isRunning(false) {}

// Destructor
Engine::~Engine() {
    // Destructor code
}

// Methods
void Engine::start() {
    if (m_currentFuelLevel > 0) {
        m_isRunning = true;
    }
}

void Engine::decelerate() {
    // Code to decelerate the engine
}

void Engine::stop() { m_isRunning = false; }

int Engine::calculateFuelUsage() {
    if (m_isRunning) {
        return m_fuelConsumptionRate;
    } else {
        return 0;
    }
}

bool Engine::isOperational() const { return m_currentFuelLevel > 0; }

// Getters
int Engine::getThrust() const { return m_thrust; }
int Engine::getFuelConsumptionRate() const { return m_fuelConsumptionRate; }
int Engine::getCurrentFuelLevel() const { return m_currentFuelLevel; }

// Setters
void Engine::setThrust(int thrust) { m_thrust = thrust; }
void Engine::setFuelConsumptionRate(int fuelConsumptionRate) {
    m_fuelConsumptionRate = fuelConsumptionRate;
}
void Engine::setCurrentFuelLevel(int currentFuelLevel) {
    m_currentFuelLevel = currentFuelLevel;
}
