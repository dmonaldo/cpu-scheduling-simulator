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

class RR : public Scheduler {
  public:
    RR(string input, int quantum);
    void runScheduler();

  protected:
    // Returns the average response time
    double avgRespQuery();

    // Returns the average wait time
    double avgWaitQuery();

    // Returns the average turnaround time
    double avgTurnaroundQuery();

    // Returns the CPU usage in percentage form
    double cpuUseQuery();

    int timeQuantum;
};
#endif
