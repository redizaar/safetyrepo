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

Character::Character(const string &username, const string &c_name, int &c_type):username(username),c_name(c_name),c_type(c_type)
{
}
Character::Character(const string &c_name):c_name(c_name)
{

}
