#include "programmer.h"

string Programmer::getWork_area() const
{
    return work_area;
}

void Programmer::setWork_area(const string &value)
{
    work_area = value;
}

int Programmer::getExperience() const
{
    return experience;
}

void Programmer::setExperience(int value)
{
    experience = value;
}

string Programmer::getLanguage() const
{
    return language;
}

void Programmer::setLanguage(const string &value)
{
    language = value;
}

Programmer::Programmer(const string name, int age, int id,int salary,string work_area,int experience,string language)
    :Dolgozo(name,age,id,salary),
      work_area(work_area),experience(experience),language(language)
{

}

void Programmer::welcoming() const
{
    cout<<"Hi , my name is : "<<getName()<<endl;
    cout<<"I'm "<<getAge()<<" years old."<<endl;
    cout<<"I'm a programmer"<<endl;
}

void Programmer::working_area() const
{
    cout<<getName()<<"'s work area is :  "<<getWork_area()<<endl;
    cout<<"He has "<<getExperience()<<" years of experience"<<endl;
    cout<<"He's main programming language is : "<<getLanguage()<<endl;
}

string Programmer::workType() const
{
    return "Programozo";
}

void Programmer::newWorker(const Dolgozo &nw)
{
    if(nw.getId()<100)
        cout<<getName()<<" udvozol a programozok kozott"<<endl;
}
