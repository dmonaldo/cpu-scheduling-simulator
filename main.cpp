#include <iostream>
#include <stdlib.h>
#include "SRTF.h"
#include "FCFS.h"
#include "scheduler.h"
#include "RR.h"

using namespace std;

int main(int argc, char *argv[]) {
  string inputFile;
  string scheduler;
  int timeQuantum;

  // Check for minimum arguments to run
  if (argc < 3) {
    cout << "You are missing some arguments." << endl;
    return 0;
  }

  inputFile = argv[1];
  scheduler = argv[2];

  // Determine scheduler algorithm to run
  if (scheduler == "FCFS") {
      cout << "Scheduling algorithm: " << scheduler << endl;
      FCFS fcfsObj(inputFile);
      fcfsObj.runScheduler();
      fcfsObj.printProcessResult();
  }
  else if (scheduler == "RR") {
      cout << "Scheduling algorithm: " << scheduler << endl;
      if (argc < 4) {
        cout << "You are missing the time quantum argument." << endl;
        return 0;
      } else {
        timeQuantum = atoi(argv[3]);
      }
      // Run RR Process
      RR RRobj(inputFile, timeQuantum);
      RRobj.runScheduler();
      RRobj.printProcessResult();
  }
  else if (scheduler == "SRTF") {
      cout << "Scheduling algorithm: " << scheduler << endl;
      SRTF srtfObj(inputFile);
      srtfObj.runScheduler();
      srtfObj.printProcessResult();

  }
  else {
      cout << "Invalid scheduler name. Exiting program..." << endl;
  }

  return 0;
}
