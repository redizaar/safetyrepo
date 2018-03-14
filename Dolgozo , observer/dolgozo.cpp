
#include "dolgozo.h"

string Dolgozo::getName() const
{
    return name;
}

void Dolgozo::setName(const string &value)
{
    name = value;
}

int Dolgozo::getAge() const
{
    return age;
}

void Dolgozo::setAge(int value)
{
    age = value;
}

int Dolgozo::getSalary() const
{
    return salary;
}

void Dolgozo::setSalary(int value)
{
    salary = value;
}

int Dolgozo::getId() const
{
    return id;
}

void Dolgozo::setId(int value)
{
    id = value;
}

Dolgozo::Dolgozo(const string name, int age, int id, int salary):name(name),age(age),id(id),salary(salary)
{

}
