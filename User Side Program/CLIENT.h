#ifndef _CLIENT_
#define _CLIENT_

#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include "Socket.h"

using namespace std; 

class CLIENT{
	string machineStatus; 
	string machineTimer; 
	string connectionStatus; 
	bool cs; //stands for connection status
	vector<string> split(string str, char sep);

public:
	CLIENT(string host, int port, string machineID); 
	string returnMachineStatus(); 
	string returnMachineTimer(); 
}; 

#endif  // _CLIENT_
