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
This program can successfully simulate the FCFS, RR and SRTF scheduling algorithms. It reads in a file of PID numbers, arrival times and burst times for a list of processes to be simulated. The output is printed to the console

###### Weaknesses:
Calculations for RR averages are slightly off.

###### Team Members:
- Alex Runciman (@agrsu) - Implemented FCFS, implemented SRTF, wrote parseInputFile function, wrote makefile
- Dante Monaldo (@dmonaldo) - Implemented RR, parsed command line arguments, wrote README
