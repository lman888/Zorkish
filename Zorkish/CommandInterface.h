#pragma once
#include <string>

class CommandInterface
{
public:
	CommandInterface() = default;
	virtual ~CommandInterface() = default;
	
	virtual void CommandType(std::string a_Command) = 0;
};