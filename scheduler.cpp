#include "scheduler.h"

Scheduler::Scheduler(string input) {
  inputFile = input;
  avgTurn = 0;
  avgResp = 0;
  avgWait = 0;
  cpuUsage = 0;
  pidCount = 0;
}

void Scheduler::parseInputFile() {
  ifstream inFile;
  int pidVal;
  int arrivalVal;
  int burstVal;

  inFile.open(inputFile);

  if (inFile.fail())
    return;

  while(inFile >> pidVal >> arrivalVal >> burstVal) {
    cout << process.size() << endl;
    process.push_back(processInfo());
    process.at(pidCount).pid = pidVal;
    process.at(pidCount).arrival = arrivalVal;
    process.at(pidCount).burst = burstVal;
    pidCount++;
  }

  inFile.close();
  cout << " Total " << pidCount << " tasks are read from \"input\"."
    << "Press \'enter\' to start...";
  cin.ignore();
  cout << "========================================================"
    << "==========" << endl;
}

void Scheduler::printRunProcess(int numPro) {
  cout << "<system Time " << timeCounter << "> process "
    << numPro << " is running" << endl;
}

// void Scheduler::printProcessResult() {
//   cout << "========================================================"
//      << "==========" << endl;
//   //cout << "CPU usage : " << << endl;
//   cout << "Average wait time : " << avgWaitQuery() << endl;
//   cout << "Average resopnse time : " << avgRespQuery() << endl;
//   cout << "Average turnaround time : " << avgTurnaroundQuery() << endl;
//   cout << "========================================================"
//      << "==========" << endl;
// }
