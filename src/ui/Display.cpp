#include "../../include/ui/Display.h"

#include <iostream>  // Assuming using standard output for display

#include "../../include/game_logic/Game.h"  // Include Display.h for class definition

void Display::show() {
    // Implement logic to display initial menu or information
    std::cout << "Welcome to the Game!" << std::endl;
}

void Display::render(const Game::GameState& gameState) {
    // Implement logic to render the game state on the display (using gameState)
    // This could involve displaying game objects, scores, etc.
    // (Example using standard output)
    std::cout << "Game State:" << std::endl;
    // ... (Use data from gameState to display information) ...
}

void Display::clearScreen() {
    // Implementation to clear the screen (e.g., using system calls)
    std::cout << "\033[2J\033[1;1H";  // For Unix-based systems
}

void Display::printLine(const std::string& text) {
    std::cout << text << std::endl;
}
