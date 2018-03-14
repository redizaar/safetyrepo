#ifndef PROJECT_H
#define PROJECT_H
#include <iostream>
#include "dolgozo.h"
#include <map>
#include <list>
using namespace std;
class Project
{
    int unique_id;
protected:
    static map<string,Project*> projects;
    map<Project*,list<Dolgozo*>> work;
    string modelName;
    int noWheels;
    string engineType;
public:
    Project(const string &modelName,int noWheels,const string &engineType);
    virtual void addProject()=0;
    virtual void listProjects()=0;//gyerek osztályokban
    virtual bool addWorkerToProject(Dolgozo *worker)=0;
    virtual int listWorkers()=0;
    virtual int getWorkersNum() const=0;
    static map<string,Project*> Projectlist();
    virtual map<string,int> projectProperties()=0;
    string getModelName() const;
    int getNoWheels() const;
    string getEngineType() const;
};

#endif // PROJECT_H
