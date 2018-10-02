#ifndef _DORM_
#define _DORM_

#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

#include "floor.h"


class Dorm{
	char * DormId;  /**3 letters Id for a dorm, ex. ell-> Ellingson*/
	char * DormName; /**Name of the dorm*/
	int FloorQty; /**Number of floors*/
	Floor ** AllFloorList;  /**Array to pointers to each floor class*/

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
	Dorm(const char * DormNameN,const char * DormIdN);
	void addFloor(const char * MachineId);
	void showFloorList(ostream &ostr);
	Floor& operator[] (int n);
	char * getDormId(void);
	char * getDormName(void);
};


#endif

