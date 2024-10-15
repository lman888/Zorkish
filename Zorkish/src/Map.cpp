#include "Map.h"
#include <fstream>
#include <vector>

#include "Location.h"
#include "Item.h"

Map::Map(std::string File)
{
    std::string fileLine;
    std::ifstream mapFile(File);
    
    if (mapFile.is_open())
    {
        while (std::getline(mapFile, fileLine, '\n'))
        {
            if (fileLine.empty())
            {
                continue;
            }
            m_locationInformation.push_back(fileLine);
        }
    }
    
    CreateLocations();
}

Map::~Map()
{
	for (int i = m_locationsArray.size() - 1; i >= 0; --i)
	{
		delete m_locationsArray[i];
        m_locationsArray[i] = nullptr;
	}
}

std::vector<Location*> Map::GetMapLocations() const
{
    return m_locationsArray;
}

void Map::CreateLocations()
{
    // Turn into TMAP?
    int informationSize = 3;
    for (int i = 0; i < m_locationInformation.size(); i += informationSize)
    {
        std::string locationName = m_locationInformation[i];
        std::string locationDescription = m_locationInformation[i + 1];
        std::string locationConnection = m_locationInformation[i + 2];

        Location* newLocation = new Location(locationName, locationDescription, locationConnection);
        if (newLocation != nullptr)
        {
            m_locationsArray.push_back(newLocation);
        }
    }
}