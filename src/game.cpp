#include "game.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include <algorithm>

// Constructor
Game::Game()
    : playerName("Captain"),
      shipName("Enterprise"),
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

void updateGameState(const std::string &playerInput)
{
    std::string command = sanitizeInput(playerInput);
}

// TODO: Implement scanField function to scan the field
// void Game::scanField(const std::vector<std::vector<char>> &field, int playerX, int playerY)
// {
//     std::cout << "Scanning the surrounding area...\n";

//     for (int x = std::max(0, playerX - 1); x <= std::min((int)field.size() - 1, playerX + 1); ++x)
//     {
//         for (int y = std::max(0, playerY - 1); y <= std::min((int)field[x].size() - 1, playerY + 1); ++y)
//         {
//             if (field[x][y] != ' ' && !(x == playerX && y == playerY))
//             {
//                 std::cout << "Found: " << field[x][y] << " at (" << x << ", " << y << ")\n";
//             }
//         }
//     }
// }


// Main game looo
void Game::run()
{
    displayWelcomeScreen();
    displayMainMenu();

    while (getIsRunning())
    {
        processPlayerInput();
        updateGameState();
        render();
    }
}

// Process player input
void Game::processPlayerInput()
{
    std::cout << "Enter your command (move, quit, menu, scan, help): ";
    std::string command;
    std::cin >> command;

    // Convert command to lowercase for case-insensitive matching
    std::transform(command.begin(), command.end(), command.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    if (command == "move" || command == "")
    {
        playerPosition++;
        std::cout << "You moved to position " << playerPosition << "." << std::endl;
    }
    else if (command == "quit" || command == "q")
    {
        stopGame();
    }
    else if (command == "menu" || command == "m")
    {
        displayMainMenu();
    }
    else if (command == "scan" || command == "s")
    {
        // TODO: Implement scan functionality
        // std::cout << "Scanning the surrounding area... No threats detected!" << std::endl;
        // scanField(playingField, playerX, playerY);
    }
    else if (command == "help" || command == "h")
    {
        displayHelpMenu();
    }
    else
    {
        std::cout << "Invalid command. Try again!" << std::endl;
    }
}

// Update the game's state
void Game::updateGameState()
{
    if (playerPosition >= 10)
    {
        std::cout << "Congratulations, Captain " << playerName << "! You've completed your mission." << std::endl;
        stopGame();
    }
    else
    {
        std::cout << "Exploring new galaxies..." << std::endl;
    }
}

// Render the game
void Game::render()
{
    std::cout << "=============================" << std::endl;
    std::cout << "Rendering Current Game State" << std::endl;
    std::cout << "=============================" << std::endl;
    std::cout << "Player Position: " << playerPosition << std::endl;
    std::cout << "Keep exploring the galaxy, Captain " << playerName << "!" << std::endl;
    std::cout << "=============================" << std::endl;
}
