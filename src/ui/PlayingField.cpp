#include "../../include/ui/PlayingField.h"  // Include the PlayingField header file

#include <iostream>
#include <string>

#include "../../include/ui/Display.h"  // Include the Display header file

// Constants for the terminal size
constexpr int TERMINAL_WIDTH = 207;
constexpr int TERMINAL_HEIGHT = 56;

PlayingField::PlayingField() {
    // Initialize the playing field based on the terminal size
    initializeField(TERMINAL_WIDTH, TERMINAL_HEIGHT);
}

void PlayingField::initializeField(int width, int height) {
    // Set the playing field size
    PLAYING_FIELD_WIDTH = width;
    PLAYING_FIELD_HEIGHT = height;

    // Initialize the playing field with empty spaces
    field.resize(height, std::vector<char>(width, ' '));

    // Add the border to the playing field
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                field[i][j] = PLAYING_FIELD_BORDER;
            }
        }
    }
}

// ... (rest of your PlayingField class implementation)

void PlayingField::display() const {
    Display display;

    std::string fieldString;

    // Convert the  2D field vector to a string
    for (const auto &row : field) {
        for (const auto &cell : row) {
            fieldString += cell;
        }
        fieldString += "\n";
    }

    std::cout << fieldString;
}
