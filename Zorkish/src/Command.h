#pragma once
#include "CommandInterface.h"

struct CommandWords
{
	std::string MoveWords[4] {"walk", "run", "go", "gander"};
	std::string LookWords[3]{ "look", "see", "move"};
};
class Command : CommandInterface
{
public:
	virtual void CommandType(std::string textCommand) override;

private:
	CommandWords m_commandWords;
};