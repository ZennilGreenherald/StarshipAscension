#ifndef STATION_H
#define STATION_H

#include <cstdint>
#include <string>

class Spaceship;

class Station {
public:
    Station(std::string name = "", int maxHealth = 0, int maxFuel = 0, int maxAmmo = 0);
    std::string getName() const;
    int getHealth() const;
    int getFuel() const;
    int getAmmo() const;
    void repair(Spaceship* spaceship, int amount);
    void repair(int amount);
    void refuel(Spaceship* spaceship, int amount);
    void refuel(int amount);
    void restock(Spaceship* spaceship, int amount);
    void restock(int amount);
    Station();
    Station(uint32_t x, uint32_t y) : x_{ x }, y_{ y } {}

    uint32_t getX() const { return x_; }
    uint32_t getY() const { return y_; }

private:
    std::string name_;
    int health_;
    int fuel_;
    int ammo_;
    int maxHealth_;
    int maxFuel_;
    int maxAmmo_;
    uint32_t x_;
    uint32_t y_;
};

Station::Station() : x_{ 0 }, y_{ 0 } {}

#endif // STATION_H
