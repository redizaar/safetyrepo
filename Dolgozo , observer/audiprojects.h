#ifndef AUDIPROJECTS_H
#define AUDIPROJECTS_H
#include "project.h"

class AudiProjects:public Project
{
public:
    AudiProjects(const string &modelName,int noWheels,const string &engineType);
    void addProject();
    void listProjects();
    bool addWorkerToProject(Dolgozo *worker);
    map<string,int> projectProperties();
    int listWorkers();
    int getWorkersNum() const;
};

#endif // AUDIPROJECTS_H
