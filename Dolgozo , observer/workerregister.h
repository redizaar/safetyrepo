#ifndef WORKERREGISTER_H
#define WORKERREGISTER_H
#include "workereventinteface.h"
#include <list>
#include "dolgozo.h"
class WorkerRegister
{
    list<Dolgozo*> observers;
    string name;
public:
    WorkerRegister(string name);
    void addObserver(Dolgozo* obs);
    void registerWorker(const Dolgozo &nw);
};

#endif // WORKERREGISTER_H
