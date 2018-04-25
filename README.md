# cpu-scheduling-simulator
## CPU scheduler that simulates FCFS, RR and SRTF

###### Scheduling algorithms:
1. First Come First Served (FCFS)
2. Round Robin (RR)
3. Shortest Remaining Time First (SRTF)

FCFS and SRTF can use the same parse function. RR must use a different parse function that accounts for the time quantum.

Compute average waiting time, response time, turnaround time and overall CPU usage for each scheduler after processes have been run.

Scheduler is an abstract class for FCFS, RR and SRTF.

###### Strengths:
Proper use of an abstract class, scheduler, containing pure virtual functions and derivived classes properly implement these pure 
virtual functions.

###### Weaknesses:
SRTF response time function was unable to be created successfully and therefore will always return 0.

###### Team Members:
- Alex Runciman (@agrsu) - Implemented FCFS, implemented SRTF, implemented the majority of scheduler, wrote parseInputFile function, 
wrote makefile, wrote part of main
- Dante Monaldo (@dmonaldo) - Implemented RR, implemented part of scheduler, parsed command line arguments, wrote README, 
wrote part of main
