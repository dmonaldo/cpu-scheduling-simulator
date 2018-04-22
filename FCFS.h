#ifndef FCFS_H
#define FCFS_H

#include "shceduler.h"

class FCFS : public schedular
{
public:
FCFS(string input) : scheduler(input);
virtual void runScheduler();
};
#endif
