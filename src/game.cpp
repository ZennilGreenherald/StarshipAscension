#include "./include/game.h"
#include "./include/player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUM_STARBASES = 3;
const int NUM_MOONS = 5;
const int NUM_ENEMY_SHIPS = 10;

Game::Game() {
    currentPlayerIndex = 0;
}

void Game::start() {
    displayMenu();
    initializePlayingField();
    displayPlayingField();

    while (!gameOver()) {
        handleUserInput();
        updatePlayingField();
        displayPlayingField();
        handleCollisions();
    }

    handleScoring();
    displayHighScore();
}

void Game::displayMenu() {
    cout << "Welcome to Space Game!" << endl;
    cout << "How many players? (1 or 2)" << endl;

    int numPlayers;
    cin >> numPlayers;

    for (int i = 0; i < numPlayers; i++) {
        players[i].setScore(0);
    }

    cout << "High Score: " << players[0].getScore() << endl;
    cout << "Press any key to start the game..." << endl;
    cin.ignore();
    cin.get();
}

void Game::initializePlayingField() {
    srand(time(NULL));

    playingField.initialize();

    playingField.addObject(PLAYING_FIELD_SHIP, PLAYING_FIELD_HEIGHT / 2, PLAYING_FIELD_WIDTH / 2);
    playingField.addObject(PLAYING_FIELD_PLANET, PLAYING_FIELD_HEIGHT / 4, PLAYING_FIELD_WIDTH / 4);

    for (int i = 0; i < NUM_STARBASES; i++) {
        int x, y;
        do {
            x = rand() % PLAYING_FIELD_WIDTH;
            y = rand() % PLAYING_FIELD_HEIGHT;
        } while (playingField.getObject(y, x) != PLAYING_FIELD_EMPTY);
        playingField.addObject(PLAYING_FIELD_STARBASE, y, x);
    }

    for (int i = 0; i < NUM_MOONS; i++) {
        int x, y;
        do {
            x = rand() % PLAYING_FIELD_WIDTH;
            y = rand() % PLAYING_FIELD_HEIGHT;
        } while (playingField.getObject(y, x) != PLAYING_FIELD_EMPTY);
        playingField.addObject(PLAYING_FIELD_MOON, y, x);
    }

    for (int i = 0; i < NUM_ENEMY_SHIPS; i++) {
        int x, y;
        do {
            x = rand() % PLAYING_FIELD_WIDTH;
            y = rand() % PLAYING_FIELD_HEIGHT;
        } while (playingField.getObject(y, x) != PLAYING_FIELD_EMPTY);
        playingField.addObject(PLAYING_FIELD_ENEMY_SHIP, y, x);
    }
}

void Game::displayPlayingField() {
    system("clear");
    playingField.display();
}

bool Game::gameOver() {
    return playingField.getObject(PLAYING_FIELD_SHIP) == PLAYING_FIELD_PLANET;
}

void Game::handleUserInput() {
    char input;
    bool validInput = false;
    while (!validInput) {
        cout << "Player " << currentPlayerIndex + 1 << ", enter your move (WASD): ";
        cin >> input;
        switch (input) {
            case 'w':
                playingField.moveObject(PLAYING_FIELD_SHIP, -1, 0);
                validInput = true;
                break;
            case 'a':
                playingField.moveObject(PLAYING_FIELD_SHIP, 0, -1);
                validInput = true;
                break;
            case 's':
                playingField.moveObject(PLAYING_FIELD_SHIP, 1, 0);
                validInput = true;
                break;
            case 'd':
                playingField.moveObject(PLAYING_FIELD_SHIP, 0, 1);
                validInput = true;
                break;
            default:
                cout << "Invalid input. Please enter W, A, S, or D." << endl;
                break;
        }
    }
}

void Game::updatePlayingField() {
    // Update the playing field based on game logic
}

void Game::handleCollisions() {
    // Handle collisions between objects in the game
    if (playingField.getObject(PLAYING_FIELD_SHIP) == PLAYING_FIELD_PLANET) {
        players[currentPlayerIndex].setScore(players[currentPlayerIndex].getScore() - 10);
    }
}

void Game::handleScoring() {
    // Update the player's score based on the game's outcome
    if (playingField.getObject(PLAYING_FIELD_SHIP) == PLAYING_FIELD_PLANET) {
        players[currentPlayerIndex].setScore(players[currentPlayerIndex].getScore() - 10);
    } else {
        players[currentPlayerIndex].setScore(players[currentPlayerIndex].getScore() + 5);
    }
    currentPlayerIndex = (currentPlayerIndex + 1) % 2;
}

void Game::displayHighScore() {
    // Check which player has the highest score
    int highestScore = players[0].getScore();
    int highestScoreIndex = 0;
    for (int i = 1; i < 2; i++) {
        if (players[i].getScore() > highestScore) {
            highestScore = players[i].getScore();
            highestScoreIndex = i;
        }
    }
    cout << "High Score: " << highestScore << endl;
    cout << "Player " << highestScoreIndex + 1 << " wins!" << endl;
}
