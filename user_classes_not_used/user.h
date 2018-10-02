#ifndef _USER_
#define _USER_

#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
using namespace std;

#include "menu.h"

class User{
	char * userDorm;
	int userFloor;
	int userMachine;
	char userMachineType;
	char* userMachineId;


	char * makecopy(const char * ch){        //the makecopy fuction to create copied of c style strings
	char * newchar;
	int i=0;
	for (i=0; ch[i]!='\0'; i++);
	newchar= new char [i+1];
	for(int j=0; j<i+1; j++)
		newchar[j]=ch[j];
	return newchar;
	}

public:
	User(void);
	void setUserDorm(const char * DormId);
	void setUserFloor(int FloorId);
	void setUserMachine(int MachineIdNo);
	void setUserMachineType(const char MachineType);
	char * getUserMachineId(void);
};

#endif