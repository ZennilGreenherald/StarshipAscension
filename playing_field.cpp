#include "playing_field.h"

#include <iostream>

PlayingField::PlayingField() {
    field.resize(PLAYING_FIELD_HEIGHT,
                 std::vector<char>(PLAYING_FIELD_WIDTH, PLAYING_FIELD_EMPTY));
}

void PlayingField::initialize() {
    for (int i = 0; i < PLAYING_FIELD_HEIGHT; i++) {
        for (int j = 0; j < PLAYING_FIELD_WIDTH; j++) {
            if (i == 0 || i == PLAYING_FIELD_HEIGHT - 1 || j == 0 ||
                j == PLAYING_FIELD_WIDTH - 1) {
                field[i][j] = PLAYING_FIELD_BORDER;
            } else {
                field[i][j] = PLAYING_FIELD_EMPTY;
            }
        }
    }
}

void PlayingField::addObject(char object, int row, int col) {
    field[row][col] = object;
}

void PlayingField::removeObject(int row, int col) {
    field[row][col] = PLAYING_FIELD_EMPTY;
}

char PlayingField::getObject(int row, int col) const { return field[row][col]; }

void PlayingField::moveObject(char object, int rowOffset, int colOffset) {
    int row, col;
    for (int i = 0; i < PLAYING_FIELD_HEIGHT; i++) {
        for (int j = 0; j < PLAYING_FIELD_WIDTH; j++) {
            if (field[i][j] == object) {
                row = i;
                col = j;
                break;
            }
        }
    }
    field[row][col] = PLAYING_FIELD_EMPTY;
    field[row + rowOffset][col + colOffset] = object;
}

void PlayingField::display() const {
    for (int i = 0; i < PLAYING_FIELD_HEIGHT; i++) {
        for (int j = 0; j < PLAYING_FIELD_WIDTH; j++) {
            std::cout << field[i][j];
        }
        std::cout << std::endl;
    }
}
