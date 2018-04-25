/*
  AUTHORS: Alex Runciman
  FILEFAME: FCFS.h
  DESCRIPTION: This class is designed to run a SRTF simulator and print the
                results for the average wait time, average response time, average
                turn around time, and the cpu usage.
*/

#ifndef SRTF_H
#define SRTF_H

#include "scheduler.h"
#include <vector>

class SRTF: public virtual Scheduler {
  public:
    SRTF(string input) : Scheduler(input){};
    ~SRTF(){};
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

  private:
    static const int MAX = 1000000;
};
#endif
