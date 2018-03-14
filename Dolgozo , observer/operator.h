#ifndef OPERATOR_H
#define OPERATOR_H
#include "dolgozo.h"
#include "workereventinteface.h"

class Operator:public Dolgozo
{
    string work_area;
    int experience;
public:
    Operator(const string name, int age, int id,int salary,string work_area,int experience);
    virtual void welcoming() const;
    virtual void working_area() const;
    virtual string workType() const;
    virtual void newWorker(const Dolgozo &nw);

    string getWork_area() const;
    void setWork_area(const string &value);
    int getExperience() const;
    void setExperience(int value);
};

#endif // OPERATOR_H
