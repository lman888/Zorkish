#include "Item.h"

Item::Item()
{
    description = "This is a sacred item that may be useful on your quest!";
}

Item::~Item()
{

}

std::string Item::ShowDescription() const
{
    return description;
}