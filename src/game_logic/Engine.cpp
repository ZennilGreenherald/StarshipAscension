#include "../../include/game_logic/Engine.h"

// Constructor
Engine::Engine(int thrust, int fuelConsumptionRate, int maxFuelLevel, int initialFuelLevel)
  : m_thrust(thrust), m_fuelConsumptionRate(fuelConsumptionRate), m_maxFuelLevel(maxFuelLevel), m_isRunning(false) {
  m_currentFuelLevel = initialFuelLevel; // Initialize current fuel level with default value (or provided argument)
}

// Destructor
Engine::~Engine() {
  // Add any destructor logic if needed (e.g., resource cleanup)
}

// Methods
void Engine::start() {
  if (m_currentFuelLevel > 0) {
    m_isRunning = true;
  }
}

void Engine::stop() {
  m_isRunning = false;
}

void Engine::accelerate() {
  // Implement logic to accelerate the engine (increase thrust?)
}

void Engine::decelerate() {
  // Implement logic to decelerate the engine (decrease thrust?)
}

int Engine::calculateFuelUsage() {
  if (m_isRunning) {
    return m_fuelConsumptionRate;
  } else {
    return 0;
  }
}

bool Engine::isOperational() const {
  return m_currentFuelLevel > 0;
}

// Getters
int Engine::getThrust() const {
  return m_thrust;
}

int Engine::getFuelConsumptionRate() const {
  return m_fuelConsumptionRate;
}

int Engine::getCurrentFuelLevel() const {
  return m_currentFuelLevel;
}

// Setters
void Engine::setThrust(int thrust) {
  m_thrust = thrust;
}

void Engine::setFuelConsumptionRate(int fuelConsumptionRate) {
  m_fuelConsumptionRate = fuelConsumptionRate;
}

void Engine::setCurrentFuelLevel(int currentFuelLevel) {
  m_currentFuelLevel = currentFuelLevel;
}
