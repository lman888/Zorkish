#include "Command.h"
#include "Movement.h"

void Command::CommandType(std::string textCommand)
{
	for (const auto& command : m_commandWords.LookWords)
	{
		if (command == textCommand)
		{

		}
	}

	for (const auto& command : m_commandWords.MoveWords)
	{
		if (command == textCommand)
		{

		}
	}
}