#ifndef MAGE_H
#define MAGE_H
#include "character.h"

class Mage:public Character
{
public:
    Mage(const string c_name,int type);
    virtual int b_attack(int power, int crit);
};

#endif // MAGE_H
