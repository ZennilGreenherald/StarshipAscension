#ifndef HEALTH_H
#define HEALTH_H

class Health {
private:
    int health; // The current health of the object

public:
    Health(int initialHealth); // Constructor that sets the initial health

    int getHealth() const; // Getter for the health
    void setHealth(int newHealth); // Setter for the health

    void takeDamage(int damage); // Method to reduce health by a given amount
};

#endif // HEALTH_H
