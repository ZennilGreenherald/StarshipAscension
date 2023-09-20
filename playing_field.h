#ifndef PLAYING_FIELD_H
#define PLAYING_FIELD_H

#include <vector>

const int PLAYING_FIELD_HEIGHT = 20;
const int PLAYING_FIELD_WIDTH = 40;

const char PLAYING_FIELD_EMPTY = ' ';
const char PLAYING_FIELD_BORDER = '#';
const char PLAYING_FIELD_SHIP = 'S';
const char PLAYING_FIELD_PLANET = 'P';
const char PLAYING_FIELD_STARBASE = 'B';
const char PLAYING_FIELD_MOON = 'M';
const char PLAYING_FIELD_ENEMY_SHIP = 'E';

class PlayingField {
public:
    PlayingField();
    void initialize();
    void addObject(char object, int row, int col);
    void removeObject(int row, int col);
    char getObject(int row, int col) const;
    void moveObject(char object, int rowOffset, int colOffset);
    void display() const;
private:
    std::vector<std::vector<char>> field;
};

#endif
