#ifndef MOB_H
#define MOB_H
#include <iostream>
#include "location.h"
using namespace std;
class Mob
{
    string m_location;
    string m_name;
    int m_lvl;
    float m_hp;
    int xp;
    float m_attack;
    float m_dodge=8;
    float m_cirt=12;
    map<string,int> monsters;
public:
    Mob(){}
    Mob(const string &m_location,const string &m_name, int &m_hp, int &m_attack,int &m_dodge);
    map<string,int> mobLoad();
    string name() const;
    void setName(const string &name);
    int dodge() const;
    void setDodge(int dodge);
    int getXp() const;
    void setXp(int value);
    float getHp() const;
    void setHp(float hp);
    float getAttack() const;
    void setAttack(float attack);
    float getCirt() const;
    void setCirt(float cirt);
    int getLvl() const;
    void setLvl(int lvl);
    float getDodge() const;
    string getName() const;
};

#endif // MOB_H
