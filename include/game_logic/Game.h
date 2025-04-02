
#ifndef GAME_H
#define GAME_H

#include <vector>

struct GameState {
    bool isGameRunning;
    int currentScore;
    // Add additional game state variables as necessary
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
        int value;  // For numeric inputs
    };

    Game();
    bool isRunning() const;
    void handleInput(InputType inputType, int inputValue);
    void update();
    void start();

  private:
    GameState gameState;  // Primary game state
    std::vector<InputData> inputHistory;

    void handleMenuSelection(int choice);
    void handlePlayerMovement(int direction);
};

#endif  // GAME_H
