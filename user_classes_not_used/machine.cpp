#include<iostream>
using namespace std;

#include "machine.h"

Machine::Machine(const char * MachineIdN){
		MachineId=makecopy(MachineIdN);
		MachineType=pullMachineType(MachineIdN);
		MachineIdNo=pullMachineIdNo(MachineIdN);
	}

char * Machine::getMachineId(void){
		return MachineId;
	}

