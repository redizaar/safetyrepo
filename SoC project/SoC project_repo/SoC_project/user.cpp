#include "user.h"

string User::getUsername() const
{
    return username;
}

void User::setUsername(const string &value)
{
    username = value;
}

string User::getPassword() const
{
    return password;
}

void User::setPassword(const string &value)
{
    password = value;
}

User::User(const string &username, const string &password):username(username),password(password)
{
}
User::User()
{

}
