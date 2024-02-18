#include <iostream>

#include "../../include/game_logic/Engine.h"
#include "../../include/game_logic/Game.h"
#include "../../include/ui/Display.h"
#include "../../include/ui/Menu.h"

using namespace std;

int main() {
    // Initialize the game engine
    Engine engine;

    // Initialize the game display
    Display display;

    Game game;

    // Initialize the game menu
    Menu menu(display, game);

    // Start the game
    engine.start();

    // Display the game
    display.show();

    // Show the main menu
    menu.display();

    // Main game loop
    while (true) {
        menu.displayMenu();
        menu.handleInput();
        menu.processInput();
        display.redraw();
    }

    // Exit the game cleanly
    return 0;
}
