#include "scheduler.h"
 
 Scheduler::Scheduler(string input)
 {
    inputFile = input;
    avgTurn = 0;
    avgResp = 0;
    avgWait = 0;
    cpuUsage = 0;
    pidCount = 0;
 }
 virtual void Scheduler::parseInputFile()
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
    cout << " Total " << pidCount << " tasks are read from \"input\"."
     << "Press \'enter\' to start...";
    cin.ingore();
 }
void Scheduler::printRunProcess(int numPro)
{
 cout << "<system Time " << timeCounter << "> process " 
  << numPro << " is running" << endl;
}
void Scheduler::printProcess()
{
 cout << "CPU usage : " << << endl;
 cout << "Average wait time : " << avgWaitQuery() << endl;
 cout << "Average resopnse time : " << avgRespTime() << endl;
 cout << "Average turnaround time : " << avgTurnaroundQuery() << endl;
}
