#include "game.hpp"
#include <algorithm>
#include <cstdlib> // For system()

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

// Clear the screen
void Game::clearScreen()
{
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Unix/Linux/Mac
#endif
}

// Display the welcome screen
void Game::displayWelcomeScreen()
{
    std::cout << "=====================================" << std::endl;
    std::cout << "          StarshipAscension          " << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "A galaxy of adventure awaits you, Captain!" << std::endl;
    std::cout << "Prepare to explore the stars and achieve ascension." << std::endl;
    std::cout << "\nPress Enter to continue..." << std::endl;
    std::cin.get(); // Wait for the user to press Enter
    clearScreen();  // Clear the screen after input
}

// Display the main menu
void Game::displayMainMenu()
{
    std::cout << "=====================================" << std::endl;
    std::cout << "               Main Menu              " << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "1. Start New Game" << std::endl;
    std::cout << "2. Load Saved Game" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "\nSelect an option: ";
    int choice;
    std::cin >> choice;

    // Handle menu choices
    switch (choice)
    {
    case 1:
        std::cout << "\nStarting a new game...\n";
        break;
    case 2:
        std::cout << "\nLoading saved game...\n";
        break;
    case 3:
        std::cout << "\nExiting. Goodbye!\n";
        stopGame();
        break;
    default:
        std::cout << "\nInvalid choice. Returning to menu...\n";
        displayMainMenu(); // Recursive call for invalid input
    }
}

// Main game loop
void Game::run()
{
    displayWelcomeScreen(); // Display welcome screen
    displayMainMenu();      // Display the menu

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
        stopGame();
    }
    else
    {
        std::cout << "Invalid command. Try again!" << std::endl;
    }
}

// Update the game's state (placeholder logic)
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
