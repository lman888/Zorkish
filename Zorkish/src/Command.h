#pragma once
#include "CommandInterface.h"

class Map;
class Player;

struct Commands
{
	std::string MoveWords[4] {"walk", "run", "go", "gander"};
	std::string LookWords[3]{ "look", "see", "move"};
};

class Command : CommandInterface
{
public:
	Command();
	Command(Map* GameMap, Player* PlayerCharacter);
	virtual void CommandType(std::string textCommand) override;

private:
	Commands m_commandWords;

	Player* m_player = nullptr;
	Map* m_map = nullptr;
};