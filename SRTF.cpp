
void SRTF::runScheduler()
{
  vector<int> rt; //remaining time

  for (int i = 0; i < pidCount; i++){
    rt.push_back(process[i].burst);
  }
 
  int complete = 0, min = MAX;
  int shortest = 0, finishTime;
  bool check = false;
 
    // Process until all processes gets completed
  while (complete != pidCount) {
    for (int j = 0; j < pidCount; j++) {
      if ((process[j].arrival <= timeCounter) &&
          (rt[j] < min) && rt[j] > 0) {
        min = rt[j];
        shortest = j;
        check = true;
      }
    }
    printRunProcess(shortest+1);
    if(check == false) {
      timeCounter++;
    }
    rt[shortest]--;
    min = rt[shortest];
    if(min == 0)
      min = MAX;
    if (rt[shortest] == 0) {
      complete++;
      finishTime = timeCounter + 1;
      cout << "<system time " << finishTime << "> process " << (shortest+1) 
        << " is finished..." << endl;
      waitTime[shortest] = finishTime - process[shortest].burst -
        process[shortest].arrival;
      if(waitTime[shortest] < 0)
        waitTime[shortest] = 0;
    }
    timeCounter++;
  }
}
double SRTF::avgRespQuery()
{
}
double SRTF::avgWaitQuery()
{
  for(int i = 0; i < pidCount; i++){
    avgWait+= waitTime[i];
  }
  return avgWait/pidCount;
}
double SRTF::avgTurnaroundQuery()
{
   for(int i = 0; i < pidCount; i++){
    avgTurn = agTurn + process[i].burst + waitTime[i];
  }
  return avgTurn/pidCount;
}
