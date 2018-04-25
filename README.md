# cpu-scheduling-simulator
## CPU scheduler that simulates FCFS, RR and SRTF

###### Scheduling algorithms:
1. First Come First Served (FCFS)
2. Round Robin (RR)
3. Shortest Remaining Time First (SRTF)

FCFS and SRTF can use the same parse function. RR must use a different parse function that accounts for the time quantum.

Compute average waiting time, response time, turnaround time and overall CPU usage for scheduler.

Scheduler is an abstract class for FCFS, RR and SRTF.

###### Strengths:
Using virtual functions to implement functions relating to FCFS, RR, and SRTF


###### Weaknesses:
SRTF response time function was unable to be created successfully and so will always output 0.

###### Team Members:
- Alex Runciman (@agrsu) - Implemented FCFS, implemented SRTF, implemented the majority of scheduler, wrote parseInputFile function, 
wrote makefile, wrote part of main
- Dante Monaldo (@dmonaldo) - Implemented RR, implemented part of scheduler, parsed command line arguments, wrote README, 
wrote part of main
