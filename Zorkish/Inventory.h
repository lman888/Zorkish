#pragma once
#include <map>
#include <string>

class Item;

class Inventory
{
public:
    Inventory();
    ~Inventory() = default;
    
    void AddItemToInventory(std::string newItemName, Item* newItem);
    void RemoveItemInInventory(std::string itemName);
    void ShowInventory();
    std::map<std::string, Item*> GetInventory() const;
    
private:
    std::map<std::string, Item*> m_inventory;
    
};
