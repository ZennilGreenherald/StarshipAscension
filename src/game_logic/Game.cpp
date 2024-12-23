#include "../../include/game_logic/Game.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

Game::Game() {
    currentState.isGameRunning = false;
    currentState.currentScore = 0;
}

void Game::start() {
    currentState.isGameRunning = true;
    // Additional initialization code
}

bool Game::isRunning() const { return currentState.isGameRunning; }

void Game::handleInput(InputType inputType, int inputValue) {
    // Store input in history
    inputHistory.push_back({inputType, inputValue});

    // Process input based on type
    switch (inputType) {
        case InputType::MenuSelection:
            handleMenuSelection(inputValue);
            break;
        case InputType::PlayerMovement:
            handlePlayerMovement(inputValue);
            break;
        case InputType::None:
        default:
            // Handle invalid or unrecognized input
            break;
    }
}

void Game::handleMenuSelection(int choice) {
    currentState.isGameRunning = false;
    switch (choice) {
        case 1:
            // Handle StartGame
            start();
            break;
        case 2:
            // Handle SelectPlayers
            break;
        case 3:
            // Handle LoadGame
            break;
        case 4:
            // Handle SaveGame
            break;
        case 5:
            // Handle ExitGame
            currentState.isGameRunning = false;
            break;
        default:
            // Handle invalid choice
            break;
    }
}

void Game::handlePlayerMovement(int direction) {
    // Implement player movement logic
    // direction could be 0=up, 1=right, 2=down, 3=left
    // Add your movement implementation here
    std::cout << "Player movement detected: " << direction << std::endl;
}

void Game::update() {
    // Update game state based on input history and current state
    // Implement game logic here

    // Check if there's a recent input to process
    if (!inputHistory.empty()) {
        // Get the most recent input
        auto lastInput = inputHistory.back();

        // Process the input based on its type
        if (lastInput.type == InputType::PlayerMovement) {
            handlePlayerMovement(lastInput.value);
        } else if (lastInput.type == InputType::MenuSelection) {
            handleMenuSelection(lastInput.value);
        }

        // Clear the input history after processing
        inputHistory.pop_back();
    }
}
