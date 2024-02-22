#ifndef SHUTTLECRAFT_H
#define SHUTTLECRAFT_H

#include "../../include/game_logic/Spaceship.h"

class Shuttlecraft : public Spaceship {
  public:
    Shuttlecraft();
    ~Shuttlecraft();

    // Functions specific to the Shuttlecraft
    void dock();
    void undock();
    void performMaintenance();

    // Override or add to the base class functions if needed
    // void move() override;
    // void fireWeapon() override;
};

#endif  // SHUTTLECRAFT_H
