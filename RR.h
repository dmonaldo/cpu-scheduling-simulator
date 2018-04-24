#ifndef RR_H
#define RR_H

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
    double cpuUsageQuery();
    int timeQuantum;
};
#endif
