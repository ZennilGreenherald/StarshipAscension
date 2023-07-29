#include <iostream>
#include <string>
#include <cmath>

class Spaceship {
public:
    Spaceship(std::string name, int maxHealth, int maxFuel, int maxAmmo)
        : name_{ name }, health_{ maxHealth }, fuel_{ maxFuel }, ammo_{ maxAmmo },
        maxHealth_{ maxHealth }, maxFuel_{ maxFuel }, maxAmmo_{ maxAmmo }
    {
    }

    std::string getName() const
    {
        return name_;
    }

    int getHealth() const
    {
        return health_;
    }

    int getFuel() const
    {
        return fuel_;
    }

    int getAmmo() const
    {
        return ammo_;
    }

    void repair(int amount)
    {
        health_ = std::min(health_ + amount, maxHealth_);
    }

    void refuel(int amount)
    {
        fuel_ = std::min(fuel_ + amount, maxFuel_);
    }

    void restock(int amount)
    {
        ammo_ = std::min(ammo_ + amount, maxAmmo_);
    }

    void dock(Station& station) {
        double distance = calculateDistance();
        if (distance <= dockingDistanceThreshold) {
            activateDockingClamps();
            std::cout << "Starbase Docking Successful!" << std::endl;
        } else {
            std::cout << "Approach the docking port to activate docking clamps." << std::endl;
        }
    }

private:
    std::string name_;
    int health_;
    int fuel_;
    int ammo_;
    int maxHealth_;
    int maxFuel_;
    int maxAmmo_;

    static constexpr double dockingDistanceThreshold = 1.0;  // Example value, replace with actual value

    double calculateDistance() const {
        // Assuming the position of the spaceship is stored in variables called "x2" and "y2"
        double x1 = dockingPortX;
        double y1 = dockingPortY;
        double x2 = spaceshipX;
        double y2 = spaceshipY;

        double distance = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
        return distance;
    }

    void activateDockingClamps() {
        // Code to activate the docking clamps
        // Implement the logic to activate the clamps here
    }

    static constexpr double dockingPortX = 1.0;  // Example value, replace with actual value
    static constexpr double dockingPortY = 2.0;  // Example value, replace with actual value
    double spaceshipX;
    double spaceshipY;
};

class Station {
public:
    Station(std::string name, int maxHealth, int maxFuel, int maxAmmo)
        : name_{ name }, health_{ maxHealth }, fuel_{ maxFuel }, ammo_{ maxAmmo },
        maxHealth_{ maxHealth }, maxFuel_{ maxFuel }, maxAmmo_{ maxAmmo }
    {
    }

    std::string getName() const
    {
        return name_;
    }

    int getHealth() const
    {
        return health_;
    }

    int getFuel() const
    {
        return fuel_;
    }

    int getAmmo() const
    {
        return ammo_;
    }

    void repair(Spaceship& spaceship, int amount)
    {
        health_ = std::min(health_ + amount, maxHealth_);
        spaceship.repair(amount);
    }

    void refuel(Spaceship& spaceship, int amount)
    {
        fuel_ = std::min(fuel_ + amount, maxFuel_);
        spaceship.refuel(amount);
    }

    void restock(Spaceship& spaceship, int amount)
    {
        ammo_ = std::min(ammo_ + amount, maxAmmo_);
        spaceship.restock(amount);
    }

private:
    std::string name_;
    int health_;
    int fuel_;
    int ammo_;
    int maxHealth_;
    int maxFuel_;
    int maxAmmo_;
};

int main()
{
    Spaceship spaceship{ "Enterprise", 100, 50, 10 };
    Station station{ "Starbase 1", 1000, 10000, 1000 };

    std::cout << "Before docking:\n";
    std::cout << "Spaceship health: " << spaceship.getHealth() << "\n";
    std::cout << "Spaceship fuel: " << spaceship.getFuel() << "\n";
    std::cout << "Spaceship ammo: " << spaceship.getAmmo() << "\n";
    std::cout << "Station health: " << station.getHealth() << "\n";
    std::cout << "Station fuel: " << station.getFuel() << "\n";
    std::cout << "Station ammo: " << station.getAmmo() << "\n\n";

    station.repair(spaceship, 10);
    station.refuel(spaceship, 20);
    station.restock(spaceship, 5);

    std::cout << "After docking:\n";
    std::cout << "Spaceship health: " << spaceship.getHealth() << "\n";
    std::cout << "Spaceship fuel: " << spaceship.getFuel() << "\n";
    std::cout << "Spaceship ammo: " << spaceship.getAmmo() << "\n";
    std::cout << "Station health: " << station.getHealth() << "\n";
    std::cout << "Station fuel: " << station.getFuel() << "\n";
    std::cout << "Station ammo: " << station.getAmmo() << "\n";

    spaceship.dock(station);

    return 0;
}
