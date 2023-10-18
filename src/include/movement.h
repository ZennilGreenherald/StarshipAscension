#ifndef MOVEMENT_H
#define MOVEMENT_H

class Movement {
public:
    void move_ship(int dx, int dy);
    void moveUp(Spaceship& spaceship, int playingField[][PLAYING_FIELD_WIDTH]) {
        if (spaceship.getY() > 0) {
            spaceship.setY(spaceship.getY() - 1);
        }
    }
    void moveLeft(Spaceship& spaceship, int playingField[][PLAYING_FIELD_WIDTH]) {
        if (spaceship.getX() > 0) {
            spaceship.setX(spaceship.getX() - 1);
        }
    }
    void moveDown(Spaceship& spaceship, int playingField[][PLAYING_FIELD_WIDTH]) {
        if (spaceship.getY() < PLAYING_FIELD_HEIGHT - 1) {
            spaceship.setY(spaceship.getY() + 1);
        }
    }
    void moveRight(Spaceship& spaceship, int playingField[][PLAYING_FIELD_WIDTH]) {
        if (spaceship.getX() < PLAYING_FIELD_WIDTH - 1) {
            spaceship.setX(spaceship.getX() + 1);
        }
    }
};

#endif
