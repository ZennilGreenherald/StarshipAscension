#include <iostream>

#include "../include/game_logic/Engine.h"
#include "../include/game_logic/Game.h"
#include "../include/ui/Display.h"
#include "../include/ui/Menu.h"

using namespace std;

int main() {
    // Initialize the game engine
    Engine engine(100, 5, 100, 80);
    Engine highFuelEngine(100, 5, 100, 80);

    // Initialize the game display
    Display display;

    // Initialize the game and menu
    Game game;
    Menu menu(display, game);

    // Start the game engine (likely for initialization)
    engine.start();

    // Display initialization (may not be necessary)
    // display.show();

    // Main game loop
    bool isPlaying = true;
    while (isPlaying) {
        // Show the main menu
        menu.displayMenu();

        // Handle user input and process game actions
        Menu::Action action = menu.handleInput();
        switch (action) {
            case Menu::Action::StartGame:
                // Enter game loop if user selects "Start Game"
                while (game.isRunning()) {
                    // Game logic (handled by Game object)
                    game.handleInput();
                    game.update();
                    display.render(
                        game.getState());  // Render based on game state

                    // Optional frame rate limiter
                    // std::this_thread::sleep_for(std::chrono::milliseconds(16));
                }
                break;
            case Menu::Action::SelectPlayers:
                // Handle player selection logic
                // (implement functionality in Menu.cpp)
                break;
            case Menu::Action::LoadGame:
                // Handle game load logic
                // (implement functionality in Menu.cpp)
                break;
            case Menu::Action::SaveGame:
                // Handle game save logic
                // (implement functionality in Menu.cpp)
                break;
            case Menu::Action::ExitGame:
                isPlaying = false;
                break;
            case Menu::Action::Invalid:
                // Handle invalid user input
                break;
        }
    }

    // Exit the game cleanly
    return 0;
}
