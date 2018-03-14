#ifndef DOLGOZO_H
#define DOLGOZO_H
#include <iostream>
using namespace std;

class Dolgozo
{
    string name;
    int age;
    int id;
    int salary;
public:
    Dolgozo(const string name, int age, int id,int salary);
    virtual void newWorker(const Dolgozo &nw)=0;
    virtual void welcoming() const=0;
    virtual void working_area() const=0;
    virtual string workType() const=0;
    string getName() const;
    void setName(const string &value);
    int getAge() const;
    void setAge(int value);
    int getSalary() const;
    void setSalary(int value);
    int getId() const;
    void setId(int value);
};

#endif // DOLGOZO_H
