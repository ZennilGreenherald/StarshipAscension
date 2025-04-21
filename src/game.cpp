#include "game.hpp"
#include <algorithm>
#include <array>
#include <bitset>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <ostream>
#include <iomanip>
#include <vector>
#include <map>
#include <utility>
#include <stdexcept>
#include <cstring>
#include <cctype>
#include <limits>
#include <ctime>
#include <chrono>
#include <thread>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <memory>
#include <functional>
#include <type_traits>
#include <initializer_list>
#include <iterator>
#include <exception>
#include <stdexcept>
#include <utility>
#include <filesystem>
#include <vector>
// #include <nlohmann/json.hpp>

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
    std::cout << "Welcome aboard, Captain " << playerName << "!\n";
    std::cout << "A galaxy of adventure awaits you, Captain!" << std::endl;
    std::cout << "Prepare to explore the stars and achieve ascension." << std::endl;
    std::cout << "\nPress Enter to continue..." << std::endl;
    std::cin.get(); // Wait for the user to press Enter
    clearScreen();  // Clear the screen after input
}

void Game::displayMainMenu()
{
    std::cout << "=====================================" << std::endl;
    std::cout << "             Main Menu               " << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "1. Start New Game" << std::endl;
    std::cout << "2. Continue Game" << std::endl;
    // TODO: Implement save game functionality, renumber the menu options accordingly
    // std::cout << "3. Save Game" << std::endl;
    std::cout << "3. Load Saved Game" << std::endl;
    std::cout << "4. Captain's Log" << std::endl;
    std::cout << "5. Mission Briefing" << std::endl;
    std::cout << "6. Ship Systems Overview" << std::endl;
    std::cout << "7. Help" << std::endl;
    std::cout << "8. Setup Game" << std::endl;
    std::cout << "9. Credits" << std::endl;
    std::cout << "10. Exit" << std::endl;
    std::cout << std::endl << "Select an option: ";

    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << "\nStarting a new game...\n";
        // TODO: Implement new game functionality
        // std:cout << "\nLoading playing field...\n";
        // std::cout << "Initializing game...\n";
        // std::cout << "Initializing player...\n";
        // std::cout << "Initializing ship...\n";
        // std::cout << "Initializing crew...\n";
        // std::cout << "Initializing mission...\n";
        // std::cout << "loading mission..\n";
        // std::cout << "Initializing systems...\n";
        // std::cout << "Initializing inventory...\n";
        // std::cout << "Initializing map...\n";
        // std::cout << "Initializing log...\n";
        // std::cout << "Initializing settings...\n";
        // std::cout << "Initializing game...\n";
        break;
    case 2:
        std::cout << "\nContinuing game...\n";
        break;
        case 3:
        {
            std::cout << "\nLoading saved game...\n";
            std::cout << "Choose a format to load your game:\n";
            std::cout << "1. Plain Text (.txt)\n";
            std::cout << "2. JSON (.json)\n";
            std::cout << "3. XML (.xml)\n";
            std::cout << "4. Binary (.dat)\n";
            std::cout << "Enter your choice: ";
            int loadChoice;
            std::cin >> loadChoice;
        
            std::cout << "Here are the available save files:\n";
            listSaveFiles(); // Display available save files
        
            std::cout << "Enter the name of the saved game file (with extension): ";
            std::string fileName;
            std::cin.ignore();
            std::getline(std::cin, fileName);
        
            switch (loadChoice)
            {
            case 1:
                loadFromPlainText(fileName);
                break;
            // case 2:
            //     loadFromJSON(fileName);
            //     break;
            case 3:
                loadFromXML(fileName);
                break;
            case 4:
                loadFromBinary(fileName);
                break;
            default:
                std::cout << "Invalid choice. Returning to menu...\n";
                return;
            }
        
            std::cout << "\nPress Enter to return to the Main Menu.";
            std::cin.get();
            clearScreen();
            displayMainMenu();
            break;
        }        
    case 4:
        std::cout << "\nDisplaying captain's log...\n";
        // std::cout << "Captain's Log:\n";
        // std::cout << "=====================\n";
        // std::cout << "Captain's Name: " << playerName << "\n";
        // std::cout << "Ship Name: " << shipName << "\n";
        // std::cout << "Current Position: " << playerPosition << "\n";
        // std::cout << "Mission Status: In Progress\n";
        // std::cout << "Last Entry: Exploring the Alpha Centauri System.\n";
        // std::cout << "=====================\n";
        // std::cout << "Captain's Log Entries:\n";
        // std::cout << "1. Entered the Alpha Centauri System.\n";
        // std::cout << "2. Encountered a hostile ship.\n";
        // std::cout << "3. Engaged in combat.\n";
        // std::cout << "4. Successfully evaded enemy fire.\n";
        // std::cout << "5. Received a distress signal from a nearby planet.\n";
        // std::cout << "6. Investigating the source of the signal.\n";
        // std::cout << "7. Found a derelict ship.\n";
        // std::cout << "8. Boarding the ship to investigate.\n";
        // std::cout << "9. Found valuable resources.\n";
        // std::cout << "10. Preparing to leave the system.\n";
        // std::cout << "=====================\n";
        // std::cout << "Captain's Log Summary:\n";
        // std::cout << "Total Entries: 10\n";
        // std::cout << "Total Missions Completed: 2\n";
        // std::cout << "Total Resources Collected: 50 units\n";
        // std::cout << "Total Hostile Encounters: 3\n";
        // std::cout << "Total Crew Members: 50\n";
        // std::cout << "Total Ship Damage: 20%\n";
        // std::cout << "Total Repairs Needed: 5\n";
        // std::cout << "Total Time Spent: 10 hours\n";
        // std::cout << "Total Distance Traveled: 100 light-years\n";
        // std::cout << "Total Fuel Used: 50 units\n";
        // std::cout << "Total Supplies Used: 20 units\n";
        // std::cout << "Total Medical Supplies Used: 5 units\n";
        // std::cout << "Total Food Supplies Used: 10 units\n";
        // std::cout << "Total Water Supplies Used: 5 units\n";
        // std::cout << "Total Power Used: 20 units\n";
        // std::cout << "Total Energy Used: 10 units\n";
        // std::cout << "Total Shields Used: 5 units\n";
        // std::cout << "Total Weapons Used: 10 units\n";
        // std::cout << "Total Ammunition Used: 5 units\n";
        // std::cout << "Total Repairs Made: 5\n";
        // std::cout << "Total Upgrades Made: 2\n";
        // std::cout << "Total New Technologies Discovered: 1\n";
        // std::cout << "Total New Species Discovered: 1\n";
        // std::cout << "Total New Planets Discovered: 1\n";
        // std::cout << "Total New Star Systems Discovered: 1\n";
        // std::cout << "Total New Civilizations Discovered: 1\n";
        // std::cout << "Total New Resources Discovered: 1\n";
        // std::cout << "Total New Technologies Developed: 1\n";
        // std::cout << "Total New Weapons Developed: 1\n";
        // std::cout << "Total New Shields Developed: 1\n";
        // std::cout << "Total New Engines Developed: 1\n";
        // std::cout << "Total New Power Sources Developed: 1\n";
        // std::cout << "Total New Life Forms Discovered: 1\n";
        // std::cout << "Total New Civilizations Contacted: 1\n";
        // std::cout << "Total New Civilizations Allied: 1\n";
        // std::cout << "Total New Civilizations Hostile: 1\n";
        // std::cout << "Total New Civilizations Neutral: 1\n";
        // std::cout << "Total New Civilizations Unknown: 1\n";
        // std::cout << "Total New Civilizations Explored: 1\n"; 
        // std::cout << "Total New Civilizations Mapped: 1\n";
        // std::cout << "Total New Civilizations Surveyed: 1\n";
        // std::cout << "Total New Civilizations Researched: 1\n";
        // std::cout << "Total New Civilizations Studied: 1\n";
        // std::cout << "Total New Civilizations Analyzed: 1\n";
        // std::cout << "Total New Civilizations Cataloged: 1\n";
        // std::cout << "Total New Civilizations Documented: 1\n";
        // std::cout << "Total New Civilizations Recorded: 1\n";
        // std::cout << "Total New Civilizations Archived: 1\n";
        // std::cout << "Total New Civilizations Preserved: 1\n";
        // std::cout << "Total New Civilizations Saved: 1\n";
        // std::cout << "Total New Civilizations Rescued: 1\n";
        // std::cout << "Total New Civilizations Evacuated: 1\n";
        // std::cout << "Total New Civilizations Rehabilitated: 1\n";
        // std::cout << "Total New Civilizations Reintegrated: 1\n";
        // std::cout << "Total New Civilizations Reunited: 1\n";
        // std::cout << "Total New Civilizations Reconciled: 1\n";
        // std::cout << "Total New Civilizations Reformed: 1\n";
        // std::cout << "Total New Civilizations Rehabilitated: 1\n";
        // std::cout << "Total New Civilizations Reintegrated: 1\n";
        std::cout << "[TODO: Implement Captain's Log]\n";
        std::cout << "\nPress Enter to return to the Main Menu.";
        std::cin.ignore();
        std::cin.get();
        clearScreen();
        // displayCaptainsLog();
        displayMainMenu();
        break;
    case 5:
        std::cout << "\nDisplaying mission briefing...\n";
        std::cout << "[TODO: Implement Mission Briefing]\n";
        std::cout << "\nPress Enter to return to the Main Menu.";
        std::cin.ignore();
        std::cin.get();
        clearScreen();
        // TODO: Implement mission briefing functions
        // createMissionBriefing();
        // saveMissionBriefing();
        // loadMissionBriefing();
        // displayMissionBriefing();
        displayMainMenu();
        break;
    case 6: 
        std::cout << "\nDisplaying ship systems overview...\n";
        std::cout << "\nPress Enter to return to the Main Menu.";
        std::cin.ignore();
        std::cin.get();
        clearScreen();
        displayShipSystemsOverview();
        displayMainMenu();
        break;
    case 7:
        displayHelpMenu();
        break;
    case 8:
        displaySetupMenu();
        break;
    case 9:
        displayCredits();
        break;
    case 10:
        std::cout << "\nExiting. Goodbye!\n";
        stopGame();
        break;
    default:
        std::cout << "\nInvalid choice. Returning to menu...\n";
        clearScreen();
        displayMainMenu();
    }
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

