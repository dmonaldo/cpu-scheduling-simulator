#include "FCFS.h"

virtual void FSFC::runScheduler()
{
  waitTime[0] = 0;
  for(int i = 1; i < pidCount; i ++){
    waitTime[i] = 0;
    for(int j = 0 ; j < i; j++){
      waitTime[i] += process[i].burst;
    }
  }
}
