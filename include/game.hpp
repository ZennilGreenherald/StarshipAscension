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
    bool isRunning;

    // Example game-specific attributes
    std::string playerName;
    int playerPosition;
};

#endif // GAME_HPP
