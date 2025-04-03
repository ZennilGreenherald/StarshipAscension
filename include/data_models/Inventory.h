// Inventory.h
#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <map>
#include <iostream>

class Item {
public:
    enum class ItemType {
        Weapon,
        Consumable,
        ShipPart,
        Artifact,
        Misc
    };

    Item(std::string name, int quantity, ItemType type, int weight = 0, bool isUsable = false)
        : name(name), quantity(quantity), type(type), weight(weight), isUsable(isUsable) {}

    const std::string& getName() const { return name; }
    int getQuantity() const { return quantity; }
    ItemType getType() const { return type; }
    int getWeight() const { return weight; }
    bool getIsUsable() const { return isUsable; }

    void setQuantity(int newQuantity) { quantity = newQuantity; }
    void setWeight(int newWeight) { weight = newWeight; }

private:
    std::string name;
    int quantity;
    ItemType type;
    int weight;
    bool isUsable;
};

class Inventory {
public:
    void addItem(const Item& item);
    void removeItem(const std::string& itemName, int quantity);
    void listItems() const;
    void useItem(const std::string& itemName);

private:
    std::map<std::string, Item> items;
};

#endif  // INVENTORY_H
