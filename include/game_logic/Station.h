#ifndef STATION_H
#define STATION_H

#include <string>
#include <vector>

class Spaceship;

class Station {
  public:
    Station(const std::string& name);
    ~Station();

    // Method to add a spaceship to the station
    bool addSpaceship(Spaceship* spaceship);

    // Method to remove a spaceship from the station
    bool removeSpaceship(Spaceship* spaceship);

    // Method to check if a spaceship is docked at the station
    bool isSpaceshipDocked(const std::string& spaceshipName) const;

    // Method to get the list of spaceships docked at the station
    const std::vector<Spaceship*>& getDockedSpaceships() const;

  private:
    std::string name;
    std::vector<Spaceship*> dockedSpaceships;
};

#endif  // STATION_H
