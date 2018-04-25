/*
  AUTHORS: Alex Runciman
  FILENAME: SRTF.cpp
  DESCRIPTION: Implementation of functions declared in SRTF.h
*/

#include "SRTF.h"

// Run the SRTF scheduler
void SRTF::runScheduler() {
  parseInputFile();
  vector<int> rt; // Remaining time

  for (int i = 0; i < pidCount; i++) {
    rt.push_back(process[i].burst);
    waitTime.push_back(-INC);
  }

  int complete = 0, min = MAX;
  int shortest = 0, finishTime;
  bool check = false;

  // Process until all processes gets completed
  while (complete != pidCount) {
    for (int j = 0; j < pidCount; j++) {
      if ((process[j].arrival <= timeCounter) &&
          (rt[j] < min) && rt[j] > 0) {
        min = rt[j];
        shortest = j;
        check = true;
      }
    }
    printRunProcess(shortest+1);
    if (check == false) {
      timeCounter++;
    }
    rt[shortest]--;
    min = rt[shortest];

    if (min == 0)
      min = MAX;

    if (rt[shortest] == 0) {
      complete++;
      finishTime = timeCounter + 1;
      printCompleteProcess(shortest+1);
      waitTime[shortest] = finishTime - process[shortest].burst -
        process[shortest].arrival;
      if(waitTime[shortest] < 0)
        waitTime[shortest] = 0;
    }
    timeCounter++;
  }
}

// Returns the average response time
double SRTF::avgRespQuery() {
  return 0;
}

// Returns the average wait time
double SRTF::avgWaitQuery() {
  for(int i = 0; i < pidCount; i++){
    avgWait+= waitTime[i];
  }
  return avgWait/pidCount;
}

// Returns the average turnaround time
double SRTF::avgTurnaroundQuery() {
   for(int i = 0; i < pidCount; i++){
    avgTurn = avgTurn + process[i].burst + waitTime[i];
  }
  return avgTurn/pidCount;
}

// Returns the CPU usage in percentage form
double SRTF::cpuUseQuery() {
  double tot = 0;
  for (int i = 0; i < pidCount; i++) {
    tot += process[i].burst;
  }
  tot = tot / timeCounter * 100;
  return tot;
}
