/*Driver module by Bidit Sharma for Laundry Web Service project. 5/13/16
Threads based on program by RAB*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <cstring>
#include <thread>
#include <sys/time.h>
#include "PiClasses.h"
#include "Worker.h"

using namespace std;

#define MAXWORKERS 10

/** code for control thread
    @param cdp points to smakhared data structure for controlling server */
void doControl(ControlData *cdp, int port) {
  const int maxbuff = 100;
  char buff[maxbuff];
  while (cin.getline(buff, maxbuff - 1)) {
    if (strcmp(buff, "EXIT") == 0)
      break;
    else
      cerr << "[control thread] unrecognized command: " << buff << endl;
  }

  // assert:  buff == "EXIT"
  cout << "[control thread] EXIT encountered" << endl;
  cdp->contin = 0;

  // initialize as a Client, to unblock [main] accept()
  Socket sock("localhost", port);
  sock.recv(buff, maxbuff - 1); // welcome message

  //
  sock.send("DONE", 4);
}

/**code for thread tht deals with getting sensor data from serial port, analyzing it, deciding the status and timer of machine and updating the status file*/
void SensorProgram(void) {

//open the file contating address to serial port to get real time sensor data
  ifstream idStream;     
  idStream.open("idfile.dat");
  string serialObt;
  for (int i = 1; i <= 3; i++)    //go to the third line to get the address to serial port
      getline(idStream, serialObt);
  char serialAd[13];
  strcpy(serialAd, serialObt.c_str());
  serialAd[12]='\0';
  cout<<"Serial Address:--" <<serialAd<<"--"<<endl;
  idStream.close();

  MovementData M1;     //make a Machine class that represents this specific machine
  string data;
  ifstream filestream;
  filestream.open(serialAd);         //open the virtual serial port to get the vibration data
  if (filestream.good()) {
    M1.setResponse(1);                //set response as 1 or 0 if the arduino is found/not found
    while (1) {
      M1.setFileAsNOTUSED();          //set inital status as machine not used

      if (M1.contVibCheck(filestream)) {           //check for continuous vibration of machine
        cout << "Machine Started" << endl;
        double startTime = M1.getCurrentTime();      //record the start time
        double duration = 0;
        int counter = 1;
        while (duration < M1.CYCLEDURATION) {            //run the loop until cycle ends
          duration = M1.getCurrentTime() - startTime;    //caculate timer
          counter++;                         //counter facilitates to create delay while accessing file to avoid race conditions
          if (counter % 10000000 == 0) {                         
            double timeleft = (M1.CYCLEDURATION - duration) / 60;     //update status and timer in file
            M1.setFileAsUSE((int)timeleft + 1);                    
            counter = 0;
          }
        }
        cout << "Machine Stopped" << endl;              //change status after timer is over and machine is unused again
        M1.setFileAsNOTUSED();
      }
    }
  }

  else {
    M1.setResponse(0);                 //set response as false is sensor isn' connected or isn't respondng
    M1.setAsNoSensor();
    cout<<"Type EXIT to safely close the socket and exit."<<endl;
  }
}


int main(){             //main program

  ifstream idStream;                //open the idfile to get macine Id and port number for connection
  int port;
  char MachineId[13];
  idStream.open("idfile.dat");
  if (idStream.good()){
      idStream>>MachineId;
      cout<<"Machine Id:"<<MachineId<<endl;
      idStream>>port;
      idStream.close();
  }
  else{
      cout<<"idfile.dat not found"<<endl;
      return 1;
  }
  //cout<<"Connection to socket "<<port<<endl;

  ServerSocket ssock(port);
  if (ssock.getBound())
    cout << "[main] port " << port << " bound to server socket" << endl;
  else {
    cout << "[main] could not bind port " << port
         << " to server socket, aborting" << endl;
    return 1;
  }
  // server socket ssock is now set up

  /* Define shared data structure for controlling server */
  ControlData controlData;

  /* Create a thread for handling control input */
  thread controlThread(doControl, &controlData, port);
  thread Thread2(SensorProgram);

  /* main loop: */
  Socket *csockp; // to hold new client socket
  Worker *workers[MAXWORKERS];
  for (int i = 0; i < MAXWORKERS; i++)
    workers[i] = 0;
  int workerCount = 0;
  while (controlData.contin) {
    csockp = ssock.accept();

    int indx = 0; // loop control for finding unused element in workers[]
    while (indx < MAXWORKERS) {
      if (workers[indx] != 0 &&
          workers[indx]->getState() == ThreadState::DONE) {
        cout << "[main] joining on [" << workers[indx]->getId() << "]" << endl;
        workers[indx]->join();
        cout << "[main] join on [" << workers[indx]->getId() << "] accomplished"
             << endl;
        delete workers[indx];
        workers[indx] = 0;
      }
      if (workers[indx] == 0)
        break;
      indx++;
    }
    if (indx == MAXWORKERS) {
      cout << "[main] workers[] overfull, rejecting a new client" << endl;
      csockp->send("SVBG", 4); // server is busy, send error code back to client
      cout << "SVBG sent" << endl;
      continue;
    }

    workers[indx] =
        new Worker(workerCount++, csockp, &controlData, MachineId);      //creating a new worker class (thread) after a connection request is recieved
  }

  for (int i = 0; i < MAXWORKERS; i++)
    if (workers[i]) {
      cout << "[main] joining on [" << workers[i]->getId() << "]" << endl;
      workers[i]->join();
      cout << "[main] join on [" << workers[i]->getId() << "] accomplished"
           << endl;
      delete workers[i];
      workers[i] = 0;
    }

  controlThread.join();
  Thread2.join();
  cout << "[main] control thread join accomplished" << endl;

  return 0;
}
