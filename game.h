#ifndef GAME_H
#define GAME_H

// Define constants for the playing field dimensions
const int PLAYING_FIELD_WIDTH = 80;
const int PLAYING_FIELD_HEIGHT = 24;

// Define the characters used for the playing field

const char PLAYING_FIELD_BORDER = '#';
const char PLAYING_FIELD_EMPTY = ' ';
const char PLAYING_FIELD_SHIP = 'S';
const char PLAYING_FIELD_PLANET = 'P';
const char PLAYING_FIELD_VERTICAL_BORDER = '|';
const char PLAYING_FIELD_HORIZONTAL_BORDER = '-';
const char PLAYING_FIELD_CORNER = '_';
const char PLAYING_FIELD_STAR = '*';


// Define the struct for a player
struct Player {
    int score;
};

// Declare functions
void display_menu();
void initialize_playing_field();
void display_playing_field();
bool game_over();
void handle_user_input();
void update_playing_field();
void handle_collisions();
void handle_scoring();
void display_high_score();

#endif