// TODO: Implement captains log functions
// void Game::displayCaptainsLog();
// void Game::initializeCaptainsLog()l
// void Game::createCaptainsLog();
// void Game::saveCaptainsLog();
// void Game::loadCaptainsLog();
// void Game::deleteCaptainsLog();

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
    std::cin.ignore(); // Clear buffer before getline
    std::getline(std::cin, shipName);

    std::cout << "Enter your name, Captain: ";
    std::getline(std::cin, playerName); // Store the player name

    std::cout << "\nConfiguration complete!\n";
    std::cout << "Players: " << numPlayers << "\nShip Name: " << shipName << "\nCaptain: " << playerName << std::endl;
    std::cout << "\nPress Enter to return to the Main Menu." << std::endl;
    std::cin.get();
    clearScreen();
    displayMainMenu();
}

void Game::displayShipSystemsOverview()
{
    clearScreen(); // Clear the screen for better visibility
    std::cout << "=====================================" << std::endl;
    std::cout << "         Ship Systems Overview        " << std::endl;
    std::cout << "=====================================" << std::endl;

    // General Ship Info
    std::cout << "Ship Name: " << shipName << std::endl; // Dynamically update ship name
    std::cout << "Captain:   " << playerName << std::endl; // Display captain's name
    std::cout << "Crew Size: " << 50 << std::endl; // Placeholder for crew size
    std::cout << "=====================================" << std::endl;

    // Ship Systems Status
    std::cout << "Power Core:  Online (85% capacity)" << std::endl; // Example data
    std::cout << "Engines:     Operational (Warp Speed: 3.5)" << std::endl;
    std::cout << "Shields:     Active (Integrity: 72%)" << std::endl;
    std::cout << "Weapons:     Armed (Photon Torpedoes: 8 remaining)" << std::endl;
    std::cout << "Sensors:     Calibrated (Range: 20,000 km)" << std::endl;
    std::cout << "Life Support: Nominal (Oxygen: 95%)" << std::endl;
    std::cout << "=====================================" << std::endl;

    // Mission Objectives
    std::cout << "Mission Objectives:" << std::endl;
    std::cout << "- Explore the Alpha Centauri System" << std::endl; // Placeholder mission
    std::cout << "- Deliver supplies to Station Delta" << std::endl;
    std::cout << "- Respond to distress signal near Proxima Centauri" << std::endl;
    std::cout << "=====================================" << std::endl;

    // Cargo Bay Inventory
    std::cout << "Cargo Bay:" << std::endl;
    std::cout << "- Medical Supplies: 20 crates" << std::endl;
    std::cout << "- Food Rations:     15 crates" << std::endl;
    std::cout << "- Exotic Minerals:  5 crates" << std::endl;
    std::cout << "=====================================" << std::endl;

    // Ship's Log
    std::cout << "Ship's Log:" << std::endl;
    std::cout << "- Last docked: Starbase 23" << std::endl; // Placeholder log
    std::cout << "- Current Location: Sector 7G" << std::endl;
    std::cout << "- Distress signals received: 1" << std::endl;
    std::cout << "=====================================" << std::endl;

    // Return to Main Menu
    std::cout << "Press Enter to return to the Main Menu..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    clearScreen();
    displayMainMenu(); // Navigate back to the main menu
}

