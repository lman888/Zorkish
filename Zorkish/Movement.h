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
    ~Movement() = default;

    void ProcessCommand(std::string a_Command) override;

private:

    CommandWords Commands;
    Map* MapLocations;
    Player* PlayerCharacter;

    bool bIsMoving;
    bool bIsLooking;
};
