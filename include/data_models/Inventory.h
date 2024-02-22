// Inventory.h
#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>

struct Item {
    std::string name;
    int quantity;
};

class Inventory {
public:
    void addItem(const std::string& itemName, int quantity);
    void removeItem(const std::string& itemName, int quantity);
    void listItems() const;

private:
    std::vector<Item> items;
};

#endif
