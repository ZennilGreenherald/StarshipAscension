#include <iostream>

#include "docking_module.h"
#include "game.h"
#include "menu.h"
#include "movement.h"
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
Player players;
int currentPlayerIndex = 0;
char playingField[PLAYING_FIELD_HEIGHT][PLAYING_FIELD_WIDTH];

int main() {
    display_menu();
    initialize_playing_field();
    display_playing_field();

    // Create instances of the necessary classes
    Movement movement;
    ShieldsManager shieldsManager;
    WeaponsManager weaponsManager;
    Ship ship;
    Station station;
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
