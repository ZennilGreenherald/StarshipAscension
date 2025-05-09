#ifndef CREW_MANAGER_HPP
#define CREW_MANAGER_HPP

#include "game_ui.hpp"

class CrewManager
{
public:
    void manageCrew();
    void addCrewMember();
    void assignRoles();
    void viewCrewList();
    void dismissCrewMember();
    void viewCrewStatus();

private:
    void clearScreen();         // Assumed to exist (you use it, so declare it)
    void displayMainMenu();     // Assumed to exist (used in manageCrew)
};

#endif // CREW_MANAGER_HPP
