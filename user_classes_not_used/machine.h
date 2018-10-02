#ifndef _MACHINE_
#define _MACHINE_

#include <cstring>
#include <sstream>

class Machine{
	char * MachineId;  /**The complete ID representing the machine ex. ell-2-123l*/
	char MachineType; /**Type of machine, in the id, the last letter denotes it*/
	int MachineIdNo; /**Id number of machine, in the complete id, the numbers in last term denote it*/
	bool status; /*boolean value that says whether the machine is in use or not*/
	int timer; /**integer that stores the value of number shown in machine's timer*/

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
	Machine(const char * MachineIdN);

	int getTimer(void){
		//gets the timer from the server -- not exactly sure how this is going to happen though
		return 19;
	}

	bool getStatus(void){
		return 0;
	}

	void errorReport(char * emailId){
		//gotta find a way to email the AC
	}

	void setNotification(char * emailId){
		//gotta find a way to email the user
	}

	char * getMachineId(void);
};

#endif

