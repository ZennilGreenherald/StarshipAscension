#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <string>

class GameData {
public:
    int level;
    int score;
    std::string playerName;

    template<class Archive>
    void serialize(Archive & archive)
    {
        archive(level, score, playerName);
    }
};

#endif
