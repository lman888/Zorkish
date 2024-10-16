#pragma once

//C++ Files
#include <string>

//Zorkish Files
#include "Command.h"

class Map;
class Player;

struct CommandWords
{
    std::string MoveWords[4] = {"move", "go", "run", "walk"};
    std::string LookWords[4] = { "look", "see", "gander"};
};

class Movement : public Command
{
public:
    Movement();
    Movement(Map* Map, Player* Player);
    ~Movement() override;

    void CommandType(std::string Command) override;

    void ChangeLocations(std::string a_MovementText);

private:
    CommandWords m_commands;
    Map* m_map = nullptr;
    Player* m_playerCharacter = nullptr;

    bool m_bIsMoving = false;
    bool m_bIsLooking = false;
};
