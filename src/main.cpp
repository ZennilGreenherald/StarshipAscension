#include <iostream>
#include "../include/game_logic/Engine.h"
#include "../include/game_logic/Game.h"
#include "../include/ui/Display.h"
#include "../include/ui/Menu.h"

using namespace std;

int main() {
    // Initialize the engine, display, game, and menu
    Engine engine(100, 5, 100, 80);
    Display display;
    Game game;
    Menu menu(display, game);

    // Start the engine
    engine.start();
    if (!engine.isOperational()) {
        cerr << "Error: Engine failed to start. Please check fuel levels." << endl;
        return 1;  // Exit with an error code
    }

    // Main game loop
    bool isPlaying = true;
    while (isPlaying) {
        // Display the menu
        menu.displayMenu();

        // Get and handle user input through the menu
        Menu::Action action = menu.handleInput();
        menu.handleMenuAction(action);

        // Handle specific actions
        switch (action) {
            case Menu::Action::StartGame:
                game.start();
                display.printLine("Game started!");
                break;
            case Menu::Action::SelectPlayers:
                display.printLine("Feature to select players is under development.");
                break;
            case Menu::Action::LoadGame:
                display.printLine("Feature to load a game is under development.");
                break;
            case Menu::Action::SaveGame:
                display.printLine("Feature to save a game is under development.");
                break;
            case Menu::Action::ExitGame:
                isPlaying = false;  // Exit the game loop
                display.printLine("Exiting the game. Goodbye!");
                break;
            default:
                display.printLine("Invalid action. Please try again.");
        }

        // Update the game state
        game.update();

        // Render the current game state on the display
        display.render(game.isRunning() ? GameState{true, 0} : GameState{false, 0});
    }

    // Stop the engine before exiting
    engine.stop();
    display.printLine("Engine stopped. Thank you for playing!");

    return 0;
}
