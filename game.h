#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "playing_field.h"

class Game {
public:
    Game();
    void start();
private:
    Player players[2];
    PlayingField playingField;
    int currentPlayerIndex;
    void displayMenu();
    void initializePlayingField();
    void displayPlayingField();
    bool gameOver();
    void handleUserInput();
    void updatePlayingField();
    void handleCollisions();
    void handleScoring();
    void displayHighScore();
};

#endif
