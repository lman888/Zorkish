#pragma once

#include "Command.h"

class Look : public Command
{
public:
	Look();
	virtual void CommandType(std::string textCommand) override;

};