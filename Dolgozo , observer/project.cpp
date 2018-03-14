#include "project.h"
Project::Project(const string &modelName, int noWheels, const string &engineType)
    :modelName(modelName),noWheels(noWheels),engineType(engineType)
{

}

map<string,Project*> Project::Projectlist()
{
//    for(auto it : projects)
//    {
//        if(it.second!=nullptr)
//        {
//            cout<<"Projekt neve : "<<it.second->getModelName()<<endl;
//        }
//    }
    return projects;
}

map<string, int> Project::projectProperties()
{
    map<string,int> result;
    for(auto it : work)
    {
        result[it.first->getModelName()]++;
    }
    return result;
}
int Project::getNoWheels() const
{
    return noWheels;
}

string Project::getEngineType() const
{
    return engineType;
}

string Project::getModelName() const
{
    return modelName;
}
map<string,Project*> Project::projects={
    {"x",0}
};
