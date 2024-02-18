#ifndef MENU_H
#define MENU_H

#include <string>
#include "Display.h" // Assuming Display.h is the header for your display class
#include "Game.h" // Assuming Game.h is the header for your game class

class Menu {
public:
    Menu(Display& display, Game& game);
    ~Menu();

    void displayMenu();
    void handleInput();

private:
    Display& display;
    Game& game;

    // Private methods to handle specific menu options
    void startGame();
    void selectPlayers();
    void loadGame();
    void saveGame();
    void exitGame();
};

#endif // MENU_H