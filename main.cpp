#include <iostream>

using namespace std;
enum scheAlgorithms {FCFS, RR, SRTF};

int main(int argc, char *argv[]) {
  string inputFile;
  string scheduler;
  int timeQuantum;

  /*
  string commandLine;
  stringstream iss(commandLine);
  iss >> inputFile >> scheduler;
  */
  // Check for minimum arguments to run
  if (argc < 3) {
    cout << "You are missing some arguments." << endl;
    return 0;
  }

  inputFile = argv[1];
  scheduler = argv[2];

  // Determine scheduler algorithm to run
  switch(scheduler)
  {
    case scheAlgorithms.FCFS:
      cout << "Scheduling algorithm: " << scheduler << endl;
      // Initialize FCFS object here and then print out results
      break;
    case scheAlgorithms.RR:
      cout << "Scheduling algorithm: " << scheduler << endl;
      /*
      iss >> inputFile >> scheduler >> timeQuantum;
      
      */
      if (argc < 4) {
        cout << "You are missing the time quantum argument." << endl;
        return 0;
      } else {
        timeQuantum = atoi(argv[3]);
      }
      // Initialize RR object here and then print out results
      break;
    case scheAlgorithms.SRTF:
      cout << "Scheduling algorithm: " << scheduler << endl;
      // Initialize SRTF object here and then print out results 
      break;
    default:
      cout << "Invalid scheduler name. Exiting program..." << endl;
    return 0;
  }


  return 0;
}
