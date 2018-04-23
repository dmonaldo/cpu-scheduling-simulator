#ifndef SRTF_H
#define SRTF_H

#include "scheduler.h"

class SRTF: public Scheduler
{
public: 
SRTF(string input) : Schedluer(input);
virtual void run scheduler();
protected:
virtual double avgRespQuery();
virtual double avgWaitQuery();
virtual double avgTurnaroundQuery();

};
#endif
