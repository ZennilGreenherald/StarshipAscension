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
    void displayWelcomeScreen(); // Welcome screen method
    void clearScreen();          // Screen clearing method
    void displayMainMenu();      // Main menu method
    void processPlayerInput();
    void updateGameState();
    void render();
    void stopGame();
    bool getIsRunning() const;

    // Attributes for the game
    std::string playerName;
    int playerPosition;
    bool isRunning;
};

#endif // GAME_HPP
