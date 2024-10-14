#include "Command.h"
#include "Movement.h"

void Command::CommandType(std::string a_Command)
{
	for (const auto& command : commandWords.LookWords)
	{
		if (command == a_Command)
		{

		}
	}

	for (const auto& command : commandWords.MoveWords)
	{
		if (command == a_Command)
		{

		}
	}
}