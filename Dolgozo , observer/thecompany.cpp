#include "thecompany.h"

TheCompany::TheCompany()
{
}

int TheCompany::id=1;

string TheCompany::getLocation() const
{
    return location;
}

void TheCompany::addDolgozo(Dolgozo *worker)
{
    if(dynamic_cast<Programmer*>(worker))
    {
        programmers[id]=worker;
    }
    else if(dynamic_cast<Operator*>(worker))
    {
        operators[id]=worker;
    }
    id++;
}

void TheCompany::listDolgozok() const
{
    for(auto it : programmers)
    {
        cout<<"Programozok:"<<endl;
        cout<<"azonosito : "<<it.first<<" "<<it.second->getName()<<endl;
    }
    for(auto it : operators)
    {
        cout<<"Operatorok:"<<endl;
        cout<<"azonosito :" <<it.first<<" "<<it.second->getName()<<endl;
    }
}
void TheCompany::initalizeCompany()
{
    this->name="Continental";
    this->location="Veszprem Hazgyar ut 6-8";
    this->owner="Toth Patrik";
}
