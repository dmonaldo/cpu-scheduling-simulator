#ifndef FCFS_H
#define FCFS_H

#include "scheduler.h"

class RR : public Scheduler
{
  public:
    RR(string input);
    void runScheduler();

  protected:
    double avgRespQuery();
    double avgWaitQuery();
    double avgTurnaroundQuery();
};
#endif
