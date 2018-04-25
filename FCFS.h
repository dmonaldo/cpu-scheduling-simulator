/*
  AUTHORS: Alex Runciman
  FILEFAME: FCFS.h
  DESCRIPTION: This class is designed to run a FCFS simulator and print the
                results for the average wait time, average response time, average
                turn around time, and the cpu usage.
*/

#ifndef FCFS_H
#define FCFS_H

#include "scheduler.h"

using namespace std;

class FCFS : public virtual Scheduler {
  public:
    // Constructor
    // Uses the parent Scheduler constsructor to initalize all appropriate values
    FCFS(string input):Scheduler(input){};

    // Declares a function body for the pure virtual function inherited
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
};
#endif
