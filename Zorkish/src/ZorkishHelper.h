#pragma once

class Map;
class Player;

class ZorkishHelper
{
public:
	ZorkishHelper(Player* PlayerCharacter, Map* GameMap);
	~ZorkishHelper();

	Player* GetPlayer();
	Map* GetMap();

private:
	Player* m_player = nullptr;
	Map* m_gameMap = nullptr;
};