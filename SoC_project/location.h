#ifndef LOCATION_H
#define LOCATION_H
#include "character.h"
#include <map>
#include <iostream>
using namespace std;
class Location
{
    map<string,int> megyek;
    Location(){}
public:
    static Location &getInstance()
    {
        static Location instance;
        return instance;
    }
    map<string,int> locationLoad();
};

#endif // LOCATION_H
