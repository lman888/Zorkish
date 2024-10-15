#pragma once

class Inventory;
class Location;

class Player
{
public:
    Player(Location* StartingLocation, Inventory* PlayerInventory);
    ~Player();

    Location* GetCurrentLocation() const;
    
    void ChangeLocations(Location* NewLocation);
    
private:
    Location* m_currentLocation = nullptr;
    Inventory* m_playerInventory = nullptr;
};
