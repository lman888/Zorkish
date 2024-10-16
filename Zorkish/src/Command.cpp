#include "Command.h"

//Zorkish Files
#include "Movement.h"
#include "Look.h"

Command::Command()
{
}

Command::Command(Map* GameMap, Player* PlayerCharacter)
{
	m_map = GameMap;
	PlayerCharacter = m_player;
}

void Command::CommandType(std::string textCommand)
{
	for (const auto& lookCommand : m_commandWords.LookWords)
	{
		if (lookCommand == textCommand)
		{
			//Perform Look Action
			Look look;

			look.CommandType(lookCommand);
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