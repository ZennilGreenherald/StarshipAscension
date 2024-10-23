#include "../../include/ui/Menu.h"

#include <iostream>

Menu::Menu(Display& displayRef, Game& gameRef)
    : display(displayRef), game(gameRef) {}

Menu::~Menu() {}

void Menu::displayMenu() {
    // Use the Display class to print the menu options
    display.clearScreen();
    display.printLine("1. Start Game");
    display.printLine("2. Select Players");
    display.printLine("3. Load Game");
    display.printLine("4. Save Game");
    display.printLine("5. Exit Game");
    display.printLine("Enter your choice: ");
}

void Menu::handleInput() {
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            startGame();
            break;
        case 2:
            selectPlayers();
            break;
        case 3:
            loadGame();
            break;
        case 4:
            saveGame();
            break;
        case 5:
            exitGame();
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
    }
}

void Menu::startGame() {
    // Start the game
    game.start();
}

void Menu::selectPlayers() {
    // Select the number of players
    // Implement the logic to select players
}

void Menu::loadGame() {
    // Load the game state
    // Implement the logic to load the game
}

void Menu::saveGame() {
    // Save the game state
    // Implement the logic to save the game
}

void Menu::exitGame() {
    // Exit the game
    // Implement the logic to exit the game
}
