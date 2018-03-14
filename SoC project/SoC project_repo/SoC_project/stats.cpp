#include "stats.h"

float Stats::getC_crit() const
{
    return c_crit;
}

void Stats::setC_crit(float value)
{
    c_crit = value;
}

float Stats::getC_dodge() const
{
    return c_dodge;
}

void Stats::setC_dodge(float value)
{
    c_dodge = value;
}

int Stats::getC_type() const
{
    return c_type;
}

void Stats::setC_type(int value)
{
    c_type = value;
}
string Stats::getC_name() const
{
    return c_name;
}

void Stats::setC_name(const string &value)
{
    c_name = value;
}

Stats::Stats(const string &c_name, const int &c_type, const int &c_lvl,const int &c_xp,const int &c_hp,const int &c_power,const float &c_crit,const float &c_dodge)
    :c_name(c_name),c_type(c_type),c_lvl(c_lvl),c_xp(c_xp),c_hp(c_hp),c_power(c_power),c_crit(c_crit),c_dodge(c_dodge)
{
}
int Stats::getC_lvl() const
{
    return c_lvl;
}

void Stats::setC_lvl(int value)
{
    c_lvl = value;
}

int Stats::getC_xp() const
{
    return c_xp;
}

void Stats::setC_xp(int value)
{
    c_xp = value;
}

int Stats::getC_hp() const
{
    return c_hp;
}

void Stats::setC_hp(int value)
{
    c_hp = value;
}

int Stats::getC_power() const
{
    return c_power;
}

void Stats::setC_power(int value)
{
    c_power = value;
}
