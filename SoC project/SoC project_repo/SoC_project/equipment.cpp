#include "equipment.h"

string Equipment::getHead() const
{
    return head;
}

void Equipment::setHead(const string &value)
{
    head = value;
}

string Equipment::getChest() const
{
    return chest;
}

void Equipment::setChest(const string &value)
{
    chest = value;
}

string Equipment::getLegs() const
{
    return legs;
}

void Equipment::setLegs(const string &value)
{
    legs = value;
}

string Equipment::getSword() const
{
    return sword;
}

void Equipment::setSword(const string &value)
{
    sword = value;
}

Equipment::Equipment(const string &c_name,const string &head,const string &chest,const string &legs,const string &sword)
    :Character(c_name)
    ,head(head),chest(chest),legs(legs),sword(sword)
{

}
