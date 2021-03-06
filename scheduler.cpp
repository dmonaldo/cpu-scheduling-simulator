#include "scheduler.h"

Scheduler::Scheduler(string input) {
  inputFile = input;
  avgTurn = 0;
  avgResp = 0;
  avgWait = 0;
  cpuUsage = 0;
  pidCount = 0;
  timeCounter = 0;
}

void Scheduler::parseInputFile() {
  ifstream inFile;
  int pidVal;
  int arrivalVal;
  int burstVal;

  inFile.open(inputFile.c_str());

  if (inFile.fail())
    return;

  // Read process values from file and store vector
  while (inFile >> pidVal >> arrivalVal >> burstVal) {
    processInfo tempProcess = {
      pidVal,
      true,
      arrivalVal,
      burstVal,
      0,
      burstVal
    };
    process.push_back(tempProcess);
    pidCount++;
  }

  inFile.close();

  cout << "Total " << pidCount << " tasks are read from "
      << inputFile << ". Press 'enter' to start..." << endl
      << "==========================================" << endl;
  cin.ignore();
}

void Scheduler::printRunProcess(int numPro) {
  cout << "<system time " << timeCounter << "> process "
    << numPro << " is running" << endl;
}

void Scheduler::printCompleteProcess(int numPro) {
  cout << "<system time " << timeCounter << "> process "
    << numPro << " is finished..." << endl;
}

void Scheduler::printProcessResult() {
  cout << "==========================================" << endl;
  cout.precision(2);
  cout << fixed;
  cout << "CPU usage : " << cpuUseQuery() << " %"<< endl;
  cout << "Average wait time : " << avgWaitQuery() << endl;
  cout << "Average response time : " << avgRespQuery() << endl;
  cout << "Average turnaround time : " << avgTurnaroundQuery() << endl;
  cout << "==========================================" << endl;
}
