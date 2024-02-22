#ifndef MISSIONS_H
#define MISSIONS_H

#include <string>

class Missions {
  public:
    Missions();   // Constructor
    ~Missions();  // Destructor

    void startMission(int missionID);
    void completeMission(int missionID);

  private:
    // Add any private members or methods here
};

#endif
