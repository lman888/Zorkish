#include "Player.h"

#include "Inventory.h"

Player::Player(Location* StartingLocation, Inventory* PlayerInventory)
{
    m_currentLocation = StartingLocation;
    m_playerInventory = PlayerInventory;
}

Player::~Player()
{
    m_currentLocation == nullptr;
    m_playerInventory == nullptr;
}

Location* Player::GetCurrentLocation() const
{
    return m_currentLocation;
}

void Player::ChangeLocations(Location* NewLocation)
{
    m_currentLocation = NewLocation;
}
