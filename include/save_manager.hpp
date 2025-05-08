#ifndef SAVE_MANAGER_HPP
#define SAVE_MANAGER_HPP

#include <string>
#include <filesystem>

class Game {
private:
    std::string playerName;
    int playerPosition;

public:
    // Function to save the game to a file
    void saveGame();

    // Function to load the game from a file
    void loadGame();

    // Function to list all available save files
    void listSaveFiles();

private:
    // Helper functions for saving the game in various formats
    void saveAsPlainText(const std::string &fileName);
    void saveAsXML(const std::string &fileName);
    void saveAsBinary(const std::filesystem::path &filePath);
    void saveAsJSON(const std::string &fileName);

    // Helper functions for loading the game in various formats
    void loadFromPlainText(const std::string &fileName);
    void loadFromXML(const std::string &fileName);
    void loadFromBinary(const std::string &fileName);
    void loadFromJSON(const std::string &fileName);

    // Utility function to clear the screen (optional system-dependent implementation)
    void clearScreen() const;

    // Utility function to display the main menu
    void displayMainMenu() const;
};

#endif // SAVE_MANAGER_HPP
