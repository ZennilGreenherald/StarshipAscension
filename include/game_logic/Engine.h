#ifndef ENGINE_H
#define ENGINE_H

class Engine {
  public:
    Engine(int thrust, int fuelConsumptionRate, int maxFuelLevel, int initialFuelLevel = 100);
    ~Engine();

    void start();
    void stop();
    void accelerate();
    void decelerate();
    int calculateFuelUsage();
    bool isOperational() const;

    int getThrust() const;
    int getFuelConsumptionRate() const;
    int getCurrentFuelLevel() const;

    void setThrust(int thrust);
    void setFuelConsumptionRate(int fuelConsumptionRate);
    void setCurrentFuelLevel(int currentFuelLevel);

  private:
    int m_thrust;
    int m_fuelConsumptionRate;
    int m_maxFuelLevel;
    bool m_isRunning;
    int m_currentFuelLevel;
};

#endif  // ENGINE_H
