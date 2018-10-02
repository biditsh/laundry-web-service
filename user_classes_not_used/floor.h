#ifndef _FLOOR_
#define _FLOOR_


#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

#include "machine.h"

class Floor{
	int FloorId; /*Number ID given to each floor*/
	int MachineQty;  /**Number of machines in each floor*/
	Machine ** AllMachineList;  /**Array to pointers to each machine in the floor*/

	int pullFloorNumber(const char * MachineId){
	char num[3];
	for (int i=4; i<6; i++)
		num[i-4]=MachineId[i];
	num[2]='\0';
	stringstream convert(num); 
	int r;
	convert>>r;
	return r;  //int r<<stringstream(num)
}
public:
	Floor(const char * MachineId);
	void addMachine(const char * MachineId);
	void showMachineList(ostream &ostr);
	Machine& operator[] (int n);
	int getFloorId(void);
};


#endif