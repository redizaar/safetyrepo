#ifndef STATS_H
#define STATS_H
#include "character.h"

class Stats
{
    string c_name;
    int c_type;
    int c_lvl;
    int c_xp;
    int c_hp;
    int c_power;
    float c_crit;
    float c_dodge;
public:
    Stats(const string &c_name, const int &c_type, const int &c_lvl,const int &c_xp,const int &c_hp,const int &c_power,const float &c_crit,const float &c_dodge);
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
    string getC_name() const;
    void setC_name(const string &value);
};

#endif // STATS_H
