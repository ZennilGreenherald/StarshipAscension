#include "game.h"
#include <iostream>

using namespace std;

// Declare global variables
Player players[2];
int currentPlayerIndex = 0;
char playingField[PLAYING_FIELD_HEIGHT][PLAYING_FIELD_WIDTH];

int main()
{
	display_menu();
	initialize_playing_field();
	display_playing_field();

	while (!game_over())
	{
		handle_user_input();
		update_playing_field();
		display_playing_field();
		handle_collisions();
	}

	handle_scoring();
	display_high_score();
	return 0;
}

void display_menu()
{
	// Display the name of the game and ask for the number of players
	cout << "Welcome to Space Game!" << endl;
	cout << "How many players? (1 or 2)" << endl;

	// Read the number of players from the keyboard
	int numPlayers;
	cin >> numPlayers;

	// Initialize the players' scores to 0
	for (int i = 0; i < numPlayers; i++)
	{
		players[i].score = 0;
	}

	// Display the high score and prompt the user to start the game
	cout << "High Score: " << players[0].score << endl;
	cout << "Press any key to start the game..." << endl;
	cin.ignore();
	cin.get();
}

const char PLAYING_FIELD_STARBASE = 'B';
const char PLAYING_FIELD_MOON = 'M';
const char PLAYING_FIELD_ENEMY_SHIP = 'E';

void initialize_playing_field()
{
	// Initialize the playing field with empty spaces
	for (int i = 0; i < PLAYING_FIELD_HEIGHT; i++)
	{
		for (int j = 0; j < PLAYING_FIELD_WIDTH; j++)
		{
			if (i == 0 || i == PLAYING_FIELD_HEIGHT - 1 || j == 0 || j == PLAYING_FIELD_WIDTH - 1)
			{
				playingField[i][j] = PLAYING_FIELD_BORDER;
			}
			else
			{
				playingField[i][j] = PLAYING_FIELD_EMPTY;
			}
		}
	}

	// Add a ship and a planet to the playing field
	playingField[PLAYING_FIELD_HEIGHT / 2][PLAYING_FIELD_WIDTH / 2] = PLAYING_FIELD_SHIP;
	playingField[PLAYING_FIELD_HEIGHT / 4][PLAYING_FIELD_WIDTH / 4] = PLAYING_FIELD_PLANET;

	// Add starbases, moons, and enemy ships to the playing field
	for (int i = 0; i < NUM_STARBASES; i++)
	{
		int x, y;
		do
		{
			x = rand() % PLAYING_FIELD_WIDTH;
			y = rand() % PLAYING_FIELD_HEIGHT;
		} while (playingField[y][x] != PLAYING_FIELD_EMPTY);

		playingField[y][x] = PLAYING_FIELD_STARBASE;
	}

	for (int i = 0; i < NUM_MOONS; i++)
	{
		int x, y;
		do
		{
			x = rand() % PLAYING_FIELD_WIDTH;
			y = rand() % PLAYING_FIELD_HEIGHT;
		} while (playingField[y][x] != PLAYING_FIELD_EMPTY);

		playingField[y][x] = PLAYING_FIELD_MOON;
	}

	for (int i = 0; i < NUM_ENEMY_SHIPS; i++)
	{
		int x, y;
		do
		{
			x = rand() % PLAYING_FIELD_WIDTH;
			y = rand() % PLAYING_FIELD_HEIGHT;
		} while (playingField[y][x] != PLAYING_FIELD_EMPTY);

		playingField[y][x] = PLAYING_FIELD_ENEMY_SHIP;
	}
}

void display_playing_field()
{
	// Clear the console window
	system("clear");

	// Display the playing field
	for (int i = 0; i < PLAYING_FIELD_HEIGHT; i++)
	{
		for (int j = 0; j < PLAYING_FIELD_WIDTH; j++)
		{
			cout << playingField[i][j];
		}
		cout << endl;
	}
}

bool game_over()
{
	// Game over if the ship collides with the planet
	return playingField[10][10] == PLAYING_FIELD_PLANET;
}

void handle_user_input()
{
	// Move the ship based on user input
	char input;
	bool validInput = false;
	while (!validInput)
	{
		cout << "Player " << currentPlayerIndex + 1 << ", enter your move (WASD): ";
		cin >> input;

		switch (input)
		{
		case 'w':
			playingField[10][10] = PLAYING_FIELD_STAR;
			playingField[9][10] = PLAYING_FIELD_SHIP;
			validInput = true;
			break;
		case 'a':
			playingField[10][10] = PLAYING_FIELD_STAR;
			playingField[10][9] = PLAYING_FIELD_SHIP;
			validInput = true;
			break;
		case 's':
			playingField[10][10] = PLAYING_FIELD_STAR;
			playingField[11][10] = PLAYING_FIELD_SHIP;
			validInput = true;
			break;
		case 'd':
			playingField[10][10] = PLAYING_FIELD_STAR;
			playingField[10][11] = PLAYING_FIELD_SHIP;
			validInput = true;
			break;
		default:
			cout << "Invalid input. Please enter W, A, S, or D." << endl;
			break;
		}
	}
}

void update_playing_field()
{
	// Update the playing field based on game logic
}

void handle_collisions()
{
	// Handle collisions between objects in the game
	if (playingField[10][10] == PLAYING_FIELD_PLANET)
	{
		players[currentPlayerIndex].score -= 10;
	}
}

void handle_scoring()
{
	// Update the player's score based on the game's outcome
	if (playingField[10][10] == PLAYING_FIELD_PLANET)
	{
		players[currentPlayerIndex].score -= 10;
	}
	else
	{
		players[currentPlayerIndex].score += 5;
	}

	// Switch to the next player
	currentPlayerIndex = (currentPlayerIndex + 1) % 2;
}

void display_high_score()
{
	// Check which player has the highest score
	int highestScore = players[0].score;
	int highestScoreIndex = 0;

	for (int i = 1; i < 2; i++)
	{
		if (players[i].score > highestScore)
		{
			highestScore = players[i].score;
			highestScoreIndex = i;
		}
	}

	// Display the high score and the name of the winning player
	cout << "High Score: " << highestScore << endl;
	cout << "Player " << highestScoreIndex + 1 << " wins!" << endl;
}
