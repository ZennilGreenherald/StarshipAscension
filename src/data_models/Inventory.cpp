#include "../../include/data_models/Inventory.h"

// Add item to inventory
void Inventory::addItem(const Item& item) {
    auto it = items.find(item.getName());
    if (it != items.end()) {
        it->second.setQuantity(it->second.getQuantity() + item.getQuantity());
    } else {
        items[item.getName()] = item;
    }
    std::cout << "Added " << item.getQuantity() << " " << item.getName() << "(s) to inventory." << std::endl;
}

// Remove item from inventory
void Inventory::removeItem(const std::string& itemName, int quantity) {
    auto it = items.find(itemName);
    if (it != items.end()) {
        if (it->second.getQuantity() >= quantity) {
            it->second.setQuantity(it->second.getQuantity() - quantity);
            std::cout << "Removed " << quantity << " " << itemName << "(s)." << std::endl;
            if (it->second.getQuantity() == 0) {
                items.erase(it);  // Remove item if quantity is 0
                std::cout << itemName << " is no longer in the inventory." << std::endl;
            }
        } else {
            std::cout << "Not enough " << itemName << " to remove. Only " << it->second.getQuantity() << " left." << std::endl;
        }
    } else {
        std::cout << itemName << " not found in inventory." << std::endl;
    }
}

// List all items in inventory
void Inventory::listItems() const {
    if (items.empty()) {
        std::cout << "The inventory is empty." << std::endl;
        return;
    }

    std::cout << "Inventory List:" << std::endl;
    for (const auto& item : items) {
        std::cout << item.second.getName() << " (Type: " 
                  << static_cast<int>(item.second.getType()) 
                  << ") - Quantity: " << item.second.getQuantity() 
                  << ", Weight: " << item.second.getWeight() << "kg"
                  << (item.second.getIsUsable() ? ", Usable" : "") << std::endl;
    }
}

// Use an item from the inventory
void Inventory::useItem(const std::string& itemName) {
    auto it = items.find(itemName);
    if (it != items.end() && it->second.getIsUsable()) {
        std::cout << "You used " << itemName << "." << std::endl;
        removeItem(itemName, 1);  // Remove 1 item when used
    } else {
        std::cout << "Item " << itemName << " is not usable or does not exist in inventory." << std::endl;
    }
}
