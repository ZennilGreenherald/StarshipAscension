#include <cstdlib>
#include <iostream>

#include "docking_module.h"
#include "game.h"
#include "movement.h"
#include "player.h"
#include "shields_manager.h"
#include "ship.h"
#include "station.h"
#include "vector2d.h"
#include "weapons_manager.h"

using namespace std;

// Constants for playing field objects
const int NUM_STARBASES = 3;
const int NUM_MOONS = 5;
const int NUM_ENEMY_SHIPS = 10;

// Declare global variables
Player players[2];
int currentPlayerIndex = 0;
char playingField[PLAYING_FIELD_HEIGHT][PLAYING_FIELD_WIDTH];

// Declare functions and classes
void display_menu();
void initialize_playing_field();
void display_playing_field();
bool game_over();
void handle_user_input();
void update_playing_field();
void handle_collisions();
void handle_scoring();
void display_high_score();

int main() {
    display_menu();
    initialize_playing_field();
    display_playing_field();

    // Create instances of the necessary classes
    Movement movement;
    ShieldsManager shieldsManager;
    WeaponsManager weaponsManager;
    Spaceship ship;
    Station station("", 0, 0, 0);
    DockingModule dockingModule;
    Vector2D vector2D;

    while (!game_over()) {
        handle_user_input();
        update_playing_field();
        display_playing_field();
        handle_collisions();
    }

    handle_scoring();
    display_high_score();

    return 0;
}

void display_menu() {
    // Display the name of the game and ask for the number of players
    cout << "Welcome to Space Game!" << endl;
    cout << "How many players? (1 or 2)" << endl;

    // Read the number of players from the keyboard
    int numPlayers;
    cin >> numPlayers;

    // Initialize the players' scores to 0
    for (int i = 0; i < numPlayers; i++) {
        players[i].setScore(0);
    }

    // Display the high score and prompt the user to start the game
    cout << "High Score: " << players[0].score() << endl;
    cout << "Press any key to start the game..." << endl;
    cin.ignore();
    cin.get();
}

void initialize_playing_field() {
    // Initialize the playing field with empty spaces
    for (int i = 0; i < PLAYING_FIELD_HEIGHT; i++) {
        for (int j = 0; j < PLAYING_FIELD_WIDTH; j++) {
            if (i == 0 || i == PLAYING_FIELD_HEIGHT - 1 || j == 0 ||
                j == PLAYING_FIELD_WIDTH - 1) {
                playingField[i][j] = PLAYING_FIELD_BORDER;
            } else {
                playingField[i][j] = PLAYING_FIELD_EMPTY;
            }
        }
    }

    // Add a ship and a planet to the playing field
    playingField[PLAYING_FIELD_HEIGHT / 2][PLAYING_FIELD_WIDTH / 2] =
        PLAYING_FIELD_SHIP;
    playingField[PLAYING_FIELD_HEIGHT / 4][PLAYING_FIELD_WIDTH / 4] =
        PLAYING_FIELD_PLANET;

    // Add starbases, moons, and enemy ships to the playing field
    for (int i = 0; i < NUM_STARBASES; i++) {
        int x, y;
        do {
            x = rand() % PLAYING_FIELD_WIDTH;
            y = rand() % PLAYING_FIELD_HEIGHT;
        } while (playingField[y][x] != PLAYING_FIELD_EMPTY);
        playingField[y][x] = PLAYING_FIELD_STARBASE;
    }

    for (int i = 0; i < NUM_MOONS; i++) {
        int x, y;
        do {
            x = rand() % PLAYING_FIELD_WIDTH;
            y = rand() % PLAYING_FIELD_HEIGHT;
        } while (playingField[y][x] != PLAYING_FIELD_EMPTY);
        playingField[y][x] = PLAYING_FIELD_MOON;
    }

    for (int i = 0; i < NUM_ENEMY_SHIPS; i++) {
        int x, y;
        do {
            x = rand() % PLAYING_FIELD_WIDTH;
            y = rand() % PLAYING_FIELD_HEIGHT;
        } while (playingField[y][x] != PLAYING_FIELD_EMPTY);
        playingField[y][x] = PLAYING_FIELD_ENEMY_SHIP;
    }
}

void display_playing_field() {
    // Clear the console window
    system("clear");

    // Display the playing field
    for (int i = 0; i < PLAYING_FIELD_HEIGHT; i++) {
        for (int j = 0; j < PLAYING_FIELD_WIDTH; j++) {
            cout << playingField[i][j];
        }
        cout << endl;
    }
}

bool game_over() {
    // Game over if the ship collides with the planet
    return playingField[ship.getY()][ship.getX()] ==
           PLAYING_FIELD_PLANET;
}

void handle_user_input() {
    // Move the ship based on user input
    Movement movement;
    char input;
    bool validInput = false;
    while (!validInput) {
        cout << "Player " << currentPlayerIndex + 1
             << ", enter your move (WASD): ";
        cin >> input;
        switch (input) {
            case 'w':
                movement.moveUp(ship, playingField);
                validInput = true;
                break;
            case 'a':
                movement.moveLeft(spaceship, playingField);
                validInput = true;
                break;
            case 's':
                movement.moveDown(spaceship, playingField);
                validInput = true;
                break;
            case 'd':
                movement.moveRight(spaceship, playingField);
                validInput = true;
                break;
            default:
                cout << "Invalid input. Please enter W, A, S, or D." << endl;
                break;
        }
    }
}

void update_playing_field() {
    // Update the playing field based on game logic
    ShieldsManager shieldsManager;
    WeaponsManager weaponsManager;
    Spaceship ship;
    shieldsManager.updateShields(ship);
    weaponsManager.updateWeapons(ship);
}

void handle_collisions() {
    // Handle collisions between objects in the game
    if (playingField[ship.getY()][ship.getX()] == PLAYING_FIELD_PLANET) {
        players[currentPlayerIndex].score -= 10;
    }
}

void handle_scoring() {
    // Update the player's score based on the game's outcome
    if (playingField[spaceship.getY()][spaceship.getX()] ==
        PLAYING_FIELD_PLANET) {
        players[currentPlayerIndex].setScore(
            players[currentPlayerIndex].score() - 10);
    } else {
        players[currentPlayerIndex].setScore(
            players[currentPlayerIndex].score() + 5);
    }

    // Switch to the next player
    currentPlayerIndex = (currentPlayerIndex + 1) % 2;
}

void display_high_score() {
    // Check which player has the highest score
    int highestScore = players[0].score();
    int highestScoreIndex = 0;
    for (int i = 1; i < 2; i++) {
        if (players[i].score() > highestScore) {
            highestScore = players[i].score();
            highestScoreIndex = i;
        }
    }

    // Display the high score and the name of the winning player
    cout << "High Score: " << players[0].score() << endl;
    cout << "Player " << highestScoreIndex + 1 << " wins!" << endl;
}
