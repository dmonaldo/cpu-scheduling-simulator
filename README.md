# cpu-scheduling-simulator
## CPU scheduler that simulates FCFS, RR and SRTF

###### Scheduling algorithms:
1. First Come First Served (FCFS)
2. Round Robin (RR)
3. Shortest Remaining Time First (SRTF)

This program reads in a file of PID numbers, arrival times and burst times for a list of processes to be simulated. The output is printed to the console. `input.1` is a sample test file.

```
./a.out input.1 FCFS
```

RR requires a time quantum to be entered in the command.
```
./a.out input.1 RR 10
```

Average waiting time, response time, turnaround time and overall CPU usage is printed to the console after the scheduler has completed.

Scheduler is an abstract class for FCFS, RR and SRTF.

###### Strengths:
Proper use of an abstract class (scheduler) containing pure virtual functions and derived classes properly to implement virtual function bodies. This program can successfully simulate the FCFS, RR and SRTF scheduling algorithms.

###### Weaknesses:
SRTF response time function was unable to be created successfully and therefore will always return 0.

###### Team Members:
- Alex Runciman (@agrsu) - Implemented FCFS, implemented SRTF, implemented the majority of scheduler, wrote parseInputFile function,
wrote makefile, wrote part of main
- Dante Monaldo (@dmonaldo) - Implemented RR, implemented part of scheduler, parsed command line arguments, wrote README,
wrote part of main
