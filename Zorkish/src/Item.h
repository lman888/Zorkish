#pragma once
#include <string>


class Item
{
public:
    Item();
    ~Item();

    std::string ShowDescription() const;
    
private:
    std::string description;
    
};
