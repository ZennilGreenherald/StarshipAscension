#include "../../include/ui/Menu.h"

#include <iostream>
#include <limits>
#include <stdexcept>

Menu::Menu(Display& displayRef, Game& gameRef)
    : display(displayRef), game(gameRef) {}

Menu::~Menu() {}

void Menu::displayMenu() {
    display.clearScreen();
    display.printLine("1. Start Game");
    display.printLine("2. Select Players");
    display.printLine("3. Load Game");
    display.printLine("4. Save Game");
    display.printLine("5. Exit Game");
    display.printLine("Enter your choice: ");
}

Menu::Action Menu::handleInput() {
    int choice;
    while (!(std::cin >> choice) || choice < 1 || choice > 5) {
        std::cout << "Invalid choice. Please try again." << std::endl;
        std::cin.clear();  // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                        '\n');  // Ignore the rest of the line
    }

    switch (choice) {
        case 1:
            return Menu::Action::StartGame;
        case 2:
            return Menu::Action::SelectPlayers;
        case 3:
            return Menu::Action::LoadGame;
        case 4:
            return Menu::Action::SaveGame;
        case 5:
            return Menu::Action::ExitGame;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            return Menu::Action::Invalid;
    }
}

void Menu::handleMenuAction(Menu::Action action) {
    switch (action) {
        case Menu::Action::StartGame:
            game.handleInput(Game::InputType::None,
                             0);  // No specific input required
            break;
        case Menu::Action::SelectPlayers:
            game.handleInput(Game::InputType::PlayerMovement,
                             0);  // Implement player selection logic
            break;
        case Menu::Action::LoadGame:
            game.handleInput(Game::InputType::None,
                             0);  // No specific input required
            break;
        case Menu::Action::SaveGame:
            game.handleInput(Game::InputType::None,
                             0);  // No specific input required
            break;
        case Menu::Action::ExitGame:
            game.handleInput(Game::InputType::None,
                             0);  // No specific input required
            break;
        default:
            // Handle invalid action
            break;
    }
}
