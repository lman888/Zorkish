#pragma once
#include <string>
#include <vector>

class Location;

class Map
{
public:
    Map(std::string File);
    ~Map();

    std::vector<Location*> GetMapLocations() const;
    
private:
    void CreateLocations();

    std::vector<std::string> m_locationInformation;
    std::vector<Location*> m_locationsArray;
};
