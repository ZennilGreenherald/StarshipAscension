#include <iostream>

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

private:
    std::string name_;
    int health_;
    int fuel_;
    int ammo_;
    int maxHealth_;
    int maxFuel_;
    int maxAmmo_;
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

    return 0;
}