#ifndef SHIELDS_H
#define SHIELDS_H

#include <string>

class Shields {
public:
    Shields(int initialHealth);
    ~Shields();

    bool areUp() const;
    void raise();
    void lower();
    void repair(int amount);
    void takeDamage(int amount);
    int getHealth() const;
    std::string getStatus() const;

private:
    int health;
};

#endif // SHIELDS_H
