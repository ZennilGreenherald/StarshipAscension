#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <iostream>

class Game
{
public:
    Game();
    ~Game();
    void run();
    void listSaveFiles();

private:
    void displayWelcomeScreen();
    void clearScreen();
    void displayMainMenu();
    void displayHelpMenu();  // Help menu option
    void displaySetupMenu(); // Setup menu option
    void displayCredits();   // View credits option
    void processPlayerInput();
    void updateGameState();
    void render();
    void stopGame();
    bool getIsRunning() const;
    void saveGame();                                   // Save game method
    void loadGame();                                   // Load game method
    void saveAsPlainText(const std::string &fileName); // Save as plain text
    // void saveAsJSON(const std::string &fileName);        // Save as JSON
    void saveAsXML(const std::string &fileName);         // Save as XML
    void saveAsBinary(const std::string &fileName);      // Save as binary
    void loadFromPlainText(const std::string &fileName); // Load from plain text
    // void loadFromJSON(const std::string &fileName);      // Load from JSON
    void loadFromXML(const std::string &fileName);    // Load from XML
    void loadFromBinary(const std::string &fileName); // Load from binary

    // Game attributes
    std::string playerName;
    int playerPosition;
    bool isRunning;
};

#endif // GAME_HPP
