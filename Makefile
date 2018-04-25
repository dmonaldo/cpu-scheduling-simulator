#Author Alex Runciman
#Makefile for projectt 2
CC = g++
CFLAGS = -c -Wall
all: schedsim

schedsim: main.o FCFS.o RR.o SRTF.o scheduler.o
	$(CC) main.o FCFS.o SRTF.o scheduler.o -o schedsim

scheduler.o: scheduler.h scheduler.cpp
	$(CC) $(CFLAGS) scheduler.cpp
FCFS.o: FCFS.h scheduler.h FCFS.cpp
	$(CC) $(CFLAGS) FCFS.cpp
RR.o: RR.h scheduler.h RR.cpp
	$(CC) $(CFLAGS) RR.cpp
SRTF.o: SRTF.h scheduler.h SRTF.cpp
	$(CC) $(CFLAGS) SRTF.cpp
main.o: main.cpp SRTF.cpp RR.o FCFS.cpp scheduler.cpp
	$(CC) $(CFLAGS) main.cpp
clean:
	\rm*.o*~
