#include "game.hpp"
#include <algorithm>

// Constructor
Game::Game()
    : playerName("Captain"),
      playerPosition(0),
      isRunning(true)
{
}

// Destructor
Game::~Game() {}

// Stop the game
void Game::stopGame()
{
    isRunning = false;
}

// Getter for isRunning
bool Game::getIsRunning() const
{
    return isRunning;
}

// Main game loop
void Game::run()
{
    displayWelcomeMessage();
    while (getIsRunning()) // Use the getter method consistently
    {
        processPlayerInput(); // Added: Call to process player input
        updateGameState();    // Added: Update game state as needed
        render();
    }
}

// Display a welcome message
void Game::displayWelcomeMessage()
{
    std::cout << "Welcome to the Space Adventure Game!" << std::endl;
    std::cout << "Prepare to embark on your journey, Captain " << playerName << "!" << std::endl
              << "\n";
}

// Process player input
void Game::processPlayerInput()
{
    std::cout << "Enter your command (move, quit): ";
    std::string command;
    std::cin >> command;

    // Convert command to lowercase for case-insensitive comparison
    std::transform(command.begin(), command.end(), command.begin(),
                   [](unsigned char c)
                   { return std::tolower(c); });

    if (command == "move")
    {
        playerPosition++;
    }
    else if (command == "quit")
    {
        stopGame(); // Updated: Use stopGame to encapsulate logic
    }
    else
    {
        std::cout << "Invalid command. Try again!" << std::endl;
    }
}

// Update the game's state (placeholder logic)
void Game::updateGameState()
{
    // Example logic: Check if player has reached a certain position
    if (playerPosition >= 10)
    {
        std::cout << "Congratulations, Captain " << playerName << "! You've completed your mission." << std::endl;
        stopGame(); // Stop the game if a goal is achieved
    }
    else
    {
        std::cout << "Exploring new galaxies..." << std::endl;
    }
}

// Render the game (text-based output)
void Game::render()
{
    std::cout << "=============================" << std::endl;
    std::cout << "Rendering Current Game State" << std::endl;
    std::cout << "=============================" << std::endl;
    std::cout << "Player Position: " << playerPosition << std::endl;
    std::cout << "Keep exploring the galaxy, Captain " << playerName << "!" << std::endl;
    std::cout << "=============================" << std::endl;
}
