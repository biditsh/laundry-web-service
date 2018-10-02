/*error codes:
    NSF- No sensor found, when ttyACM0 cant be accecssed
    ICF- Incorrect Conficuration, when status.dat isn't found
    SVBG- Server Busy, when Workers are more than MAXWORKWERS
*/



#include "CLIENT.h"
#include <sstream>


CLIENT::CLIENT (string host, int port, string machineID){
  Socket sock(host.c_str(), port);
  int ret;

  if (sock.getConnected()){
    connectionStatus = "Conection was sucessful";
    cs = true;
  }
  else {
    connectionStatus = "Could not connect, check your internet: socket not connected";
    machineStatus = "Connection";
    machineTimer = "Failed";
    cs = false;
  }

  char buff[100];

  if ((ret = sock.recv(buff, 100-1)) < 0) {
    connectionStatus = "Could not connect, check your internet: bad return value";
    cout << ret << endl;
    cs = false;
  }

  cout << connectionStatus << endl;
  // assert:  welcome message received and connection to server completed

  while (cs) {
    sock.send(machineID.c_str(), machineID.size());
    ret = sock.recv(buff, 100-1);
    buff[ret] = '\0';  // add terminating nullbyte to received array of char

    string information = buff;
    cout << buff << endl;
    vector<string> parts = split(information, '-');

    if(ret = 0){
        machineStatus = "Data not";
        machineTimer = "received";
    }

    else if (strcmp(buff, "EPIC") == 0){   //happens when status.dat isn't found
      machineStatus="Pi Configuration";
      machineTimer="Error";
    }

    else if (strcmp(buff, "SVBG") == 0){      //happens when MAXWORKER is reached
      machineStatus="Server";
      machineTimer="Busy";
    }

    else if (strcmp(buff, "SNFD") == 0){      //happens when dev/ttyACMx isn't found by Pi
      machineStatus="Sensor";
      machineTimer="Not Found";
    }

    else if (strcmp(buff, "WRCD") == 0){          //happend when wrong machine Id is sent to Pi
      machineStatus="Configuration";
      machineTimer="Error";
    }


     else if (parts.size() != 2) {
          cerr << "invalid data" << endl;
          cerr << "recieved string: " << information << endl;
          machineStatus="Invalid";
          machineTimer= "Response";
    }


    else{
         machineStatus = parts.at(0);
         machineTimer = parts.at(1);
    }

    //------------------------------
    ret = sock.recv(buff, 100-1);
    buff[ret] = '\0';  // add terminating nullbyte to received array of char

    string information = buff;
    sock.send("DONE", 4);

    if (information == "DONE") {
      sock.send("END", 3);
      sock.close();
      break;
    }
  }
}

vector<string> CLIENT::split(string str, char sep) {
  stringstream test(str);
  string segment;
  vector<string> seglist;

  while(getline(test, segment, sep)) {
   seglist.push_back(segment);
  }

  return seglist;
}


string CLIENT::returnMachineStatus(){
  return machineStatus;
}

string CLIENT::returnMachineTimer(){
  return machineTimer;
}
