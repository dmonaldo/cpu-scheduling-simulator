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
  // Declares a functin body so the pure vitrual fnction inherited to
  //properly handle wait time for FCFS
  double avgWaitQuery();
  //declres a functin body ot the pure vitrual fnction inherited to
  //properly handle response time for FCFS
  double avgRespQuery();
  //declres a functin body ot the pure vitrual fnction inherited to
  //properly handle turnaround time for FCFS
  double avgTurnaroundQuery();
  //declres a functin body ot the pure vitrual fnction inherited to
  //properly handle CPU usage for FCFS
  double cpuUseQuery();
};
#endif
