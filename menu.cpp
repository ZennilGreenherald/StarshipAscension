#include "menu.h"
#include <iostream>

Menu::Menu() {}

void Menu::displayMenu() {
    std::cout << "Welcome to the game!" << std::endl;
    std::cout << "1. Start new game" << std::endl;
    std::cout << "2. Load saved game" << std::endl;
    std::cout << "3. Display high scores" << std::endl;
}

int Menu::getNumPlayers() {
    int numPlayers;
    std::cout << "Enter the number of players: ";
    std::cin >> numPlayers;
    return numPlayers;
}

std::vector<std::string> Menu::getPlayerNames(int numPlayers) {
    std::vector<std::string> playerNames;
    for (int i = 0; i < numPlayers; i++) {
        std::string playerName;
        std::cout << "Enter name for player " << i+1 << ": ";
        std::cin >> playerName;
        playerNames.push_back(playerName);
    }
    return playerNames;
}

bool Menu::loadSavedGame() {
    char choice;
    std::cout << "Do you want to load a saved game? (y/n): ";
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        // Load saved game
        return true;
    }
    return false;
}

void Menu::displayHighScores() {
    std::cout << "High scores:" << std::endl;
    // Display high scores
}
