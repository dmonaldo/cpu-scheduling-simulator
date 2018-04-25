//AUTHOR: Alex Runciman
//FILENAME: SRTF.h
//DESCRIPTION: A program to simulate the SRTF algorithm

#ifndef SRTF_H
#define SRTF_H

#include "scheduler.h"
#include <vector>
class SRTF: public virtual Scheduler
{
 public:
 SRTF(string input) : Scheduler(input){};
  ~SRTF(){};
  void runScheduler();
 protected:
  double avgRespQuery();
  double avgWaitQuery();
  double avgTurnaroundQuery();
  double cpuUseQuery();
 private:
  static const int MAX = 1000000;
};
#endif
