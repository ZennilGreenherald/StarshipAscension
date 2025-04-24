#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <iostream>
#include <filesystem>
#include <vector>

class Game
{
public:
    Game();
    ~Game();
    void run();
    void listSaveFiles();
    void displayShipSystemsOverview();

private:
    void displayWelcomeScreen();
    void clearScreen();
    void displayMainMenu();
    void displayHelpMenu();  // Help menu option
    void displaySetupMenu(); // Setup menu option
    void displayCredits();   // View credits option
    void displayCaptainsLog(); // View captain's log option
    void addToCaptainsLog(const std::string &entry); // Add entry to captain's log
    void initializeCaptainsLog(); // Initialize captain's log
    void initializeStep(const std::string &step); // Initialize game step
    void processPlayerInput();
    void updateGameState();
    void manageCrew();
    void render();
    void stopGame();
    bool getIsRunning() const;
    void saveGame();                                   // Save game method
    void loadGame();                                   // Load game method
    void saveAsPlainText(const std::string &fileName); // Save as plain text
    // void saveAsJSON(const std::string &fileName);        // Save as JSON
    void saveAsXML(const std::string &fileName);         // Save as XML
    void saveAsBinary(const std::filesystem::path &filePath);      // Save as binary
    void loadFromPlainText(const std::string &fileName); // Load from plain text
    // void loadFromJSON(const std::string &fileName);      // Load from JSON
    void loadFromXML(const std::string &fileName);    // Load from XML
    void loadFromBinary(const std::string &fileName); // Load from binary
    // TODO: implement scanField function to scan the field
    // void scanField(const std::vector<std::vector<char>> &field, int playerX, int playerY);

    // Game attributes
    void setPlayerName(const std::string& name);
    std::vector<std::string> captainsLog;
    std::string getPlayerName() const;
    std::string playerInput;
    std::string playerName;
    std::string shipName;
    std::string cheifEng;
    std::string cheifTac;
    std::string cheifSecurity;
    std::string firstOfficer;
    std::string secondOfficer;
    std::string cheifMed;
    std::string cheifScience;
    int currentLocation;
    int playerPosition;
    int shieldStrength;
    int shieldStatus;
    int hullIntegrity;
    bool sheieldStrength;
    bool isRunning;
    int crewSize;
};

#endif // GAME_HPP
