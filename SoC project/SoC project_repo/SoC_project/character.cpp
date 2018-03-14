#include "character.h"
string Character::getC_name() const
{
    return c_name;
}

void Character::setC_name(const string &value)
{
    c_name = value;
}

string Character::getUsername() const
{
    return username;
}

void Character::setUsername(const string &value)
{
    username = value;
}

int Character::getC_type() const
{
    return c_type;
}

void Character::setC_type(int value)
{
    c_type = value;
}

int Character::b_attack(int power, int cirt)
{
    return 0;
}

Character::Character(const string &username, const string &c_name, int &c_type):username(username),c_name(c_name),c_type(c_type)
{
}
Character::Character(const string username, int type):username(username),c_type(type)
{

}
