#ifndef PRIEST_H
#define PRIEST_H
#include "character.h"

class Priest:public Character
{
public:
    Priest(const string c_name,int type);
    virtual int b_attack(int power, int crit);
};

#endif // PRIEST_H
