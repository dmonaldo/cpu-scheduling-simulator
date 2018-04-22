#ifndef FCFS_H
#define FCFS_H

#include "Scheduler.h"

class FCFS : public Scheduler
{
public:
FCFS(string input) : scheduler(input);
virtual void runScheduler();
};
#endif
