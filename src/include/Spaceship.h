#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "GameObj.h"

#include <string>

class Spaceship : public GameObj
{
private:
	// Add the missing field declarations
	uint32_t maxHealth;
	uint32_t health;
	uint32_t maxFuel;
	uint32_t fuel;
	uint32_t maxAmmo;
	uint32_t ammo;

public:
	Spaceship();

	Spaceship(std::string name, const uint32_t maxHealth, const uint32_t maxFuel, const uint32_t maxAmmo);

	Spaceship(Serializer& ser);

	Spaceship(Spaceship&& ship) noexcept;

	Spaceship(const Spaceship& ship);

	Spaceship& operator=(Spaceship&& ship) noexcept;

	Spaceship& operator=(const Spaceship& ship);

	void serialize(Serializer& ser) override;

	void deserialize(Serializer& ser) override;

	uint32_t getMaxHealth() const;

	uint32_t getHealth() const;

	void repair(const uint32_t amount);

	uint32_t getMaxFuel() const;

	uint32_t getFuel() const;

	void refuel(const uint32_t amount);

	uint32_t getMaxAmmo() const;

	uint32_t getAmmo() const;

	void restock(const uint32_t amount);

	std::string getDisplay() const override;

	Spaceship* Clone() const override;

	int getX() const;

	void setX(int x);

	int getY() const;

	void setY(int y);

};

#endif  // SPACESHIP_H
