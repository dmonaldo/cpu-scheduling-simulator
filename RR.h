#ifndef FCFS_H
#define FCFS_H

#include "scheduler.h"

using namespace std;

class RR : public Scheduler {
  public:
<<<<<<< HEAD
    RR(string input, int quantum);
    // ~RR(void);
=======
    RR(string input): Scheduler(input){}; //quantum value?
    ~RR(void);
>>>>>>> ca0f40edef0cf0dabb8b49610db92e4cc9da9c60
    void runScheduler();

  protected:
    double avgRespQuery();
    double avgWaitQuery();
    double avgTurnaroundQuery();
    int timeQuantum;
};
#endif
