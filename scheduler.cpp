#include "scheduler.h"
 
 scheduler::Scheduler(string input)
 {
    inputFile = input;
    avgTurn = 0;
    avgResp = 0;
    avgWait = 0;
    cpuUsage = 0;
    pidCount = 0;
 }
 virtual void scheduler::parseInputFile()
 {
    ifstream inFile;
    int pidVal;
    int timeVal;
    int burstVal;
    
    if(inFile.fail())
        return;
    while(inFile >> pidVal >> timeVal >> burstVal){
        process[pidCount].pid = pidVal;
        process[pidCount].arrival = timeVal;
        process[pidCount].burst = burstVal;
        pidCount++;
    }
    inFile.close();
 }
