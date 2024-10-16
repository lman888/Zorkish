#pragma once

#include "Inventory.h"
#include "Item.h"
#include "Location.h"
#include "Map.h"
#include "Player.h"
#include "Movement.h"
#include "CommandInterface.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

	void RunGame();

private:
	Map* m_gameMap = new Map("mapdata/Locations.txt");


    std::vector<Location*> m_locations;

    Inventory* m_playerInventory = nullptr;
    Item* m_playerLetter = nullptr;
    Player* m_playerCharacter = nullptr;

    Command* m_commandInterface = nullptr;

    std::string m_inputText;
};