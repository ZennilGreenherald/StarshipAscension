#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>

#include "../../include/game_logic/Game.h"

class Game;  // Forward declaration

class Display {
  public:
    void show();
    typedef GameState GameStateType;
    void render(const GameState& gameState);
    void clearScreen();
    void printLine(const std::string& text);

  private:
    // Private members for display implementation details
    // ... (optional) ...
};

#endif  // DISPLAY_H
