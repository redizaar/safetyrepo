#include <iostream>
#include <thread>
#include <vector>
#include <ctime>
#include <mutex>
#include "dolgozo.h"
#include "programmer.h"
#include "workerregister.h"
#include "operator.h"
#include "thecompany.h"
#include "project.h"
#include "audiprojects.h"
#include "bmwprojects.h"
using namespace std;
void welcoming(Dolgozo* obj)
{
    obj->welcoming();
}
void work_area(Dolgozo* obj)
{
    obj->working_area();
}
void visualization(map<string,Project*> projects,map<string,Project*>::iterator)
{
    cout<<"A project idoben valo elkeszulesenek eselye: "<<endl;
    srand(time(0));
    for(auto it : projects)
    {
        int chances = rand() % 10+1;
        if(it.second!=0)
        {
            cout<<"\t";
            if(it.second->getWorkersNum()%2==0)
            {
                if(chances==8)
                    chances++;
                else if(chances==10)
                    chances--;
                else if(chances==9)
                {
                }
                else
                   chances++;
           }
           else if(it.second->getWorkersNum()==0)
           {
              chances=0;
           }
           cout<<chances*10<<" %"<<endl;
           for(int i=0;i<1;i++)
           {
               cout<<"|";
               for(int j=0;j<10;j++)
               {
                   if(chances>0)
                   {
                        cout<<"*|";
                   }
                   else
                   {
                        cout<<" |";
                   }
                   chances--;
               }
             cout<<endl;
          }
      }
   }
}
void estimatedWorkTime(vector<pair<Project*,int>> startedProjects)
{
    for(auto it : startedProjects)
    {
        cout<<"Estimated worktime for : "<<it.first->getModelName()<<endl;
        cout<<"Based on a very scientific alogithm"<<endl;
        int workerNum=it.second;
        if(workerNum>1)
        {
            cout<<"Calculating..."<<endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            srand(time(0));
            int days=rand()%75+1;
            int hours=rand()%23+1;
            int minutes=rand()%59+1;
            if(workerNum%2==0)
            {
                cout<<"The estimated worktime is : "<<days<<" days , "<<hours<<" hours ,"<<minutes<<" minutes "<<endl;
                cout<<"-- According to these estimations which are super accurate --"<<endl;
                cout<<"This project's will be completed on : ";
            }
            else
            {
                days+=rand()%15+5;
                cout<<"The estimated worktime is : "<<days<<" days , "<<hours<<" hours ,"<<minutes<<" minutes "<<endl;
                cout<<"-- Note: according to statistics it is prefered to work in groups which are even --"<<endl;
                cout<<"-- it can the teams workflow --"<<endl;
                cout<<"This project's will be completed on : ";
            }
            typedef std::chrono::system_clock Clock;
            auto now = Clock::now();
            time_t now_c = Clock::to_time_t(now);
            struct tm *parts = localtime(&now_c);

            int months=0;
            while(days>=20)
            {
                months++;
                days-=20;
            }
            if(parts->tm_mday+days>31)
            {
                months++;
                days=days-31;
            }
            cout << 1900 + parts->tm_year<<".";
            cout << 1    + months + parts->tm_mon<<".";
            cout << days + parts->tm_mday  << endl;

        }
        else
        {
            this_thread::sleep_for(chrono::milliseconds(1500));
            cout<<endl;
            cout<<"### Warning ###"<<endl;
            cout<<"Project can't be started with only one person added to it!"<<endl;
            cout<<"Project manager warned!"<<endl;
            //todo observer
        }
        cout<<endl;
    }
}
void workingOnProjects()
{
    vector<pair<Project*,int>> projectStarted;
    map<string,Project*> projects=Project::Projectlist();
    for(auto it : projects)
    {
        if(it.second!=nullptr)
        {
            cout<<"Project name: "<<it.first<<endl;
            cout<<"\tWorkers added: "<<endl;
            int workersNum=it.second->listWorkers();
            if(workersNum!=0)
            {
                projectStarted.push_back(make_pair(it.second,workersNum));
                cout<<"Project started , with "<<workersNum<<" workers!"<<endl;
            }
            else
            {
                cout<<"So, "<<it.first<<" named project can't be started with 0 workers added to it!"<<endl;
            }
        }
        cout<<endl;
    }
    estimatedWorkTime(projectStarted);
}
int main()
{
    Programmer Pista("Pista",25,7,350000,"development",3,"c++");
    Operator Feri("Ferenc",30,101,120000,"assemblying",10);
    welcoming(&Pista);
    work_area(&Pista);

    welcoming(&Feri);
    work_area(&Feri);

    WorkerRegister obj("OrbanViktor");

    Programmer Warren("Warren Buffet",60,78,880000,"development",35,"c++");
    Operator NagyArpi("Nagy Arapd",44,150,180000,"assemblying",70);

    obj.addObserver(&Pista);
    obj.addObserver(&Feri);


    obj.registerWorker(Warren);
    obj.registerWorker(NagyArpi);

    TheCompany::getInstance().initalizeCompany();
    TheCompany::getInstance().addDolgozo(&Warren);
    TheCompany::getInstance().addDolgozo(&Pista);
    TheCompany::getInstance().addDolgozo(&Feri);

    TheCompany::getInstance().listDolgozok();

    AudiProjects i8("A2018_i8_1337",4,"Nagyon Gyors");

    BmwProjects M5("BMW2015_M5_4762",4,"Bunozo kedvenc");
    BmwProjects M6("BMW2011_M6_4587",4,"Uj gazdag kedvenc");


    i8.addProject();
    M5.addProject();
    M6.addProject();

    //a statikus map alapértékadásánál null-al töltöttem fel
    //kiirásnál rá kell szürni hogy nem-e null amit ki akarunk irni
    map<string,Project*> projects=Project::Projectlist();
    for(auto it : projects)
    {
        if(it.second!=nullptr)
        {
            cout<<"Projekt neve : "<<it.second->getModelName()<<endl;
        }
    }


    M5.listProjects();

    BmwProjects M7("BMW2012_M7_4712",4,"Vin Diesel kedvence");

    M7.addWorkerToProject(&Warren); // meg nem .addProject()-eltünk

    M5.addWorkerToProject(&Warren);

    i8.addWorkerToProject(&Feri);
    i8.addWorkerToProject(&Pista);

    M6.addWorkerToProject(&Pista);

    map<string,int> p_properites=i8.projectProperties();

    for(auto it : p_properites)
    {
        cout<<"Project neve: "<<it.first<<" ,projecten dolgozok szama: "<<it.second<<endl;
    }

    i8.listWorkers();

    cout<<endl;
    cout<<"Starting projects "<<endl;
    //thread calcWorkTime(workingOnProjects);

    //calcWorkTime.join();
    return 0;
}
