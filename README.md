# cpu-scheduling-simulator
CPU scheduler that simulates FCFS, RR and SRTF

Scheduling algorithms
1) First Come First Served (FCFS)
2) Round Robin (RR)
3) Shortest Remaining Time First (SRTF)

FCFS and SRTF can use the same parse function. RR must use a different parse function that accounts for the time quantum.

Compute average waiting time, response time, turnaround time and overall CPU usage for scheduler.

main function:
- getCommand
- parseCommand
- createSimulatorObject

Create abstract class for FCFS, RR, SRTF:
- PCB data structure
- readInputFile
