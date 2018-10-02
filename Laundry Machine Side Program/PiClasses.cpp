#include <iostream>
#include "PiClasses.h"

Machine::Machine(void) {
  response = 0;
}

void Machine::setFileAsUSE(int time) {
  ofstream statusfile;
  statusfile.open("status.dat");
  cout << "IN USE-" << time << " minutes" << endl;
  statusfile << "IN USE-" << time
             << " minutes"; // its about 1 minute when the vibration starts
  statusfile.close();
}

void Machine::setFileAsNOTUSED(void) {
  ofstream statusfile;
  statusfile.open("status.dat");
  statusfile << "MACHINE NOT-IN USE";
  statusfile.close();
}

void Machine::setAsNoSensor(void){
    ofstream statusfile;
    statusfile.open("status.dat");
    statusfile << "NSFD";
    statusfile.close();
    cout << "NSFD stored. Restart the program after connecting sensor." << endl;
}

bool Machine::IsResponding(void) { return response; }

void Machine::setResponse(bool b) { response = b; }

MovementData::MovementData(void) : Machine() {
  // MovementData::MovementData(void): Machine() {
  fill_n(x, 2, 0);
  fill_n(y, 2, 0);
  fill_n(z, 2, 0);
}

int MovementData::TESTTIME = 10;
int MovementData::CYCLEDURATION = 2 * 60;

bool MovementData::contVibCheck(istream &file) {
  string data;
  double startTime = getCurrentTime();
  float duration = 0;
  int i = 0;
  int vibct = 0;
  while (duration < TESTTIME) {
    duration = getCurrentTime() - startTime;
    cout << duration << endl;
    getline(file, data);
    sleep(0.8f);
    // MovementData::AddData(data);
    // cout<<data<<endl;
    x[0] = x[1];
    y[0] = y[1];
    z[0] = z[1];
    if (data.length() == 11) {
      stringstream(data.substr(0, 3)) >> x[1];
      stringstream(data.substr(4, 3)) >> y[1];
      stringstream(data.substr(8, 3)) >> z[1];
    }

    if (x[0] < x[1] - 2 || x[0] > x[1] + 2 || y[0] < y[1] - 2 ||
        y[0] > y[1] + 2 || z[0] < z[1] - 2 || z[0] > z[1] + 2) {
      i++;
      vibct++;
      cout << "motion detected" << endl;
    } else
      i++;
    // cout<<"not moving"<<endl;
  }
  if (((float)vibct/(float)i)>0.25){
    return 1;
  } else {
    return 0;
  }
}
