#include <iostream>

#include "Inventory.h"
#include "Item.h"
#include "Location.h"
#include "Map.h"
#include "Player.h"
#include "Movement.h"
#include "CommandInterface.h"

int main(int argc, char* argv[])
{
    Map* GameMap = new Map("Locations.txt");
    if (GameMap == nullptr)
    {
        std::cout << "No Valid Game Map." << std::endl;
        return 0;
    }

    std::vector<Location*> locations = GameMap->GetMapLocations();
    
    Inventory* PlayerInventory = new Inventory();
    Item* PlayerLetter = new Item();
    PlayerInventory->AddItemToInventory("Letter", PlayerLetter);
    Player* PlayerCharacter = new Player(locations[0], PlayerInventory);
    
    CommandInterface* MovementInput = new Movement(GameMap, PlayerCharacter);

    std::string MovementText;

    std::cout << "Welcome to Zorkish Alpha 0.1" << "\n";
    while (MovementText != "quit")
    {
        std::cin >> MovementText;
        MovementInput->CommandType(MovementText);
    }
    
    std::cout << PlayerCharacter->GetCurrentLocation()->GetLocationName() << "\n";
    PlayerInventory->ShowInventory();
    PlayerInventory->RemoveItemInInventory("Letter");

    //Clean Up Pointers and memory
    delete GameMap;
    GameMap = nullptr;

    delete PlayerInventory;
    PlayerInventory = nullptr;

    delete PlayerLetter;
    PlayerLetter = nullptr;

    delete PlayerCharacter;
    PlayerCharacter = nullptr;

    delete MovementInput;
    MovementInput = nullptr;

    if (locations.empty() == false)
    {
        locations.clear();
    }
    
    
    return 0;
}