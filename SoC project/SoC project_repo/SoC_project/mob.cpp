#include "mob.h"

string Mob::name() const
{
    return m_name;
}

void Mob::setName(const string &name)
{
    m_name = name;
}
int Mob::dodge() const
{
    return m_dodge;
}
void Mob::setDodge(int dodge)
{
    m_dodge = dodge;
}

int Mob::getXp() const
{
    return xp;
}

void Mob::setXp(int value)
{
    xp = value;
}

float Mob::getHp() const
{
    return m_hp;
}

void Mob::setHp(float hp)
{
    m_hp = hp;
}

float Mob::getAttack() const
{
    return m_attack;
}

void Mob::setAttack(float attack)
{
    m_attack = attack;
}

float Mob::getCirt() const
{
    return m_cirt;
}

void Mob::setCirt(float cirt)
{
    m_cirt = cirt;
}

int Mob::getLvl() const
{
    return m_lvl;
}

void Mob::setLvl(int lvl)
{
    m_lvl = lvl;
}

float Mob::getDodge() const
{
    return m_dodge;
}

string Mob::getName() const
{
    return m_name;
}

Mob::Mob(const string &m_location,const string &m_name, int &m_hp, int &m_attack,int &m_dodge)
    :m_location(m_location),m_name(m_name),m_hp(m_hp),m_attack(m_attack),m_dodge(m_dodge)
{
}

map<string, int> Mob::mobLoad()
{
    monsters.insert(pair<string,int>("Boneless imp",1));
    monsters.insert(pair<string,int>("P!=NP",3));
    monsters.insert(pair<string,int>("Fel Warrior",5));
    monsters.insert(pair<string,int>("Small sting Scorpion",5));
    monsters.insert(pair<string,int>("Challanged Warrior",9));
    monsters.insert(pair<string,int>("Blood-hungry Bat",9));
    monsters.insert(pair<string,int>("Frozen Spider Queen",13));
    monsters.insert(pair<string,int>("Sindragosa",13));
    return monsters;
}
