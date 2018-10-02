#ifndef _MENU_
#define _MENU_

#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
using namespace std;

#include "dorm.h"

class Menu {
	protected:
	  int DormQty; /** < the number of Dorms */
	  Dorm ** AllDormList; /** A list array pointing to Dorm clas */

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

	public:

	  Menu(void);
	  void showDormList(ostream &ostr);
	  Dorm& operator[] (int n);
		int getDormQty(void);
	};

#endif