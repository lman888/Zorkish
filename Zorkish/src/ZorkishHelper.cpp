#include "ZorkishHelper.h"

//Zorkish Files
#include "Map.h"
#include "Player.h"

ZorkishHelper::ZorkishHelper(Player* PlayerCharacter, Map* GameMap)
{
	m_player = PlayerCharacter;
	m_gameMap = GameMap;
}

ZorkishHelper::~ZorkishHelper()
{
	m_player = nullptr;
	m_gameMap = nullptr;
}

Player* ZorkishHelper::GetPlayer()
{
	return m_player;
}

Map* ZorkishHelper::GetMap()
{
	return m_gameMap;
}