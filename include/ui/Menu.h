#ifndef MENU_H
#define MENU_H

#include <string>
#include <limits>
#include "../../include/ui/Display.h"
#include "../../include/game_logic/Game.h"

class Menu {
public:
    enum class Action {
      StartGame,
      SelectPlayers,
      LoadGame,
      SaveGame,
      ExitGame,
      Invalid
    };

    Menu(Display& display, Game& game);
    ~Menu();

    void displayMenu();
    Menu::Action handleInput();
    void handleMenuAction(Action action);

private:
    Display& display;
    Game& game;

    // Remove these private methods as they were causing conflicts
    // void startGame();
    // void selectPlayers();
    // void loadGame();
    // void saveGame();
    // void exitGame();
};

#endif // MENU_H
