#ifndef SRTF_H
#define SRTF_H

#include "scheduler.h"

class SRTF: public Scheduler
{
public: 
SRTF(string input) : Schedluer(input);
~SRTF(){};
void runScheduler();
protected:
double avgRespQuery();
double avgWaitQuery();
double avgTurnaroundQuery();
};
#endif
