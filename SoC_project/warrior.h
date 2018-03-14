#ifndef WARRIOR_H
#define WARRIOR_H
#include "Stats.h"

class Warrior:public Stats
{
public:
    Warrior(const string &c_name,int &c_type,int &c_lvl,int &c_xp,int &c_hp,int &c_power,float &c_crit,float &c_dodge);
};

#endif // WARRIOR_H
