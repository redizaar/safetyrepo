#ifndef PROGRAMMER_H
#define PROGRAMMER_H
#include "dolgozo.h"
#include "workereventinteface.h"
class Programmer:public Dolgozo
{
    string work_area;
    int experience;
    string language;
public:
    Programmer(const string name, int age, int id,int salary,string work_area,int experience,string language);
    virtual void welcoming() const;
    virtual void working_area() const;
    virtual string workType() const;
    virtual void newWorker(const Dolgozo &nw);

    string getWork_area() const;
    void setWork_area(const string &value);
    int getExperience() const;
    void setExperience(int value);
    string getLanguage() const;
    void setLanguage(const string &value);
};

#endif // PROGRAMMER_H
