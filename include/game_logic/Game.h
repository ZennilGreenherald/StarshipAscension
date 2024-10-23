#ifndef GAME_H
#define GAME_H

class Game {
public:
    struct GameState {
        // Define GameState members here (e.g., enums, variables)
    };

    // Constructors, destructors, and member functions
    Game();
    bool isRunning() const;
    void handleInput();
    void update();
    void start();
    // Other necessary functions
};

#endif  // GAME_H
