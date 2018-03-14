#ifndef STATS_H
#define STATS_H
#include "character.h"

class Stats:public Character
{
protected:
    int c_type;
    int c_lvl;
    int c_xp;
    int c_hp;
    int c_power;
    float c_crit;
    float c_dodge;
public:
    Stats(const string &c_name,int &c_type,int &c_lvl,int &c_xp,int &c_hp,int &c_power,float &c_crit,float &c_dodge);
    int getC_lvl() const;
    void setC_lvl(int value);
    int getC_xp() const;
    void setC_xp(int value);
    int getC_hp() const;
    void setC_hp(int value);
    int getC_power() const;
    void setC_power(int value);
    float getC_crit() const;
    void setC_crit(float value);
    float getC_dodge() const;
    void setC_dodge(float value);
    int getC_type() const;
    void setC_type(int value);
};

#endif // STATS_H
