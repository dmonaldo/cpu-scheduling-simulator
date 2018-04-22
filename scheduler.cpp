// Abstract class for scheduler algorithms
#include <vector>
using namespace std
struct{
  int pid;
  bool state;
  int arrival;
  int burst;
}

class Scheduler {
  public:
    Scheduler(void);
    ~Scheduler(void);
    virtual void parseInputFile() = 0;
    virtual void runScheduler() = 0;
  protected:
    vector<int> waitTime;
    double avgWait;
    vector<int> respTime;
    double avgResp;
    vector<int> turnTime;
    double avgTurn;
    
    // struct {
    //   int pid;
    //   bool state;
    //   int arrival;
    //   int burst;
    // }
}
