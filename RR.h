/*
  AUTHORS: Dante Monaldo
  FILEFAME: RR.h
  DESCRIPTION: This class is designed to run a RR simulator and print the
                results for the average wait time, average response time, average
                turn around time, and the cpu usage.
*/

#ifndef RR_H
#define RR_H

#include "scheduler.h"

using namespace std;

class RR : public Scheduler {
  public:
    RR(string input, int quantum);
    void runScheduler();

  protected:
    double avgRespQuery();
    double avgWaitQuery();
    double avgTurnaroundQuery();
    double cpuUseQuery();
    int timeQuantum;
};
#endif
