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
    virtual void runScheduler() = 0; //bool?
    void printResults();
    
    const double cpuUseQuery();
  
  protected:
    virtual double avgTurnaroundQuery() = 0;
    virtual double avgWaitQuery() = 0;
    virtual double avgRespQuery() = 0;
    void printCurrProcess();
    vector<processInfo> process;
    vector<int> waitTime;
    double avgWait;
    //vector<int> respTime;
    double avgResp;
    vector<int> turnTime;
    double avgTurn;
    double cpuUsage;
    string inputFile;
    int pidCount;
    int timeCounter;
    // struct {
    //   int pid;
    //   bool state;
    //   int arrival;
    //   int burst;
    // }
}
