#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <time.h>
using namespace std;
class Character
{
    string username;
    string c_name;
    int c_type; //1 - warrior  2 - mage 3 - tank  4 - priest
public:
    Character(const string &username,const string &c_name,int &c_type);
    Character(const string username,int type);
    string getC_name() const;
    void setC_name(const string &value);
    string getUsername() const;
    void setUsername(const string &value);
    int getC_type() const;
    void setC_type(int value);
    virtual int b_attack(int power, int cirt);


};
#endif // CHARACTER_H
