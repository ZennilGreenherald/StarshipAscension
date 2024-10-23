#ifndef SHIELDSMANAGER_H
#define SHIELDSMANAGER_H

#include <vector>

#include "../../include/data_models/Shields.h"  // Assuming Shield is a class representing a shield

class ShieldsManager {
  public:
    ShieldsManager();
    ~ShieldsManager();

    // Method to add a shield to the manager
    void addShield(Shields* shield);

    // Method to remove a shield from the manager
    void removeShield(Shields* shield);

    // Method to get a shield by its ID
    Shields* getShield(int id);

    // Method to update all shields
    void updateShields();

    // Other methods as needed for managing shields

  private:
    std::vector<Shields*> shields;  // A collection of pointers to shields
    // Other private members as needed for the shields manager
};

#endif  // SHIELDS_MANAGER_H
