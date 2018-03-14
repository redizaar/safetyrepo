#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include "character.h"
#include <iostream>
using namespace std;

class Equipment:public Character
{
    string head;
    string chest;
    string legs;
    string sword;
public:
    Equipment(const string &c_name,const string &head,const string &chest,const string &legs,const string &sword);
    string getHead() const;
    void setHead(const string &value);
    string getChest() const;
    void setChest(const string &value);
    string getLegs() const;
    void setLegs(const string &value);
    string getSword() const;
    void setSword(const string &value);
};

#endif // EQUIPMENT_H
