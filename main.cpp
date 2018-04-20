#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  string inputFile;
  string scheduler;
  int timeQuantum;

  // Check for minimum arguments to run
  if (argc < 3) {
    cout << "You are missing some arguments." << endl;
    return 0;
  }

  inputFile = argv[1];
  scheduler = argv[2];

  // Determine scheduler algorithm to run
  if (scheduler == "FCFS") {
    cout << "FCFS" << endl;
    // Initialize FCFS object here
  }
  else if (scheduler == "RR") {
    cout << "RR" << endl;
    if (argc < 4) {
      cout << "You are missing the time quantum argument." << endl;
      return 0;
    } else {
      timeQuantum = atoi(argv[3]);
    }
    // Initialize RR object here
  }
  else if (scheduler == "SRTF") {
    cout << "SRTF" << endl;
    // Initialize SRTF object here
  }
  else {
    cout << "Invalid scheduler name." << endl;
    return 0;
  }

  return 0;
}
