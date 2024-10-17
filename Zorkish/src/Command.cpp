#include "Command.h"

//Zorkish Files
#include "Movement.h"
#include "Look.h"

Command::Command()
{
	
}

Command::Command(ZorkishHelper* zorkHelper)
{
	m_zorkHelper = zorkHelper;
}

void Command::CommandType(std::string textCommand)
{
	for (const auto& lookCommand : m_commandWords.LookWords)
	{
		if (lookCommand == textCommand)
		{
			//Perform Look Action
			Look look;

			look.LookAroundLocation(lookCommand, m_zorkHelper);
			return;
		}
	}

	for (const auto& moveCommand : m_commandWords.MoveWords)
	{
		if (moveCommand == textCommand)
		{
			//Perform Movement Action
			Movement MoveCommand;

			MoveCommand.CommandType(textCommand);
			return;
		}
	}
}