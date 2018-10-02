#include <iostream>
using namespace std;

#include "dorm.h"	


Dorm::Dorm(const char * DormNameN,const char * DormIdN){
		DormName=makecopy(DormNameN);
		DormId=makecopy(DormIdN);
		AllFloorList= new Floor* [99];
		FloorQty=0;		
	}

void Dorm::addFloor(const char * MachineId){
		for (int i=0; i<FloorQty; i++){
			if (pullFloorNumber(MachineId)==AllFloorList[i]->getFloorId()){
				AllFloorList[i]->addMachine(MachineId);
				return;
			}}
			AllFloorList[FloorQty]= new Floor(MachineId);
			FloorQty++;		
	}

void Dorm::showFloorList(ostream &ostr){
		for (int i=0; i<FloorQty; i++)
			ostr <<AllFloorList[i]->getFloorId()<<endl;		
	} 

Floor& Dorm::operator[] (int n){
		return *AllFloorList[n];
	}

char * Dorm::getDormId(void){
		return DormId;
	}

char * Dorm::getDormName(void){
		return DormName;
	}
