﻿#include "Movement.h"
#include <iostream>
#include "Map.h"
#include "Player.h"
#include "Location.h"

Movement::Movement(Map* a_Map, Player* a_Player)
{
    MapLocations = a_Map;
    PlayerCharacter = a_Player;
    bIsMoving = false;
    bIsLooking = false;
}

Movement::~Movement()
{
	delete MapLocations;
	delete PlayerCharacter;
	MapLocations = nullptr;
	PlayerCharacter = nullptr;
}

void Movement::CommandType(std::string a_Command)
{
	/* Moving (Need to implement this better) */
	std::string CommandWord = a_Command.substr(0, a_Command.find(" "));

	for (const auto& MoveWord : Commands.MoveWords)
	{
		if (CommandWord == MoveWord)
		{
			bIsMoving = true;
		}
	}

	if (bIsMoving)
	{
		std::vector<std::string> LocationConnections = PlayerCharacter->GetCurrentLocation()->GetLocationConnections();

		for (const auto& location : LocationConnections)
		{
			if (a_Command.find(location) != std::string::npos)
			{
				for (const auto& ChosenLocation : MapLocations->GetMapLocations())
				{
					if (ChosenLocation->GetLocationName() == location)
					{
						std::cout << "Moving to Location: " << location << "\n";
						PlayerCharacter->ChangeLocations(ChosenLocation);
						bIsMoving = false;
					}
				}
			}
		}
	}
}

//void Movement::ChangeLocations(std::string a_MovementText)
//{
//    /* Looking (Need to implement this better) */
//    for (const auto& LookWord : Commands.LookWords)
//    {
//        if (CommandWord == LookWord)
//        {
//            bIsLooking = true;
//        }
//    }
//
//    if (bIsLooking)
//    {
//        std::cout << PlayerCharacter->GetCurrentLocation()->GetLocationDescription() << "\n";
//        std::cout << "Off in the distance you see: ";
//        for (auto const& location: PlayerCharacter->GetCurrentLocation()->GetLocationConnections())
//        {
//            std::cout << location << " ";
//            bIsLooking = false;
//        }
//        std::cout << "\n";
//    }
//}