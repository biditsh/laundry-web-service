/* Implementation module for multithreaded server thread class
   RAB 5/2/16.
   Modified by Bidit Sharma for Laundry Web Service project 5/8/16*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <thread>
#include "Worker.h"

#define MAXBUFF 13
// int Worker::MAXBUFF = MAXBUFF;

Worker::Worker(int i, Socket *sp, const ControlData *cdp, const char Id[13])
    : thread(&Worker::doWork, this, cdp), id(i), sockp(sp), state(RUNNING) {
  cout << "New Worker Connected." << endl;
  strcpy(MachineId, Id);
}

/* NOTE about thread constructor call above:
   methods have an implicit first argument, namely, the object whose state
   variables they act on.  That object argument must be explicitly passed
   for this 2-argument thread constructor */

Worker::~Worker() {
  delete sockp;
  sockp = 0;
}

void Worker::doWork(const ControlData *cdp) {
  char buff[MAXBUFF]; /* message buffer */
  int ret; /* return value from a call */

  // send welcome message
  if (cdp->contin) {
    strcpy(buff, "ACK");
  } else
    strcpy(buff, "DONE");
  sockp->send(buff, strlen(buff));
  while (strcmp(buff, "DONE") != 0) {
    ret = sockp->recv(buff, MAXBUFF - 1);
    buff[ret] = '\0'; // add terminating nullbyte to received array of char

    if (strcmp(buff, "DONE") == 0 || !cdp->contin) {
      strcpy(buff, "DONE");
      sockp->send(buff, 4);
      cout << "[" << id << "] sent termination message" << endl;
    }

    else if (strncmp(buff, MachineId, 12) == 0) {
      ifstream file("status.dat");
      if (file.good()) {
        string firstline;
        getline(file, firstline);
        cout << "sent:" << firstline << endl; // if sensor thread doesn't find ttyACMx, it'll contain error code for not finding sensor, otherwise status and timer is sent
        sockp->send(firstline.c_str(), firstline.length());
        file.close();
      } else {
        sockp->send("EPIC",4); // error in Pi configuration, status.dat not found
        cout << "[" << id << "]status file not found. EPIC sent" << endl;
      }
    } else {
      sockp->send("WRCD", 4); // wrong machine code recieved, foolproof
      cout << "[" << id << "] wrong machine code. WRCD sent" << endl;
    }
  }

  // receive END message from client
  if ((ret = sockp->recv(buff, MAXBUFF - 1)) != -1) {
    buff[ret] = '\0';
    cout << "[" << id << "] Received " << buff << " from client" << endl;
  }
  state = DONE;
}
