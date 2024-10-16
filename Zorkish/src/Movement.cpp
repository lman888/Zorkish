#include "Movement.h"
#include <iostream>

#include "Map.h"
#include "Player.h"
#include "Location.h"

Movement::Movement()
{
}

Movement::Movement(Map* Map, Player* Player)
{
	m_map = Map;
    m_playerCharacter = Player;
}

Movement::~Movement()
{
	m_map = nullptr;
	m_playerCharacter = nullptr;
}

void Movement::CommandType(std::string Command)
{
	/* Moving (Need to implement this better) */
	std::string CommandWord = Command.substr(0, Command.find(" "));

	m_bIsMoving = m_commands.MoveWords->find(CommandWord);

	if (m_bIsMoving == false)
	{
		return;
	}
	if (m_map == nullptr)
	{
		return;
	}
	if (m_playerCharacter == nullptr)
	{
		return;
	}
	Location* CurrentLocation = m_playerCharacter->GetCurrentLocation();
	if (CurrentLocation == nullptr)
	{
		return;
	}

	std::vector<std::string> LocationConnections = CurrentLocation->GetLocationConnections();
	for (const auto& locationConnectionName : LocationConnections)
	{
		if (Command.find(locationConnectionName) != std::string::npos)
		{
			for (const auto& MapLocation : m_map->GetMapLocations())
			{
				if (MapLocation->GetLocationName() == locationConnectionName)
				{
					std::cout << "Moving to Location: " << locationConnectionName << "\n";
					m_playerCharacter->ChangeLocations(MapLocation);
					m_bIsMoving = false;
					return;
				}
			}
		}
	}
}

void Movement::ChangeLocations(std::string a_MovementText)
{
    /* Looking (Need to implement this better) */
    for (const auto& LookWord : m_commands.LookWords)
    {
        if (a_MovementText == LookWord)
        {
            m_bIsLooking = true;
        }
    }

    if (m_bIsLooking)
    {
        std::cout << m_playerCharacter->GetCurrentLocation()->GetLocationDescription() << "\n";
        std::cout << "Off in the distance you see: ";
        for (auto const& location: m_playerCharacter->GetCurrentLocation()->GetLocationConnections())
        {
            std::cout << location << " ";
            m_bIsLooking = false;
        }
        std::cout << "\n";
    }
}