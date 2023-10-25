#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

class Player {
public:
    // Constructor
    Player(std::string name);

    // Getters
    std::string getName() const;
    int getHealth() const;
    int getScore() const;
    int getDamage() const;
    std::vector<std::string> getInventory() const;
    int getLevel() const;
    int getExperience() const;
    std::vector<std::string> getAbilities() const;
    std::vector<std::string> getEquipment() const;

    // Setters
	void setName(std::string name);
    void setHealth(int health);
    void setScore(int score);
    void setDamage(int damage);
    void addItemToInventory(std::string item);
    void removeItemFromInventory(std::string item);
    void setLevel(int level);
    void setExperience(int experience);
    void addAbility(std::string ability);
    void removeAbility(std::string ability);
    void addEquipment(std::string equipment);
    void removeEquipment(std::string equipment);

private:
    std::string m_name;
    int m_health;
    int m_score;
    int m_damage;
    std::vector<std::string> m_inventory;
    int m_level;
    int m_experience;
    std::vector<std::string> m_abilities;
    std::vector<std::string> m_equipment;
};

#endif // PLAYER_H
