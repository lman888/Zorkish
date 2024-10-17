#include "Look.h"

//C++ includes (Debugging)
#include <iostream>

//Zorkish Files
#include "Player.h"
#include "Location.h"
#include "ZorkishHelper.h"

Look::Look()
{
}

void Look::LookAroundLocation(std::string textCommand, ZorkishHelper* zorkishHelper)
{
	std::cout << "In Here." << std::endl;

	std::cout << zorkishHelper->GetPlayer()->GetCurrentLocation()->GetLocationDescription() << "\n";
	std::cout << "Off in the distance you see: ";
	for (auto const& locationConnections : zorkishHelper->GetPlayer()->GetCurrentLocation()->GetLocationConnections())
	{
		std::cout << locationConnections << " ";
	}
	std::cout << "\n";
}