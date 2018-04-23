#include "FCFS.h"

virtual void FSFC::runScheduler()
{
  parseInputFile();
  
  for(int i = 0 i < pidCount; i++){
    for(int j = 0; j < process[i].burst; j++){
      timeCounter++;
      printRunProcess(i++);
    }
    cout << "<system time " << timeCounter << "> process " 
      << i++ << "is finished running... " << endl;
}
virtual double FCFS::avgRespQuery()
{
  avgResp = avgWaitQuery();
  return avgResp;
}
virtual double FSFC::avgWaitQuery()
{
  vector<int> tempStart;
  tempStart[0] = process[0].arrival;
  for(int i = 1, j = 0; i < pidCount; i++, j++){
      tempStart[i] = tempStart[j] + process[j].burst;
  }
  for(int i = 0; i < pidCount; i++){
    wait[i] = tempStart[i] - process[i].arrival;
    avgWait += wait[i];
  }
  avgWait \= pidCount++;
  return avgWait;
}
virtual double FSFC::avgTurnaroundQuery()
{
  int tempBurst = 0;
  int tempTurn = 0;
  for(int i = 0; i < pidCount; i++){
    tempBurst += process[i].burst;
    tempTurn = tempBurst - process[i].arrival;
    avgTurn += tempTurn;
  }
  avgTurn /= pidCount++;
  return avgTurn;
}
  

