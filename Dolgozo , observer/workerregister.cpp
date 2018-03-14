#include "workerregister.h"

WorkerRegister::WorkerRegister(string name):name(name)
{

}

void WorkerRegister::addObserver(Dolgozo *obs)
{
    observers.push_back(obs);
}

void WorkerRegister::registerWorker(const Dolgozo &nw)
{
    cout<<nw.getName()<<" hozzaadva a dolgozokhoz"<<endl;
    for(auto it : observers)
        it->newWorker(nw);
}
