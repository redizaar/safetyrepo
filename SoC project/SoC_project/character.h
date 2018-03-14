#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
using namespace std;
class Character
{
protected:
    string username;
    string c_name;
    int c_type; //1 - warrior  2 - mage 3 - tank  4 - priest
public:
    Character(const string &c_name);
    Character(const string &username,const string &c_name,int &c_type);
    string getC_name() const;
    void setC_name(const string &value);
    string getUsername() const;
    void setUsername(const string &value);
};

#endif // CHARACTER_H
