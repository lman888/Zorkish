#include "GameManager.h"

#include <iostream>

GameManager::GameManager()
{
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

    m_movementInput = new Movement(m_gameMap, m_playerCharacter);
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

    delete m_movementInput;
    m_movementInput = nullptr;

    if (m_locations.empty() == false)
    {
        m_locations.clear();
    }
}

void GameManager::RunGame()
{
    std::cout << "Welcome to Zorkish Alpha 0.1" << "\n";
    while (m_movementText != "quit")
    {
        std::cin >> m_movementText;
        m_movementInput->CommandType(m_movementText);
    }
}