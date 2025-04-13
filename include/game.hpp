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
    void displayWelcomeMessage();
    void processPlayerInput();
    void updateGameState();
    void render();
    void stopGame();
    bool getIsRunning() const; // Updated getter method

    // Example game-specific attributes
    std::string playerName;
    int playerPosition;
    bool isRunning; // Fixed: Declared correctly as a member variable
};

#endif // GAME_HPP
