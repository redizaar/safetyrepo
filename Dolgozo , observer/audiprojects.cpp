#include "audiprojects.h"
AudiProjects::AudiProjects(const string &modelName, int noWheels, const string &engineType)
    :Project(modelName,noWheels,engineType)
{

}
void AudiProjects::addProject()
{
    projects[this->modelName]=this;
}

void AudiProjects::listProjects()
{
    for(auto it : projects)
    {
        if(dynamic_cast<AudiProjects*>(it.second))
        {
            cout<<it.second->getModelName()<<endl;
            cout<<it.second->getEngineType()<<endl;
        }
    }
}

bool AudiProjects::addWorkerToProject(Dolgozo *worker)
{
    bool isAdded=false;
    for(auto it : projects)
    {
        if(dynamic_cast<AudiProjects*>(it.second))
            //ha audiProject egyáltalán
        {
            if(it.second->getModelName()==this->getModelName())
                //ha az objektum amire meglett hívva egyáltalán hozzávan-e adva a projektekhez
            {
                work[it.second].push_back(worker);
                cout<<worker->getName()<<" "<<worker->workType()<<" hozzaadva a(z) "<<it.second->getModelName()<<" projekthez"<<endl;
                isAdded=true;
                return true;
            }
        }
    }
    if(!isAdded)
    {
        cout<<"Ez az Audi projekt meg nem lett hozzaadva az elo Projektekhez "<<endl;
    }
    return false;
}

map<string, int> AudiProjects::projectProperties()
{
    map<string,int> properites;
    for(auto it : work)
    {
        if(dynamic_cast<AudiProjects*>(it.first))
        {
            for(auto it2 : it.second)
            {
                properites[it.first->getModelName()]++;
            }
        }
    }
    return properites;
}

int AudiProjects::listWorkers()
{
    bool hasWorker=false;
    int workersNum=0;
    for(auto it : work)
    {
        if(dynamic_cast<AudiProjects*>(it.first) && it.first->getModelName()==this->getModelName())
        {
            for(auto it2 : it.second)
            {
                hasWorker=true;
                cout<<"Nev: "<<it2->getName()<<" ";
                cout<<" Munkakor: "<<it2->workType()<<endl;
                workersNum++;
            }
        }
    }
    if(!hasWorker)
    {
        cout<<"Ehhez a projecthez meg nem lett hozzadva dolgozo!"<<endl;
    }
    return workersNum;
}

int AudiProjects::getWorkersNum() const
{
    int wrkrsNum=0;
    for(auto it : work)
    {
        if(dynamic_cast<AudiProjects*>(it.first) && it.first->getModelName()==this->getModelName())
        {
            for(auto it2 : it.second)
            {
                wrkrsNum++;
            }
        }
    }
    return wrkrsNum;
}
