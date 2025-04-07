#include "../includes/Menu.h"

#include <iostream>
#include <limits>
#include <string>

#include "../includes/Display.h"
#include "../includes/Game.h"

Menu::Menu(Display& displayRef, Game& gameRef)
    : display(displayRef), game(gameRef) {}

Menu::~Menu() {}

void Menu::displayMenu() {
    // Display the main menu options
    display.clearScreen();
    display.displayText("===== Main Menu =====");
    display.displayText("1. Start Game");
    display.displayText("2. Select Players");
    display.displayText("3. Load Game");
    display.displayText("4. Save Game");
    display.displayText("5. Exit Game");
    display.displayText("====================");
    display.displayText("Enter your choice: ");
}

Menu::Action Menu::handleInput() {
    // Handle user input for menu selection
    int choice;
    std::cin >> choice;

    // Clear input buffer if it's invalid
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return Action::Invalid;
    }

    switch (choice) {
        case 1:
            return Action::StartGame;
        case 2:
            return Action::SelectPlayers;
        case 3:
            return Action::LoadGame;
        case 4:
            return Action::SaveGame;
        case 5:
            return Action::ExitGame;
        default:
            return Action::Invalid;
    }
}

void Menu::handleMenuAction(Action action) {
    // Perform the selected menu action
    switch (action) {
        case Action::StartGame:
            game.startNewGame();
            break;
        case Action::SelectPlayers:
            game.selectPlayers();
            break;
        case Action::LoadGame:
            game.loadGame();
            break;
        case Action::SaveGame:
            game.saveGame();
            break;
        case Action::ExitGame:
            display.displayText("Exiting the game... Goodbye!");
            break;
        case Action::Invalid:
        default:
            display.displayText("Invalid choice, please try again.");
            break;
    }
}
