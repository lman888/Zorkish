#pragma once
#include <string>

class CommandInterface
{
public:
	virtual void CommandType(std::string a_Command) = 0;
};