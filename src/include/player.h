#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    Player();
    int getScore() const;
    void setScore(int score);
	int score;
private:
    int score;
};

#endif
