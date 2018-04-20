// Abstract class for scheduler algorithms

class Scheduler {
  public:
    Scheduler(void);
    ~Scheduler(void);
    virtual void parseInputFile() = 0;
    virtual void runScheduler() = 0;

    // struct {
    //   int pid;
    //   bool state;
    //   int arrival;
    //   int burst;
    // }
}
