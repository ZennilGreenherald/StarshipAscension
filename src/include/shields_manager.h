#ifndef SHIELDS_MANAGER_H
#define SHIELDS_MANAGER_H

#include <string>
#include "ship.h"

class Shield {
public:
    Shield(std::string name, int defense, int level);

    std::string getName() const;
    int getDefense() const;
    int getLevel() const;

private:
    std::string name_;
    int defense_;
    int level_;
};

class ShieldsManager {
public:
    void addShield(std::string name, int defense, int level);
    bool removeShield(std::string name);
    Shield* findShield(std::string name);
    void updateShields(StarshipAscension& spaceship);

private:
    Shield* shield_;
};

#endif
