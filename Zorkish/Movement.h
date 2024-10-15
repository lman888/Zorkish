#pragma once
#include <string>
#include "CommandInterface.h"

class Map;
class Player;

struct CommandWords
{
    std::string MoveWords[4] = {"move", "go", "run", "walk"};
    std::string LookWords[4] = { "look", "see", "gander"};
};

class Movement : public CommandInterface
{
public:
    Movement(Map* Map, Player* Player);
    ~Movement() override;

    void CommandType(std::string Command) override;

private:
    CommandWords m_commands;
    Map* m_map = nullptr;
    Player* m_playerCharacter = nullptr;

    bool m_bIsMoving = false;
    bool m_bIsLooking = false;
};
