#ifndef SHIP_H
#define SHIP_H

#include <string>

class StarshipAscension {
public:
    StarshipAscension(std::string name, std::string captain, std::string firstOfficer);

    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);

private:
    std::string captain;
    std::string firstOfficer;
	std::string name;
    int health;
    int ammo;
    int fuelStatus;
    int alertStatus;
	int m_x;
    int m_y;
	void updateShields();
    void updateEngineStatus();
    void updateLifeSupportStatus();
    void updateDamageControl();
    void updateAstrometrics();
    void updateScience();
    void updateHailingFrequencies();
    void updateRadio();
    void updateViewscreens();
    void updateSickbayStatus();
    // Add member variables here
};

#endif // SHIP_H
