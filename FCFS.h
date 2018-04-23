#ifndef FCFS_H
#define FCFS_H

#include "scheduler.h"

class FCFS : public Scheduler
{
  public:
    FCFS(string input) : Scheduler(input);
    virtual void runScheduler();
};
#endif
