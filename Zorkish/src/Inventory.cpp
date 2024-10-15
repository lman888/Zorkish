#include "Inventory.h"
#include <iostream>

#include "Item.h"

Inventory::Inventory()
{
}

void Inventory::AddItemToInventory(std::string newItemName, Item* newItem)
{
    m_inventory.insert(std::make_pair(newItemName, newItem));
}

void Inventory::RemoveItemInInventory(const std::string itemName)
{
    auto iterator = m_inventory.find(itemName);
    if (iterator != m_inventory.end())
    {
        m_inventory.erase(itemName);
    }
}

void Inventory::ShowInventory()
{
    if (m_inventory.empty() == true)
    {
        std::cout << "Inventory is empty!" << "\n";
        return;
    }
    
    for (auto const& item : m_inventory)
    {
        Item* chosenItem = item.second;
        if (chosenItem != nullptr)
        {
            std::cout << "Item Key: " << item.first << "\n";
            std::cout << "Item description: " << chosenItem->ShowDescription() << "\n";
        }
    }
}

std::map<std::string, Item*> Inventory::GetInventory() const
{
    return m_inventory;
}