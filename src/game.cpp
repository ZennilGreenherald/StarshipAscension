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
    std::cout << "3. Help" << std::endl;
    std::cout << "4. Setup Game" << std::endl;
    std::cout << "5. View Credits" << std::endl;
    std::cout << "6. Exit" << std::endl;
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
        displayHelpMenu();
        break;
    case 4:
        displaySetupMenu();
        break;
    case 5:
        displayCredits();
        break;
    case 6:
        std::cout << "\nExiting. Goodbye!\n";
        stopGame();
        break;
    default:
        std::cout << "\nInvalid choice. Returning to menu...\n";
        displayMainMenu();
    }
}

// Display Help Menu
void Game::displayHelpMenu()
{
    clearScreen();
    std::cout << "=====================================" << std::endl;
    std::cout << "               Help Menu              " << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "Welcome to StarshipAscension!" << std::endl;
    std::cout << "Here are some tips to help you get started:\n";
    std::cout << "- Use 'move' to explore the galaxy." << std::endl;
    std::cout << "- Use 'quit' to end the game." << std::endl;
    std::cout << "- Complete missions to gain points and advance." << std::endl;
    std::cout << "\nPress Enter to return to the Main Menu." << std::endl;
    std::cin.ignore();
    std::cin.get();
    clearScreen();
    displayMainMenu();
}

// Display Setup Menu
void Game::displaySetupMenu()
{
    clearScreen();
    std::cout << "=====================================" << std::endl;
    std::cout << "            Setup Game Menu           " << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "Configure your game settings here.\n";

    std::cout << "Enter the number of players: ";
    int numPlayers;
    std::cin >> numPlayers;

    std::cout << "Enter your ship's name: ";
    std::string shipName;
    std::cin.ignore();
    std::getline(std::cin, shipName);

    std::cout << "\nConfiguration complete!\n";
    std::cout << "Players: " << numPlayers << "\nShip Name: " << shipName << std::endl;
    std::cout << "\nPress Enter to return to the Main Menu." << std::endl;
    std::cin.get();
    clearScreen();
    displayMainMenu();
}

// Display Credits
void Game::displayCredits()
{
    clearScreen();
    std::cout << "=====================================" << std::endl;
    std::cout << "               Credits                " << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "StarshipAscension was created by [Your Name]!" << std::endl;
    std::cout << "Special thanks to our interstellar community!\n";
    std::cout << "\nPress Enter to return to the Main Menu." << std::endl;
    std::cin.ignore();
    std::cin.get();
    clearScreen();
    displayMainMenu();
}

// Main game loop
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
    std::cout << "Enter your command (move, quit): ";
    std::string command;
    std::cin >> command;

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
