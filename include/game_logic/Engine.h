#ifndef ENGINE_H
#define ENGINE_H

class Engine {
  public:
    // Constructor
    Engine(int thrust, int fuelConsumptionRate, int maxFuelLevel, int initialFuelLevel = 100);
    ~Engine();

    // Methods
    void start();
    void stop();
    void accelerate();
    void decelerate();
    int calculateFuelUsage();
    bool isOperational() const;

    // Getters
    int getThrust() const;
    int getFuelConsumptionRate() const;
    int getCurrentFuelLevel() const;

    // Setters
    void setThrust(int thrust);
    void setFuelConsumptionRate(int fuelConsumptionRate);
    void setCurrentFuelLevel(int currentFuelLevel);

  private:
    int m_thrust;
    int m_fuelConsumptionRate;
    int m_maxFuelLevel;
    bool m_isRunning;
    int m_currentFuelLevel;  // Declare the missing member variable
};

#endif  // ENGINE_H
