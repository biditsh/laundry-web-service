#include "user.h"

User::User(void){
		userDorm=nullptr;
		userFloor=0;
		userMachine=0;
		userMachineType=0;
		userMachineId=nullptr;
}

void User::setUserDorm(const char * DormId){
	userDorm= makecopy(DormId);
}

void User::setUserFloor(int FloorId){
	userFloor= FloorId;
}

void User::setUserMachine(int MachineIdNo){
	userMachine=MachineIdNo;
}

void User::setUserMachineType(const char MachineType){
	userMachineType=MachineType;
}

char* User::getUserMachineId(void){
	return "ell-test-test-test";
}