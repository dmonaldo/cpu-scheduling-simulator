#include "RR.h"

// Constructor
RR::RR(string input, int quantum) : Scheduler(input) {
  timeQuantum = quantum;
  parseInputFile();
}

// Run the RR scheduler
void RR::runScheduler() {
  bool allProcessesComplete = false;
  while (!allProcessesComplete) {
    for (int i = 0; i < process.size(); i++) {
      // Run process if arrival time is after current CPU time
      // and if the process has not been completed yet
      if (process[i].arrival <= timeCounter && process[i].state) {
        for (int j = 0; j < timeQuantum; j++) {
          timeCounter++;
          burstCounter++;
          process[i].timeRemaining--;
          printRunProcess(process[i].pid);

          // Mark process as complete
          if (process[i].timeRemaining <= 0) {
            printCompleteProcess(process[i].pid);
            process[i].completionTime = timeCounter;
            process[i].state = false;
            break;
          }
        }
      }
    }

    // Check if all processes have completed or are idle
    bool completed = true;
    bool idle = false;
    for (int i = 0; i < process.size(); i++) {
      if (process[i].state) {
        completed = false;
      }
      if (process[i].arrival > timeCounter) {
        idle = true;
      }
    }

    // If all processes have completed, exit while loop
    if (completed) {
      allProcessesComplete = true;
    } else if (idle) {
      // Increment time if there are no processes to run and the CPU is idle
      timeCounter++;
    }
  }
}

// Returns the CPU usage in percentage form
double RR::cpuUsageQuery() {
  return ((double)burstCounter / (double)timeCounter) * 100;
}

// Returns the average response time
double RR::avgRespQuery() {
  double sum = 0;
  for (int i = 0; i < pidCount; i++) {
    sum += i * timeQuantum;
  }
  return sum / pidCount;
}

// Returns the average wait time
double RR::avgWaitQuery() {
  double sum = 0;
  for (int i = 0; i < pidCount; i++) {
    sum += process[i].completionTime - process[i].arrival - process[i].burst;
  }
  return sum / pidCount;
}

// Returns the average turnaround time
double RR::avgTurnaroundQuery() {
  double sum = 0;
  for (int i = 0; i < pidCount; i++) {
    sum += process[i].completionTime - process[i].arrival;
  }
  return sum / pidCount;
}
