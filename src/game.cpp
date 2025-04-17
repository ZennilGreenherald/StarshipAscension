#include "game.hpp"
#include <algorithm>
#include <cstdlib> // For system()
#include <fstream>
#include <sstream>
#include <string>
// #include <nlohmann/json.hpp>

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

void Game::saveGame()
{
    clearScreen();
    std::cout << "=====================================" << std::endl;
    std::cout << "           Save Game Menu             " << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "Choose a format to save your game:\n";
    std::cout << "1. Plain Text (.txt)\n";
    std::cout << "2. JSON (.json)\n";
    std::cout << "3. XML (.xml)\n";
    std::cout << "4. Binary (.dat)\n";

    int choice;
    std::cin >> choice;

    std::string fileName = "saved_game";
    switch (choice)
    {
    case 1:
        fileName += ".txt";
        saveAsPlainText(fileName); // Call method for plain text saving
        break;
    // case 2:
    //     fileName += ".json";
    //     saveAsJSON(fileName); // Call method for JSON saving
    //     break;
    case 3:
        fileName += ".xml";
        saveAsXML(fileName); // Call method for XML saving
        break;
    case 4:
        fileName += ".dat";
        saveAsBinary(fileName); // Call method for binary saving
        break;
    default:
        std::cout << "Invalid choice. Returning to menu...\n";
        return;
    }

    std::cout << "Game saved successfully to " << fileName << "!\n";
    std::cout << "\nPress Enter to return to the Main Menu.";
    std::cin.ignore();
    std::cin.get();
    displayMainMenu();
}

void Game::loadGame()
{
    clearScreen();
    std::cout << "=====================================" << std::endl;
    std::cout << "           Load Game Menu             " << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "Choose the format of your saved game:\n";
    std::cout << "1. Plain Text (.txt)\n";
    std::cout << "2. JSON (.json)\n";
    std::cout << "3. XML (.xml)\n";
    std::cout << "4. Binary (.dat)\n";

    int choice;
    std::cin >> choice;

    std::string fileName;
    std::cout << "Enter the name of the saved game file (with extension): ";
    std::cin.ignore(); // Clear buffer
    std::getline(std::cin, fileName);

    switch (choice)
    {
    case 1:
        loadFromPlainText(fileName); // Call method for plain text loading
        break;
    // case 2:
    //     loadFromJSON(fileName); // Call method for JSON loading
    //     break;
    case 3:
        loadFromXML(fileName); // Call method for XML loading
        break;
    case 4:
        loadFromBinary(fileName); // Call method for binary loading
        break;
    default:
        std::cout << "Invalid choice. Returning to menu...\n";
        return;
    }

    std::cout << "Game loaded successfully from " << fileName << "!\n";
    std::cout << "\nPress Enter to return to the Main Menu.";
    std::cin.get();
    displayMainMenu();
}

void Game::saveAsPlainText(const std::string &fileName)
{
    std::ofstream saveFile(fileName);
    saveFile << "PlayerName: " << playerName << '\n';
    saveFile << "PlayerPosition: " << playerPosition << '\n';
    saveFile << "Score: 500\n"; // Example score
    saveFile.close();
}

// void Game::saveAsJSON(const std::string &fileName)
// {
//     nlohmann::json saveData;
//     saveData["PlayerName"] = playerName;
//     saveData["PlayerPosition"] = playerPosition;
//     saveData["Score"] = 500;

//     std::ofstream saveFile(fileName);
//     saveFile << saveData.dump(4); // Pretty print JSON
//     saveFile.close();
// }

void Game::saveAsXML(const std::string &fileName)
{
    std::ofstream saveFile(fileName);
    saveFile << "<Game>\n";
    saveFile << "  <Player>\n";
    saveFile << "    <Name>" << playerName << "</Name>\n";
    saveFile << "    <Position>" << playerPosition << "</Position>\n";
    saveFile << "  </Player>\n";
    saveFile << "  <Score>500</Score>\n";
    saveFile << "</Game>\n";
    saveFile.close();
}

void Game::saveAsBinary(const std::string &fileName)
{
    std::ofstream saveFile(fileName, std::ios::binary);
    saveFile.write(reinterpret_cast<const char *>(&playerPosition), sizeof(playerPosition));
    saveFile.close();
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

void Game::loadFromPlainText(const std::string &fileName)
{
    std::ifstream loadFile(fileName);
    if (!loadFile)
    {
        std::cout << "Error: Unable to open file " << fileName << std::endl;
        return;
    }

    std::string line;
    while (std::getline(loadFile, line))
    {
        if (line.find("PlayerName: ") != std::string::npos)
        {
            playerName = line.substr(line.find(": ") + 2);
        }
        else if (line.find("PlayerPosition: ") != std::string::npos)
        {
            playerPosition = std::stoi(line.substr(line.find(": ") + 2));
        }
        // Add more attributes to parse here
    }
    loadFile.close();
}

// Load from JSON
// void Game::loadFromJSON(const std::string &fileName)
// {
//     std::ifstream loadFile(fileName);
//     if (!loadFile)
//     {
//         std::cout << "Error: Unable to open file " << fileName << std::endl;
//         return;
//     }

//     nlohmann::json loadData;
//     loadFile >> loadData;

//     playerName = loadData["PlayerName"].get<std::string>();
//     playerPosition = loadData["PlayerPosition"].get<int>();
//     // Add more attributes to load here

//     loadFile.close();
// }

// Load from XML
void Game::loadFromXML(const std::string &fileName)
{
    std::ifstream loadFile(fileName);
    if (!loadFile)
    {
        std::cout << "Error: Unable to open file " << fileName << std::endl;
        return;
    }

    std::string line, xmlContent;
    while (std::getline(loadFile, line))
    {
        xmlContent += line + "\n";
    }

    // Parse XML manually for simplicity
    if (xmlContent.find("<Name>") != std::string::npos)
    {
        playerName = xmlContent.substr(xmlContent.find("<Name>") + 6, xmlContent.find("</Name>") - (xmlContent.find("<Name>") + 6));
    }
    if (xmlContent.find("<Position>") != std::string::npos)
    {
        playerPosition = std::stoi(xmlContent.substr(xmlContent.find("<Position>") + 10, xmlContent.find("</Position>") - (xmlContent.find("<Position>") + 10)));
    }
    // Add more attributes to parse here

    loadFile.close();
}

// Load from binary
void Game::loadFromBinary(const std::string &fileName)
{
    std::ifstream loadFile(fileName, std::ios::binary);
    if (!loadFile)
    {
        std::cout << "Error: Unable to open file " << fileName << std::endl;
        return;
    }

    loadFile.read(reinterpret_cast<char *>(&playerPosition), sizeof(playerPosition));
    // Add binary loading for other attributes here

    loadFile.close();
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
