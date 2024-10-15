#pragma once
#include <string>
#include "CommandInterface.h"

class Player;
class Map;

struct CommandWords
{
    std::string MoveWords[4] = {"move", "go", "run", "walk"};
    std::string LookWords[4] = { "look", "see", "gander"};
};

class Movement : public CommandInterface
{
public:
    Movement(Map* a_Map, Player* a_Player);
    ~Movement() override;

    void CommandType(std::string a_Command) override;

private:

    CommandWords Commands;
    Map* MapLocations = nullptr;
    Player* PlayerCharacter = nullptr;

    bool bIsMoving;
    bool bIsLooking;
};
