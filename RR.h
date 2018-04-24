#ifndef FCFS_H
#define FCFS_H

#include "scheduler.h"

using namespace std;

class RR : public Scheduler {
  public:
    RR(string input, int quantum);
    // ~RR(void);
    void runScheduler();

  protected:
    double avgRespQuery();
    double avgWaitQuery();
    double avgTurnaroundQuery();
    int timeQuantum;
};
#endif
