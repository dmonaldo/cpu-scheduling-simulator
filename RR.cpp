#include "RR.h"

RR::RR(string input, int quantum) : Scheduler(input) {
  timeQuantum = quantum;
  parseInputFile();
}

// RR::~RR(void) {
//
// }

void RR::runScheduler() {
  bool allProcessesComplete = false;
  while (!allProcessesComplete) {
    for (int i = 0; i < process.size(); i++) {
      // Run process if arrival time is after current CPU time
      if (process[i].arrival <= timeCounter) {
        // Run process if the process has not been completed yet
        if (process[i].state) {
          for (int j = 0; j < timeQuantum; j++) {
            timeCounter++;
            burstCounter++;
            process[i].timeRemaining--;
            printRunProcess(process[i].pid);
            // cout << process[i].arrival << " " << process[i].burst << " " << process[i].timeRemaining << endl << endl;

            // Mark process as complete
            if (process[i].timeRemaining <= 0) {
              printCompleteProcess(process[i].pid);
              process[i].completionTime = timeQuantum;
              process[i].state = false;
              break;
            }
          }
        }
      }
    }

    // Check if all processes have completed
    bool completed = true;
    for (int i = 0; i < process.size(); i++) {
      if (process[i].state) {
        completed = false;
      }
    }
    if (completed) {
      allProcessesComplete = true;
    } else {
      timeCounter++;
    }
  }
}

double RR::cpuUsageQuery() {
  return ((double)burstCounter / (double)timeCounter)*100;
}

double RR::avgRespQuery() {
  double sum;
  for (int i = 0; i < pidCount; i++) {
    sum += i * timeQuantum;
  }
  return sum / pidCount;
}

double RR::avgWaitQuery() {
  // turn around time - burst time
  return 0;
}

double RR::avgTurnaroundQuery() {
  // completion time - arrival time
  return 0;
}