// Display Creditsp
void Game::displayCredits()
{
    clearScreen();
    std::cout << "=====================================" << std::endl;
    std::cout << "               Credits                " << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "StarshipAscension was created by Gregory K. Bowne!" << std::endl;
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

void Game::saveAsBinary(const std::filesystem::path &filePath)
{
    try
    {
        // Ensure the parent directory exists
        if (!std::filesystem::exists(filePath.parent_path()))
        {
            std::filesystem::create_directories(filePath.parent_path());
        }

        // Open file for binary writing
        std::ofstream saveFile(filePath, std::ios::binary);
        if (!saveFile)
        {
            throw std::ios_base::failure("Failed to open file for saving.");
        }

        // Write binary data
        saveFile.write(reinterpret_cast<const char *>(&playerPosition), sizeof(playerPosition));
        saveFile.close();

        std::cout << "Game saved successfully to: " << filePath << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error saving game: " << e.what() << std::endl;
    }
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


void Game::loadFromPlainText(const std::string& fileName)
{
    std::ifstream file(fileName);

    // Check if file exists and is accessible
    if (!file.is_open())
    {
        std::cout << "Error: Unable to open file " << fileName << std::endl;
        std::cout << "Please ensure the file exists and try again.\n";
        return;
    }

    // Example of loading data from the file
    std::string line;
    while (std::getline(file, line))
    {
        std::cout << "Loaded line: " << line << std::endl; // Replace with your parsing logic
    }

    file.close();
    std::cout << "Game loaded successfully from " << fileName << "!\n";
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

void Game::listSaveFiles()
{
    std::cout << "Searching for save files...\n";
    for (const auto& entry : std::filesystem::directory_iterator("."))
    {
        if (entry.path().extension() == ".txt")
        {
            std::cout << entry.path().filename() << std::endl;
        }
        else if (entry.path().extension() == ".json")
        {
            std::cout << entry.path().filename() << std::endl;
        }
        else if (entry.path().extension() == ".xml")
        {
            std::cout << entry.path().filename() << std::endl;
        }
        else if (entry.path().extension() == ".dat")
        {
            std::cout << entry.path().filename() << std::endl;
        }
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
