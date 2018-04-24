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
  int timeVal;
  int burstVal;

  inFile.open(inputFile);

  if(inFile.fail())
    return;
  while(inFile >> pidVal >> timeVal >> burstVal) {
    process.pid.push_back(pidVal);
    process.arrival.push_back(timeVal);
    process.burst.push_back(burstVal);
    //process[pidCount].pid = pidVal;
    //process[pidCount].arrival = timeVal;
    //process[pidCount].burst = burstVal;
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

void Scheduler::printProcessResult() {
  cout << "========================================================"
     << "==========" << endl;
  //cout << "CPU usage : " << << endl;
  cout << "Average wait time : " << avgWaitQuery() << endl;
  cout << "Average resopnse time : " << avgRespQuery() << endl;
  cout << "Average turnaround time : " << avgTurnaroundQuery() << endl;
  cout << "========================================================"
     << "==========" << endl;
}
