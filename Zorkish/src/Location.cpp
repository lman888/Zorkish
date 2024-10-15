#include "Location.h"
#include <sstream>
#include <iostream>

#include "Item.h"


Location::Location()
{
    m_locationName = "Default Location yet to be made";
    m_locationDescription = "A Location yet to be created";
}

Location::Location(std::string a_locationName, std::string a_locationDescription, std::string a_locationConnections)
{
    m_locationName = a_locationName;
    m_locationDescription = a_locationDescription;
    CreateConnections(a_locationConnections);
}

Location::~Location()
{
	for (int i = m_locationItems.size() - 1; i >= 0; --i)
	{
        m_locationItems[i] = nullptr;
	}
}

std::string Location::GetLocationName() const
{
    return m_locationName;
}

std::string Location::GetLocationDescription() const
{
    return m_locationDescription;
}

std::vector<std::string> Location::GetLocationConnections() const
{
    return m_locationConnections;
}

void Location::CreateConnections(std::string a_locationConnections)
{
    std::istringstream ConnectionStream(a_locationConnections);
    std::string ConnectionName;

    while (std::getline(ConnectionStream, ConnectionName, ' '))
    {
        m_locationConnections.push_back(ConnectionName);
    }
}