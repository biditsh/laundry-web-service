#ifndef _HELPERS_
#define _HELPERS_

#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
using namespace std;

char * makecopy(const char * ch){        //the makecopy fuction to create copied of c style strings
	char * newchar;
	int i=0;
	for (i=0; ch[i]!='\0'; i++);
	newchar= new char [i+1];
	for(int j=0; j<i+1; j++)
		newchar[j]=ch[j];
	return newchar;
}

char* pullDormId(const char * MachineId){
	char* name;
	name= new char[4];
	for (int i=0; i<3; i++)
		name[i]=MachineId[i];
	name[3]='\0';
	return name;
}
 
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

int pullMachineIdNo(const char * MachineId){
	char num[4];
	for (int i=7; i<10; i++)
		num[i-7]=MachineId[i];
	num[3]='\0';
	stringstream convert(num); 
	int r;
	convert>>r;
	return r;  //int r<<stringstream(num)
}

char pullMachineType(const char * MachineId){
	return MachineId[11];           //ell-12-145-l
}

#endif