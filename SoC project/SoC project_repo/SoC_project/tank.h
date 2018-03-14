#ifndef TANK_H
#define TANK_H
#include "character.h"

class Tank:public Character
{
public:
    Tank(const string c_name,int type);
    virtual int b_attack(int power, int crit);
};

#endif // TANK_H
