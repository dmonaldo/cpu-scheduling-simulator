// Abstract class for scheduler algorithms
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

struct processInfo {
  int pid;
  bool state;
  int arrival;
  int burst;
  int completionTime;
  int timeRemaining;
};

class Scheduler {
  public:
    Scheduler(string input);
    ~Scheduler(void) {};
    void parseInputFile();
    void printProcessResult();
    virtual void runScheduler() = 0;

  protected:
    virtual double avgTurnaroundQuery() = 0;
    virtual double avgWaitQuery() = 0;
    virtual double avgRespQuery() = 0;
    virtual double cpuUseQuery() = 0;

    void printRunProcess(int numPro);
    void printCompleteProcess(int numPro);

    vector<processInfo> process;
    vector<int> waitTime;
    vector<int> turnTime;

    double avgWait;
    double avgResp;
    double avgTurn;
    double cpuUsage;

    string inputFile;

    int pidCount;
    int timeCounter;
    int burstCounter;

    static const int INC = 1;
    static const double PERCENT = 100;
};

#endif
