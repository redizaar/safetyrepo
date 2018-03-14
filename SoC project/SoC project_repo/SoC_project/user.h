#ifndef USER_H
#define USER_H
#include <iostream>
#include <list>
using namespace std;

class User
{
    string username;
    string password;
public:
    User();
    User(const string &username, const string &password);
    string getUsername() const;
    void setUsername(const string &value);
    string getPassword() const;
    void setPassword(const string &value);
};

#endif // USER_H
