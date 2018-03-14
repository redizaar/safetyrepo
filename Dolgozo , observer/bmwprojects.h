#ifndef BMWPROJECTS_H
#define BMWPROJECTS_H
#include "project.h"

class BmwProjects:public Project
{
public:
    BmwProjects(const string &modelName,int noWheels,const string &engineType);
    void addProject();
    void listProjects();
    bool addWorkerToProject(Dolgozo *worker);
    map<string,int> projectProperties();
    int listWorkers();
    int getWorkersNum() const;
};

#endif // BMWPROJECTS_H
