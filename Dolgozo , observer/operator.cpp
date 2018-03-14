#include "operator.h"

string Operator::getWork_area() const
{
    return work_area;
}

void Operator::setWork_area(const string &value)
{
    work_area = value;
}

int Operator::getExperience() const
{
    return experience;
}

void Operator::setExperience(int value)
{
    experience = value;
}

Operator::Operator(const string name, int age, int id, int salary, string work_area, int experience)
    :Dolgozo(name,age,id,salary),
      work_area(work_area),experience(experience)
{

}

void Operator::welcoming() const
{
    cout<<"Hi , my name is : "<<getName()<<endl;
    cout<<"I'm "<<getAge()<<" years old."<<endl;
    cout<<"I'm an operator"<<endl;
}

void Operator::working_area() const
{
    cout<<getName()<<"'s work area is :  "<<getWork_area()<<endl;
    cout<<"He has "<<getExperience()<<" years of experience"<<endl;
}

string Operator::workType() const
{
    return "Operator";
}

void Operator::newWorker(const Dolgozo &nw)
{
    if(nw.getId()>100)
        cout<<getName()<<" udvozol a szalagmunkasoknal"<<endl;
}
