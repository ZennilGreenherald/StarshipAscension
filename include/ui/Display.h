#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>

#include "../../include/game_logic/Game.h"

class Game;  // Forward declaration

class Display {
public:
  // Public methods to interact with the display
  void show();
  void render(const Game::GameState& gameState);
  void clearScreen();  // Add declaration
  void printLine(const std::string& text);  // Assuming GameState is a struct/class in Game.h
  // ... other methods for display functionality ...

private:
  // Private members for display implementation details
  // ... (optional) ...
};

#endif // DISPLAY_H
