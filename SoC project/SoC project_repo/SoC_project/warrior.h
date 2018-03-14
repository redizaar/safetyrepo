#ifndef WARRIOR_H
#define WARRIOR_H
#include "character.h"

class Warrior:public Character
{
public:
    Warrior(const string c_name,int type);
    virtual int b_attack(int power, int crit);
};

#endif // WARRIOR_H
