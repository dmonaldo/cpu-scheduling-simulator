// Abstract class for scheduler algorithms
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include <vector>

using namespace std

  struct processInfo{
  int pid;
  bool state;
  int arrival;
  int burst;
}

class Scheduler {
  public:
    Scheduler(string input);
    ~Scheduler(void);
    virtual void parseInputFile();
    virtual void runScheduler() = 0;
    const double avgTurnaroundQuery();
    const double avgWaitQuery();
    const double avgRespQuery();
    const double cpuUseQuery();
  
  protected:
    vector<processInfo> process;
    vector<int> waitTime;
    double avgWait;
    vector<int> respTime;
    double avgResp;
    vector<int> turnTime;
    double avgTurn;
    double cpuUsage;
    string inputFile;
    int pidCount;
    // struct {
    //   int pid;
    //   bool state;
    //   int arrival;
    //   int burst;
    // }
}
