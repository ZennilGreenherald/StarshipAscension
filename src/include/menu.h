#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

class Menu {
public:
    Menu();
    void displayMenu();
    int getNumPlayers();
    std::vector<std::string> getPlayerNames(int numPlayers);
    bool loadSavedGame();
    void displayHighScores();
};

#endif
