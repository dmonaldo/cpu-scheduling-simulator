//AUTHORS: Alex Runciman
//FILENAME: FCFS.cpp
//DESCRIPTION: Implementation of functions declared in FCFS.h

#include "FCFS.h"

void FCFS::runScheduler()
{
  parseInputFile();
  waitTime.push_back(0);
  for(int i = 0 i < pidCount; i++){
    for(int j = 0; j < process[i].burst; j++){
      printRunProcess(i+INC);
      timeCounter++;
    }
    waitTime.push_back(timeCounter);
    cout << "<system time " << timeCounter << "> process " 
      << (i+INC) << "is finished running... " << endl;
}
double FCFS::avgRespQuery()
{
  avgResp = avgWaitQuery();
  return avgResp;
}
double FCFS::avgWaitQuery()
{
  avgWait = 0;
  for(int i = 0; i < pidCount; i++){
    avgWait += (waitTime[i]-process[i].arrival);
  }
  avgWait = avgWait/pidCount;
  return avgWait;
}
double FCFS::avgTurnaroundQuery()
{
  int tempBurst = 0;
  int tempTurn = 0;
  for(int i = 0; i < pidCount; i++){
    tempBurst += process[i].burst;
    tempTurn = tempBurst - process[i].arrival;
    avgTurn += tempTurn;
  }
  avgTurn = avgTurn/pidCount;
  return avgTurn;
}
double FCFS::cpuUseQuery()
{
  double totBurst = 0;
  for(int i = 0; i < pidCount; i++){
     totBurst += process[i].burst;
  }
  totBurst = (totBurst/timeCounter) * PERCENT;
  return totBurst;
}

  

