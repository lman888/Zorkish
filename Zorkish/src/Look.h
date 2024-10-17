#pragma once

#include "Command.h"

class ZorkishHelper;

class Look
{
public:
	Look();
	void LookAroundLocation(std::string textCommand, ZorkishHelper* zorkishHelper);

};