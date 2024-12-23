#include <iostream>

#include "../include/game_logic/Engine.h"
#include "../include/game_logic/Game.h"
#include "../include/ui/Display.h"
#include "../include/ui/Menu.h"

using namespace std;

int main() {
    Engine engine(100, 5, 100, 80);
    Display display;
    Game game;
    Menu menu(display, game);

    engine.start();

    bool isPlaying = true;
    while (isPlaying) {
        menu.displayMenu();

        // Handle user input and process game actions
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                menu.handleMenuAction(Menu::Action::StartGame);
                break;
            case 2:
                menu.handleMenuAction(Menu::Action::SelectPlayers);
                break;
            case 3:
                menu.handleMenuAction(Menu::Action::LoadGame);
                break;
            case 4:
                menu.handleMenuAction(Menu::Action::SaveGame);
                break;
            case 5:
                menu.handleMenuAction(Menu::Action::ExitGame);
                isPlaying = false;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        // Convert choice to InputType and call handleInput
        game.handleInput(static_cast<Game::InputType>(choice), choice);
    }

    return 0;
}
