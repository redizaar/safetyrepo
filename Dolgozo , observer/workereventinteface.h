#ifndef WORKEREVENTINTEFACE_H
#define WORKEREVENTINTEFACE_H
#include "dolgozo.h"

class workerEventInteface
{
public:
    virtual void newWorker(const Dolgozo &nw)=0;
};

#endif // WORKEREVENTINTEFACE_H
