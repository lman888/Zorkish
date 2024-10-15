#pragma once
#include <string>
#include <vector>

class Item;

class Location
{
public:
    Location();
    Location(std::string locationName, std::string locationDescription, std::string locationConnections);
    ~Location();
    
    std::string GetLocationName() const;
    std::string GetLocationDescription() const;
    std::vector<std::string> GetLocationConnections() const;
    
private:
    void CreateConnections(std::string locationConnections);

    std::string m_locationName;
    std::string m_locationDescription;
    std::vector<std::string> m_locationConnections;
    std::vector<Item*> m_locationItems;
    std::vector<std::string> m_locationInformation;
};
