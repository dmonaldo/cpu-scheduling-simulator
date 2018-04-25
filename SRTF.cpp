
void SRTF::runScheduler()
{
  parseInputFile();
  vector<int> rt; //remaining time

  for (int i = 0; i < pidCount; i++){
    watTime.push_back(0);
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
    printRunProcess(shortest+INC);
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
      cout << "<system time " << finishTime << "> process " << (shortest+INC)
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
  return 0;
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
    avgTurn = avgTurn + process[i].burst + waitTime[i];
  }
  return avgTurn/pidCount;
}
double SRTF::cpuUseQuery()
{
  double tot = 0;
  for(int i = 0; i < pidCount; i++){
    tot += process[i].burst;
  }
  tot = tot/timeCounter * PERCENT;
  return tot;
}
