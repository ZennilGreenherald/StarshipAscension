#include <iostream>
#include "include/game_logic/Game.h"
#include "include/ui/Display.h"
#include "include/ui/Menu.h"
#include "include/game_logic/Engine.h"

using namespace std;

int main() {
    // Initialize the game engine
    Engine engine;

    // Initialize the game display
    Display display;

    // Initialize the game menu
    Menu menu;

    // Start the game
    engine.start();

    // Display the game
    display.show();

    // Show the main menu
    menu.display();

    // Main game loop
    while (engine.isRunning()) {
        // Process user input
        menu.processInput();

        // Update the game state
        engine.update();

        // Redraw the game display
        display.redraw();
    }

    // Exit the game cleanly
    return  0;
}
