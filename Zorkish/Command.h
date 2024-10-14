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
	void CommandType(std::string a_Command) override;

private:

	CommandWords commandWords;
};