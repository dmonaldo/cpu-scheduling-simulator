/*
  AUTHORS: Alex Runciman
  FILENAME: FCFS.cpp
  DESCRIPTION: Implementation of functions declared in FCFS.h
*/

#include "FCFS.h"

// Run the FCFS scheduler
void FCFS::runScheduler() {
  parseInputFile();
  waitTime.push_back(0);
  for (int i = 0; i < pidCount; i++) {
    for (int j = 0; j < process[i].burst; j++) {
      printRunProcess(i+INC);
      timeCounter++;
    }
    waitTime.push_back(timeCounter);
    printCompleteProcess(i+INC);
  }
}

// Returns the average response time
double FCFS::avgRespQuery() {
  avgResp = avgWaitQuery();
  return avgResp;
}

// Returns the average wait time
double FCFS::avgWaitQuery() {
  avgWait = 0;
  for (int i = 0; i < pidCount; i++) {
    avgWait += waitTime[i] - process[i].arrival;
  }
  avgWait = avgWait/(pidCount);
  return avgWait;
}

// Returns the average turnaround time
double FCFS::avgTurnaroundQuery() {
  int tempBurst = 0;
  int tempTurn = 0;
  for (int i = 0; i < pidCount; i++) {
    tempBurst += process[i].burst;
    tempTurn = tempBurst - process[i].arrival;
    avgTurn += tempTurn;
  }
  avgTurn = avgTurn/(pidCount);
  return avgTurn;
}

// Returns the CPU usage in percentage form
double FCFS::cpuUseQuery() {
  double totBurst = 0;
  for (int i = 0; i < pidCount; i++) {
    totBurst += process[i].burst;
  }
  totBurst = (totBurst/timeCounter) * 100;
  return totBurst;
}
