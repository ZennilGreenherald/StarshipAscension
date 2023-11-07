#include "./include/GameData.h"
#include "./include/Serializer.h"

#include <fstream>
#include <iostream>
#include <sstream>

int main() {
    Serializer serializer;
    GameData gameData;

    // Write game data to serializer
    serializer.write(gameData);

    // Serialize data to string
    std::stringstream ss;
    ss << serializer;

    // Copy string to buffer
    std::string str = ss.str();
    unsigned char* buffer = new unsigned char[str.size()];
    std::copy(str.begin(), str.end(), buffer);

    // Save buffer to file
    std::ofstream file("game_data.bin", std::ios::binary);
    file.write((char*)buffer, str.size());
    file.close();

    // Load buffer from file
    std::ifstream inFile("game_data.bin", std::ios::binary);
    inFile.seekg(0, std::ios::end);
    size_t fileSize = inFile.tellg();
    inFile.seekg(0, std::ios::beg);
    unsigned char* buffer2 = new unsigned char[fileSize];
    inFile.read((char*)buffer2, fileSize);
    inFile.close();

    // Deserialize data from buffer
    std::string str2((char*)buffer2, fileSize);
    std::stringstream ss2(str2);
    ss2 >> serializer;
    gameData = serializer.read<GameData>();

    return 0;
}
