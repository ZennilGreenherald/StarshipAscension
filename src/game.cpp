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
#include <chrono>
#include <thread>
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

void initializeStep(const std::string &step)
{
    std::cout << "Initializing " << step << "..." << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate processing delay
    std::cout << " Done!" << std::endl;
}

std::string sanitizeInput(const std::string &input)
{
    std::string sanitized = input;
    std::transform(sanitized.begin(), sanitized.end(), sanitized.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    sanitized.erase(std::remove_if(sanitized.begin(), sanitized.end(), ::isspace), sanitized.end());
    return sanitized;
}

void updateGameState(const std::string &playerInput)
{
    std::string command = sanitizeInput(playerInput);
}

void Game::addToCaptainsLog(const std::string &entry)
{
    captainsLog.push_back(entry);
    std::cout << "Entry added to Captain's Log: " << entry << std::endl;
}

void renderProgressBar(int progress, int total)
{
    int barWidth = 50;
    int filledWidth = (progress * barWidth) / total;

    std::cout << "[";
    for (int i = 0; i < filledWidth; ++i)
        std::cout << "=";
    for (int i = filledWidth; i < barWidth; ++i)
        std::cout << " ";
    std::cout << "] " << (progress * 100) / total << "%\r" << std::flush;
}

void Game::displayMainMenu()
{
    std::cout << "=====================================" << std::endl;
    std::cout << "             Main Menu               " << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "1. Start New Game" << std::endl;
    std::cout << "2. Continue Game" << std::endl;
    // TODO: Implement save game functionality, renumber the menu options accordingly
    std::cout << "3. Save Game" << std::endl;
    std::cout << "3. Load Saved Game" << std::endl;
    std::cout << "4. Captain's Log" << std::endl;
    std::cout << "5. Mission Briefing" << std::endl;
    std::cout << "6. Ship Systems Overview" << std::endl;
    std::cout << "7. Help" << std::endl;
    std::cout << "8. Setup Game" << std::endl;
    std::cout << "9. Credits" << std::endl;
    std::cout << "10. Exit" << std::endl;
    std::cout << "11. Resume Last Mission" << std::endl;
    std::cout << "12. Tactical Overview" << std::endl;
    std::cout << "13. Manage Crew" << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "Welcome, Captain " << playerName << "!" << std::endl;
    std::cout << "Your current position: " << playerPosition << std::endl;
    std::cout << "Your ship: " << shipName << std::endl;
    std::cout << "Crew Size: " << crewSize << std::endl;
    std::cout << "First Officer: " << firstOfficer << std::endl;
    std::cout << "Second Officer: " << secondOfficer << std::endl;
    std::cout << "Cheif Security Officer: " << cheifSecurity << std::endl;
    std::cout << "Cheif Medical Officer:" << cheifMed << std::endl;
    std::cout << "Cheif Engineer: " << cheifEng << std::endl;
    std::cout << "Cheif Tactical Officer: " << cheifTac << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "Available Commands:\n";
    std::cout << "1. Move: Move to a new position." << std::endl;
    std::cout << "2. Quit: Exit the game." << std::endl;
    std::cout << "3. Menu: Display the main menu." << std::endl;
    std::cout << "4. Scan: Scan the surrounding area." << std::endl;
    std::cout << "5. Help: Display help information." << std::endl;
    std::cout << "=====================================" << std::endl;
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
{
    clearScreen();
    std::cout << "Initializing Captain's Log...\n";

    int progress = 0;
    int total = 100;

    for (progress = 0; progress <= total; progress += 10) // Simulate loading in increments
    {
        renderProgressBar(progress, total);
        std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Simulate loading delay
    }
    std::cout << std::endl; // Move to a new line after the progress bar completes

    std::cout << "Captain's Log initialized successfully.\n";
    std::cout << "\nDisplaying Captain's Log...\n";
    std::cout << "=====================\n";

    // Display mock Captain's Log entries (for testing)
    std::cout << "[TODO: Implement Captain's Log functionality]\n";
    std::cout << "\nPress Enter to return to the Main Menu.";
    std::cin.ignore();
    std::cin.get();
    clearScreen();
    displayMainMenu();
    break;
    }
    
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
    case 11:
        break;
    case 12:
        break;
    case 13:
        clearScreen();
        manageCrew();
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
// void Game::initializeCaptainsLog()l
// void Game::createCaptainsLog();
// void Game::saveCaptainsLog();
// void Game::loadCaptainsLog();
// void Game::deleteCaptainsLog();

void Game::displayCaptainsLog()
{
    clearScreen(); // Optional: Clear the screen for better readability
    std::cout << "=====================================\n";
    std::cout << "          Captain's Log              \n";
    std::cout << "=====================================\n";

    if (captainsLog.empty())
    {
        std::cout << "The Captain's Log is empty. No entries recorded yet.\n";
    }
    else
    {
        for (size_t i = 0; i < captainsLog.size(); ++i)
        {
            std::cout << i + 1 << ". " << captainsLog[i] << std::endl;
        }
    }

    std::cout << "\nPress Enter to return to the Main Menu.";
    std::cin.ignore();
    std::cin.get();
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
    std::cin.ignore(); // Clear buffer before getline
    std::getline(std::cin, shipName);

    std::cout << "Enter your name, Captain: ";
    std::getline(std::cin, playerName); // Store the player name

    std::cout << "Enter your First Officer's name: ";
    std::getline(std::cin, firstOfficer); // Store the first officer's name

    std::cout << "Enter your Second Officer's name: ";
    std::getline(std::cin, secondOfficer); // Store the second officer's name

    std::cout << "Enter your Chief Security Officer's name: ";
    std::getline(std::cin, cheifSecurity); // Store the chief security officer's name

    std::cout << "Enter your Chief Medical Officer's name: ";
    std::getline(std::cin, cheifMed); // Store the chief medical officer's name

    std::cout << "Enter your Chief Engineer's name: ";
    std::getline(std::cin, cheifEng); // Store the chief engineer's name

    std::cout << "Enter your Chief Tactical Officer's name: ";
    std::getline(std::cin, cheifTac); // Store the chief tactical officer's name

    std::cout << "Enter your Chief Science Officer's name: ";
    std::getline(std::cin, cheifScience); // Store the chief science officer's name

    std::cout << "Would you like to manage your crew, captain? (yes/no): ";
    std::string manageCrewChoice;
    std::getline(std::cin, manageCrewChoice); // Store the crew management choice
    if (manageCrewChoice == "yes" || manageCrewChoice == "y")
    {
        std::cout << "You can manage your crew in the Manage Crew Menu.\n";
        manageCrew();
        clearScreen();
    } else if (manageCrewChoice == "no" || manageCrewChoice == "n") 
    {
        std::cout << "You can manage your crew later in the game.\n";
        clearScreen();
    }
    clearScreen();
    std::cout << "\nConfiguration complete!\n";
    std::cout << "Players: " << numPlayers << "\nShip Name: " << shipName << "\nCaptain: " << playerName << std::endl;
    std::cout << "\nPress Enter to return to the Main Menu." << std::endl;
    std::cin.get();
    // TODO: Implement saveSetup function to save the setup
    // saveSetup();
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
    std::cout << "First Officer: " << firstOfficer << std::endl; // Placeholder for first officer
    std::cout << "Second Officer: " << secondOfficer << std::endl; // Placeholder for second officer
    std::cout << "Cheif Security Officer: " << cheifSecurity << std::endl; // Placeholder for chief security officer
    std::cout << "Cheif Medical Officer: " << cheifMed << std::endl; // Placeholder for chief medical officer
    std::cout << "Cheif Engineer: " << cheifEng << std::endl; // Placeholder for chief engineer
    std::cout << "Cheif Tactical Officer: " << cheifTac << std::endl; // Placeholder for chief tactical officer
    std::cout << "Current Location: " << currentLocation << std::endl; // Placeholder for current location
    std::cout << "Current Position: " << playerPosition << std::endl; // Placeholder for current position
    std::cout << "Ship Status:  Online" << std::endl; // Placeholder for ship status
    std::cout << "Mission Status: In Progress" << std::endl; // Placeholder for mission status
    std::cout << "Crew Size: " << crewSize << std::endl; // Placeholder for crew size
    std::cout << "=====================================" << std::endl;

    // Ship Systems Status
    std::cout << "Power Core:  Online (85% capacity)" << std::endl; // Example data
    std::cout << "Engines:     Operational (Warp Speed: 3.5)" << std::endl;
    std::cout << "Shields Status: " << shieldStatus << std::endl;
    std::cout << "Sheilds Strength: " << shieldStrength << std::endl;
    std::cout << "Hull Integrity: " << hullIntegrity << std::endl; // Example data
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
    std::cout << "- Current Location: " << currentLocation << std::endl;
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

void Game::manageCrew()
{
    clearScreen();
    std::cout << "=====================================" << std::endl;
    std::cout << "           Manage Crew Menu           " << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "Crew Management System\n";
    std::cout << "1. View Crew List\n";
    std::cout << "2. Assign Roles\n";
    std::cout << "3. Dismiss Crew Member\n";
    std::cout << "4. Add Crew Member\n";
    std::cout << "5. View Crew Status\n";
    std::cout << "6. Return to Main Menu\n";
    std::cout << "=====================================" << std::endl;

    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        viewCrewList();
        break;
    case 2:
        assignRoles();
        break;
    case 3:
        dismissCrewMember();
        break;
    case 4:
        addCrewMember();
        break;
    case 5:
        viewCrewStatus();
        break;
    case 6:
        displayMainMenu();
        break;
    default:
        std::cout << "Invalid choice. Returning to Manage Crew Menu...\n";
        manageCrew();
        break;
    }
}

void Game::addCrewMember()
{
    clearScreen();
    std::cout << "=====================================" << std::endl;
    std::cout << "          Add Crew Member             " << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "[TODO: Implement Crew Member Addition]\n";
    std::cout << "\nPress Enter to return to Manage Crew Menu.";
    std::cin.ignore();
    std::cin.get();
    manageCrew(); // Return to the manage crew menu
}

void Game::assignRoles()
{
    clearScreen();
    std::cout << "=====================================" << std::endl;
    std::cout << "           Assign Roles               " << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "[TODO: Implement Role Assignment]\n";
    std::cout << "\nPress Enter to return to Manage Crew Menu.";
    std::cin.ignore();
    std::cin.get();
    manageCrew();
}
void Game::viewCrewList()
{
    clearScreen();
    std::cout << "=====================================" << std::endl;
    std::cout << "             Crew List                " << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "[TODO: Display Crew List]\n";
    std::cout << "\nPress Enter to return to Manage Crew Menu.";
    std::cin.ignore();
    std::cin.get();
    manageCrew();
}

void Game::dismissCrewMember()
{
    clearScreen();
    std::cout << "=====================================" << std::endl;
    std::cout << "         Dismiss Crew Member          " << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "[TODO: Implement Crew Member Dismissal]\n";
    std::cout << "\nPress Enter to return to Manage Crew Menu.";
    std::cin.ignore();
    std::cin.get();
    manageCrew();
}

void Game::viewCrewStatus()
{
    clearScreen();
    std::cout << "=====================================" << std::endl;
    std::cout << "           Crew Status                " << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "[TODO: Display Crew Status]\n";
    std::cout << "\nPress Enter to return to Manage Crew Menu.";
    std::cin.ignore();
    std::cin.get();
    manageCrew();
}


void Game::listSaveFiles()
{
    std::cout << "Available save files:\n";
    std::filesystem::path saveDir = "saves"; // Directory where save files are stored
    if (std::filesystem::exists(saveDir))
    {
        for (const auto &entry : std::filesystem::directory_iterator(saveDir))
        {
            if (entry.is_regular_file())
            {
                std::cout << "- " << entry.path().filename().string() << std::endl;
            }
        }
    }
    else
    {
        std::cout << "No save files found.\n";
    }
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
