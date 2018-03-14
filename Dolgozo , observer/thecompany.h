#ifndef THECOMPANY_H
#define THECOMPANY_H
#include <iostream>
#include "dolgozo.h"
#include "programmer.h"
#include "operator.h"
#include <map>
using namespace std;

class TheCompany
{
    TheCompany();
    string name;
    string location;
    string owner;
    map<int,Dolgozo*> programmers;
    map<int,Dolgozo*> operators;
    static int id;
public:
    static TheCompany &getInstance()
    {
        static TheCompany instance;
        return instance;
    }
    void initalizeCompany();
    string getLocation() const;
    void addDolgozo(Dolgozo *worker);
    void listDolgozok() const;
};

#endif // THECOMPANY_H
