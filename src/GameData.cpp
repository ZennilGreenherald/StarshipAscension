#include "./include/GameData.h"

#include <ios>

#include "./include/Serializer.h"

int main() {
    Serializer serializer;
    GameData gameData;

    // Write game data to serializer
    serializer.write(gameData);

    // Save serializer data to file
    std::ofstream file("game_data.bin", std::ios::binary);
    file.write((char*)serializer, serializer.getSize());
    file.close();

    // Load serializer data from file
    std::ifstream file("game_data.bin", std::ios::binary);
    file.seekg(0, std::ios::end);
    size_t fileSize = file.tellg();
    file.seekg(0, std::ios::beg);
    unsigned char* buffer = new unsigned char[fileSize];
    file.read((char*)buffer, fileSize);
    file.close();

    // Read game data from serializer
    serializer = Serializer(buffer, fileSize);
    gameData = serializer.read<GameData>();

    return 0;
}