#include "GameManager.h"

//Zorkish Files
#include "Inventory.h"
#include "Item.h"
#include "Location.h"
#include "Map.h"
#include "Player.h"
#include "Movement.h"
#include "Command.h"
#include "ZorkishHelper.h"

GameManager::GameManager()
{
    m_gameMap = new Map("mapdata/Locations.txt");
    if (m_gameMap == nullptr)
    {
        std::cout << "No Valid Game Map." << std::endl;
        return;
    }

    m_locations = m_gameMap->GetMapLocations();

    m_playerInventory = new Inventory();
    m_playerLetter = new Item();
    m_playerInventory->AddItemToInventory("Letter", m_playerLetter);
    m_playerCharacter = new Player(m_locations[0], m_playerInventory);

    m_zorkHelper = new ZorkishHelper(m_playerCharacter, m_gameMap);

    m_commandInterface = new Command(m_zorkHelper);
}

GameManager::~GameManager()
{
    //Clean Up Pointers and memory
    delete m_gameMap;
    m_gameMap = nullptr;

    delete m_playerInventory;
    m_playerInventory = nullptr;

    delete m_playerLetter;
    m_playerLetter = nullptr;

    delete m_playerCharacter;
    m_playerCharacter = nullptr;

    delete m_commandInterface;
    m_commandInterface = nullptr;

    delete m_zorkHelper;
    m_zorkHelper = nullptr;

    if (m_locations.empty() == false)
    {
        m_locations.clear();
    }
}

void GameManager::RunGame()
{
    std::cout << "Welcome to Zorkish Alpha 0.1" << "\n";
    while (m_inputText != "quit")
    {
        std::cin >> m_inputText;
        m_commandInterface->CommandType(m_inputText);
    }
}