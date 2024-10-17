#pragma once

#include <iostream>

class ZorkishHelper;

struct Commands
{
	std::string MoveWords[4] {"walk", "run", "go", "gander"};
	std::string LookWords[3]{ "look", "see", "move"};
};

class Command
{
public:
	Command();
	Command(ZorkishHelper* zorkHelper);
	void CommandType(std::string textCommand);

private:
	Commands m_commandWords;

	ZorkishHelper* m_zorkHelper = nullptr;
};