#include "./include/game.h"
#include "./include/player.h"
#include "include/Spaceship.h"
#include "include/planet.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "./include/player.h"
#include "./include/Spaceship.h"
#include "./include/vector2d.h"
#include "./include/playing_field.h"
#include "./include/StarshipAscension.h"

using namespace std;

const int NUM_STARBASES = 3;
const int NUM_MOONS = 5;
const int NUM_ENEMY_SHIPS = 10;

Game::Game() { currentPlayerIndex = 0; }

void Game::start() {
    displayMenu();
    initializePlayingField();
    displayPlayingField();

    while (!gameOver(dynamic_cast<Spaceship*>(playingField.getObject(PLAYING_FIELD_SHIP)))) {
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
    srand((unsigned int)time(nullptr));

    playingField = {};

    Spaceship* ship = new Spaceship("Player_1", 100, 100, 100);
    ship->setPos({PLAYING_FIELD_HEIGHT / 2, PLAYING_FIELD_WIDTH / 2});
    playingField.addObject(ship);

    // Planet class needs to be implemented and derived from GameObj class.
    playingField.addObject(PLAYING_FIELD_PLANET, PLAYING_FIELD_HEIGHT / 4, PLAYING_FIELD_WIDTH / 4);

    for (int i = 0; i < NUM_STARBASES; i++) {
        Vector2D pos;
        do {
            pos.x_ = rand() % PLAYING_FIELD_WIDTH;
            pos.y_ = rand() % PLAYING_FIELD_HEIGHT;
        } while (playingField.getObject(pos) != nullptr);

        // Starbase class needs to be implemented and derived from gameObj class.
        playingField.addObject(PLAYING_FIELD_STARBASE, y, x);
    }
    for (int i = 0; i < NUM_MOONS; i++) {
        Vector2D pos;
        do {
            pos.x_ = rand() % PLAYING_FIELD_WIDTH;
            pos.y_ = rand() % PLAYING_FIELD_HEIGHT;
        } while (playingField.getObject(pos) != nullptr);

        // Use planet class here when it's implemented.
        playingField.addObject(PLAYING_FIELD_MOON, y, x);
    }
    for (int i = 0; i < NUM_ENEMY_SHIPS; i++) {
        Vector2D pos;
        do {
            pos.x_ = rand() % PLAYING_FIELD_WIDTH;
            pos.y_ = rand() % PLAYING_FIELD_HEIGHT;
        } while (playingField.getObject(pos) != nullptr);

        Spaceship* enemy = new Spaceship("Enemy", 100, 100, 100);
        enemy->setPos(pos);

        playingField.addObject(enemy);
    }
}

void Game::displayPlayingField() {
    system("clear");
    playingField.display();
}

bool Game::gameOver(const Spaceship* ship) {
    return typeid(playingField.getObject(ship->getPos())) == typeid(planet);
}

void Game::handleUserInput() {
    char input;
    bool validInput = false;

    Spaceship* playerShip = (Spaceship*)playingField.getObject("Player_1");
    if (!playerShip) {
        cout << "Player ship not found." << std::endl;
        return;
    }

    while (!validInput) {
        cout << "Player " << currentPlayerIndex + 1 << ", enter your move (WASD): ";
        cin >> input;
        switch (input) {
            case 'w':
                playerShip->setPos(playerShip->getPos() - Vector2D(1, 0));
                validInput = true;
                break;
            case 'a':
                playerShip->setPos(playerShip->getPos() - Vector2D(0, 1));
                validInput = true;
                break;
            case 's':
                playerShip->setPos(playerShip->getPos() + Vector2D(1, 0));
                validInput = true;
                break;
            case 'd':
                playerShip->setPos(playerShip->getPos() + Vector2D(0, 1));
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
    GameObj* shipObj = playingField.getObject(PLAYING_FIELD_SHIP);
    if (shipObj == nullptr) {
        return;
    }
    if (shipObj->getName() == PLAYING_FIELD_PLANET) {
        players[currentPlayerIndex].setScore(players[currentPlayerIndex].getScore() - 10);
    }
}

void Game::handleScoring() {
    // Update the player's score based on the game's outcome
    if (playingField.getObject(PLAYING_FIELD_SHIP) == PLAYING_FIELD_PLANET) {
        players[currentPlayerIndex].setScore(
            players[currentPlayerIndex].getScore() - 10);
    } else {
        players[currentPlayerIndex].setScore(
            players[currentPlayerIndex].getScore() + 5);
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
