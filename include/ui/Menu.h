#ifndef MENU_H
#define MENU_H

#include <limits>
#include <string>
#include "../../include/game_logic/Game.h"
#include "../../include/ui/Display.h"

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

    Menu(Display& displayRef, Game& gameRef);
    ~Menu();

    void displayMenu();
    Action handleInput();
    void handleMenuAction(Action action);

  private:
    Display& display;
    Game& game;
};

#endif  // MENU_H
