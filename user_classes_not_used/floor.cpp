#include <iostream>
using namespace std;

#include "floor.h"

Floor::Floor(const char * MachineId){
		FloorId=pullFloorNumber(MachineId);
		MachineQty=0;
		AllMachineList= new Machine* [999];
		AllMachineList[MachineQty]=new Machine(MachineId);
		MachineQty++;
	}

void Floor::addMachine(const char * MachineId){
		for (int i=0; i<MachineQty; i++){
			if (!strcmp(MachineId,AllMachineList[i]->getMachineId())){
				cout<<"Double entry for machine. Duplication avoided"<<endl;
				return;     //escaping out of the function 
			}}
		AllMachineList[MachineQty]=new Machine(MachineId);
		MachineQty++;
	}

void Floor::showMachineList(ostream &ostr){
		for (int i=0; i<MachineQty; i++){
			ostr<<AllMachineList[i]->getMachineId()<<endl;
	}}

Machine& Floor::operator[] (int n){
		return *AllMachineList[n];
	}

int Floor::getFloorId(void){
		return FloorId;
	}