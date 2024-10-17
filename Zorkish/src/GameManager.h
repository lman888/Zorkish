#pragma once

//C++ Files
#include <iostream>
#include <vector>

class Inventory;
class Item;
class Location;
class Map;
class Player;
class Movement;
class Command;
class ZorkishHelper;

class GameManager
{
public:
	GameManager();
	~GameManager();

	void RunGame();

private:
	Map* m_gameMap = nullptr;


    std::vector<Location*> m_locations;

    Inventory* m_playerInventory = nullptr;
    Item* m_playerLetter = nullptr;
    Player* m_playerCharacter = nullptr;
    Command* m_commandInterface = nullptr;
    ZorkishHelper* m_zorkHelper = nullptr;

    std::string m_inputText;
};