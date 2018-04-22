// Abstract class for scheduler algorithms
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include <vector>

using namespace std

  struct{
  int pid;
  bool state;
  int arrival;
  int burst;
}

class Scheduler {
  public:
    Scheduler(void);
    ~Scheduler(void);
    virtual void parseInputFile() = 0;
    virtual void runScheduler() = 0;
    const double avgTurnaroundQuery();
    const double avgWaitQuery();
    const double avgRespQuery();
    const double cpuUseQuery();
  
  protected:
    vector<int> waitTime;
    double avgWait;
    vector<int> respTime;
    double avgResp;
    vector<int> turnTime;
    double avgTurn;
    double cupUsage;
  
    // struct {
    //   int pid;
    //   bool state;
    //   int arrival;
    //   int burst;
    // }
}
