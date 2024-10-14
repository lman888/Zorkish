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
    Inventory* PlayerInventory = new Inventory();
    Item* PlayerLetter = new Item();
    PlayerInventory->AddItemToInventory("Letter", PlayerLetter);
    Map* GameMap = new Map("Locations.txt");
    std::vector<Location*> locations = GameMap->GetMapLocations();
    Player* PlayerCharacter = new Player(locations[0], PlayerInventory);
    CommandInterface* MovementInput = new Movement(GameMap, PlayerCharacter);

    std::string MovementText;

    std::cout << "Welcome to Zorkish Alpha 0.1" << "\n";
    while (MovementText != "quit")
    {
        std::cin >> MovementText;
        MovementInput->ProcessCommand(MovementText);
    }
    
    std::cout << PlayerCharacter->GetCurrentLocation()->GetLocationName() << "\n";
    PlayerInventory->ShowInventory();
    
    return 0;
}