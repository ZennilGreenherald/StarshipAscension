#ifndef GAME_H
#define GAME_H

#include <vector>

struct GameState {
    // Define GameState members here (e.g., enums, variables)
    bool isGameRunning;
    int currentScore;
    // Add other state variables as needed
};

class Game {
public:
    enum class InputType {
        None,
        MenuSelection,
        PlayerMovement,
        // Add other input types as needed
    };

    struct InputData {
        InputType type;
        int value; // For numeric inputs
        // Add other relevant data as needed
    };

    Game();
    bool isRunning() const;
    void handleInput(InputType inputType, int inputValue);
    void update();
    void start();

private:
    GameState gameState;
    GameState currentState;
    std::vector<InputData> inputHistory;

    // Helper methods for handling different types of input
    void handleMenuSelection(int choice);
    void handlePlayerMovement(int direction);
};

#endif
