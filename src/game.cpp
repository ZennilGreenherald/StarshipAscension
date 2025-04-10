#include "game.hpp"

// Constructor
Game::Game() : isRunning(true), playerName("Captain"), playerPosition(0) {}

// Destructor
Game::~Game() {}

// Main game loop
void Game::run()
{
    displayWelcomeMessage();
    while (isRunning)
    {
        processPlayerInput();
        updateGameState();
        render();
    }
}

// Display a welcome message
void Game::displayWelcomeMessage()
{
    std::cout << "Welcome to the Space Adventure Game!" << std::endl;
    std::cout << "Prepare to embark on your journey, Captain " << playerName << "!" << std::endl;
}

// Process player input
void Game::processPlayerInput()
{
    std::cout << "Enter your command (move, quit): ";
    std::string command;
    std::cin >> command;

    if (command == "move")
    {
        playerPosition++;
        std::cout << "You move forward to position " << playerPosition << "." << std::endl;
    }
    else if (command == "quit")
    {
        isRunning = false;
    }
    else
    {
        std::cout << "Invalid command. Try again!" << std::endl;
    }
}

// Update game state
void Game::updateGameState()
{
    // Placeholder for more complex game state updates
}

// Render the game (text-based output)
void Game::render()
{
    std::cout << "Rendering current state..." << std::endl;
    std::cout << "Player position: " << playerPosition << std::endl;
}
