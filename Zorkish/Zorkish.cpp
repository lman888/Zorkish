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

    //Clean Up
    delete GameMap;
    delete PlayerInventory;
    delete PlayerLetter;
    delete PlayerCharacter;
    delete MovementInput;
    
    GameMap = nullptr;
    PlayerInventory = nullptr;
    PlayerLetter = nullptr;
    PlayerCharacter = nullptr;
    MovementInput = nullptr;
    
    return 0;
}