#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "playing_field.h"
#include "Spaceship.h"

class Game {
public:
    Game();
    void start();
	uint32_t x;
    uint32_t y;
private:
    Player players[2];
    PlayingField playingField;
    int currentPlayerIndex;
    void displayMenu();
    void initializePlayingField();
    void displayPlayingField();
    bool gameOver(const Spaceship* ship);
    void handleUserInput();
    void updatePlayingField();
    void handleCollisions();
    void handleScoring();
    void displayHighScore();
};

#endif
