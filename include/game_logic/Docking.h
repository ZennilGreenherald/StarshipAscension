#ifndef DOCKING_H
#define DOCKING_H

#include "../../include/game_logic/Shuttlecraft.h"
#include "../../include/game_logic/Spaceship.h"
#include "../../include/game_logic/Starbase.h"
#include "../../include/game_logic/StarshipAscension.h"
#include "../../include/game_logic/Station.h"

class Docking {
  public:
    Docking();   // Constructor
    ~Docking();  // Destructor

void dockAt(Shuttlecraft & shuttle, Shuttlebay & shuttlebay);

    void dockAt(StarshipAscension& starship, Station& station);

  private:
    // Add any private members or methods here
};

#endif
