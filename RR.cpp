#include "RR.h"

RR::RR(string input, int quantum) : Scheduler(input) {
  timeQuantum = quantum;
  parseInputFile();
}

// RR::~RR(void) {
//
// }

void RR::runScheduler() {
  while(process.size() > 0) {
    for (int i = 0; i < process.size(); i++) {
      // Run process if arrival time is after current CPU time
      if (process[i].arrival <= timeCounter) {
        for (int j = 0; j < timeQuantum; j++) {
          timeCounter++;
          burstCounter++;
          process[i].burst--;
          printRunProcess(process[i].pid);

          // Remove process from vector if completed
          if (process[i].burst <= 0) {
            printCompleteProcess(process[i].pid);
            process.erase(process.begin() + i);
            break;
          }
        }
      } else {
        timeCounter++;
      }
    }
  }
}

double RR::cpuUsageQuery() {
  return ((double)burstCounter / (double)timeCounter)*100;
}

double RR::avgRespQuery() {
  // avgResp = avgWaitQuery();
  // return avgResp;
  return 0;
}

double RR::avgWaitQuery() {
  // vector<int> tempStart;
  // tempStart[0] = process[0].arrival;
  // for(int i = 1, j = 0; i < pidCount; i++, j++){
  //     tempStart[i] = tempStart[j] + process[j].burst;
  // }
  // for(int i = 0; i < pidCount; i++){
  //   wait[i] = tempStart[i] - process[i].arrival;
  //   avgWait += wait[i];
  // }
  // avgWait \= pidCount++;
  // return avgWait;
  return 0;
}

double RR::avgTurnaroundQuery() {
  // int tempBurst = 0;
  // int tempTurn = 0;
  // for(int i = 0; i < pidCount; i++){
  //   tempBurst += process[i].burst;
  //   tempTurn = tempBurst - process[i].arrival;
  //   avgTurn += tempTurn;
  // }
  // avgTurn /= pidCount++;
  // return avgTurn;
  return 0;
}
