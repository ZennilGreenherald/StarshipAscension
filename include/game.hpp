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

    // Game attributes
    std::string playerName;
    int playerPosition;
    bool isRunning;
};

#endif // GAME_HPP
