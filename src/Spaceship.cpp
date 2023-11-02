#include "./include/Spaceship.h"

Spaceship::Spaceship()
	: maxHealth(0), health(0), maxFuel(0), fuel(0), maxAmmo(0), ammo(0)
{
}

Spaceship::Spaceship(std::string name, const uint32_t maxHealth, const uint32_t maxFuel, const uint32_t maxAmmo)
	: GameObj(std::move(name)), maxHealth(maxHealth), health(maxHealth), maxFuel(maxFuel), fuel(maxFuel),
	maxAmmo(maxAmmo), ammo(maxAmmo)
{
}

Spaceship::Spaceship(Serializer& ser)
	: GameObj(ser), maxHealth(ser.read<uint32_t>()), health(ser.read<uint32_t>()), maxFuel(ser.read<uint32_t>()),
	fuel(ser.read<uint32_t>()), maxAmmo(ser.read<uint32_t>()), ammo(ser.read<uint32_t>())
{
}

Spaceship::Spaceship(Spaceship&& ship) noexcept
	: GameObj(std::move(ship)), maxHealth(ship.maxHealth), health(ship.health), maxFuel(ship.maxFuel), fuel(ship.fuel),
	  maxAmmo(ship.maxAmmo), ammo(ship.ammo)
{
	ship.maxHealth = 0;
	ship.health = 0;
	ship.maxFuel = 0;
	ship.fuel = 0;
	ship.maxAmmo = 0;
	ship.ammo = 0;
}

Spaceship::Spaceship(const Spaceship& ship)
	: GameObj(ship), maxHealth(ship.maxHealth), health(ship.health), maxFuel(ship.maxFuel), fuel(ship.fuel),
	maxAmmo(ship.maxAmmo), ammo(ship.ammo)
{
}

Spaceship& Spaceship::operator=(Spaceship&& ship) noexcept
{
	if (this == &ship)
		return *this;

	GameObj::operator=(std::move(ship));

	maxHealth = ship.maxHealth;
	health = ship.health;
	maxFuel = ship.maxFuel;
	fuel = ship.fuel;
	maxAmmo = ship.maxAmmo;
	ammo = ship.ammo;

	ship.maxHealth = 0;
	ship.health = 0;
	ship.maxFuel = 0;
	ship.fuel = 0;
	ship.maxAmmo = 0;
	ship.ammo = 0;

	return *this;
}

Spaceship& Spaceship::operator=(const Spaceship& ship)
{
	if (this == &ship)
		return *this;

	GameObj::operator=(ship);

	maxHealth = ship.maxHealth;
	health = ship.health;
	maxFuel = ship.maxFuel;
	fuel = ship.fuel;
	maxAmmo = ship.maxAmmo;
	ammo = ship.ammo;

	return *this;
}

void Spaceship::serialize(Serializer& ser)
{
	GameObj::serialize(ser);

	ser.write(maxHealth);
	ser.write(health);
	ser.write(maxFuel);
	ser.write(fuel);
	ser.write(maxAmmo);
	ser.write(ammo);
}

void Spaceship::deserialize(Serializer& ser)
{
	GameObj::deserialize(ser);

	maxHealth = ser.read<uint32_t>();
	health = ser.read<uint32_t>();
	maxFuel = ser.read<uint32_t>();
	fuel = ser.read<uint32_t>();
	maxAmmo = ser.read<uint32_t>();
	ammo = ser.read<uint32_t>();
}

uint32_t Spaceship::getMaxHealth() const
{
	return maxHealth;
}

uint32_t Spaceship::getHealth() const
{
	return health;
}

void Spaceship::repair(const uint32_t amount)
{
	health += amount;
	if (health > maxHealth)
		health = maxHealth;
}

uint32_t Spaceship::getMaxFuel() const
{
	return maxFuel;
}

uint32_t Spaceship::getFuel() const
{
	return fuel;
}

void Spaceship::refuel(const uint32_t amount)
{
	fuel += amount;
	if (fuel > maxFuel)
		fuel = maxFuel;
}

uint32_t Spaceship::getMaxAmmo() const
{
	return maxAmmo;
}

uint32_t Spaceship::getAmmo() const
{
	return ammo;
}

void Spaceship::restock(const uint32_t amount)
{
	ammo += amount;
	if (ammo > maxAmmo)
		ammo = maxAmmo;
}

Spaceship* Spaceship::Clone() const
{
	return new Spaceship(*this);
}

std::string Spaceship::getDisplay() const
{
	return "S";
}
