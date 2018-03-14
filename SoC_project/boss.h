#ifndef BOSS_H
#define BOSS_H
#include "mob.h"

class Boss:public Mob
{
public:
    Boss(const string &m_location,const string &m_name, int &m_hp, int &m_attack, int &m_dodge);
};

#endif // BOSS_H
