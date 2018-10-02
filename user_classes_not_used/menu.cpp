#include <iostream>
using namespace std;

#include "menu.h"	

Menu::Menu(void){
	  	ifstream dormstream;
		dormstream.open("dormlist.dat");
		if (dormstream.is_open()){
		dormstream>>DormQty; 
			AllDormList=new Dorm *[DormQty];
			for (int i=0; i<DormQty; i++){
				char name[10];                                //this will take the fisrt string which is the form of ell-02-123-l 
				dormstream >> name;
				//cout<<name<<endl;
				char id[4]; 
				dormstream>>id; 
				//cout<<id<<endl;
				AllDormList[i]= new Dorm(name, id);         //based on the dorm constructor, it should take a sting and a number. 
				//make guards here later to make it foolproof
				//right now the hall will be in file line Hoyme hmh, but make it such that it  can read two or more words
			}
			dormstream.close();
		}
		else cout<<"--Unable to open dormlist file.--"<<endl;
		
		ifstream codestream;
		codestream.open("codelist.dat");
		if (codestream.is_open()){
			int n;
			int pass=0;
			codestream>>n;
			for (int i=0; i<n; i++){
				char MachineId[13];
				codestream>> MachineId;
				for (int j=0; j<DormQty; j++){
					if (!strcmp(AllDormList[j]->getDormId(),pullDormId(MachineId))){
						AllDormList[j]->addFloor(MachineId);
						pass++;
						break;
					}
				}	
				//count invalid entries
				//add guards if more or less codes than n
				//add guards for incorrect codes
				//add guards for duplicaton
			}
			cout<<"Invalid entries: "<<n-pass<<endl;
		}
		else cout<<"--Unable to open machine list file.--"<<endl;
}

void Menu::showDormList(ostream &ostr){
		for (int i=0; i<DormQty; i++){
		ostr<<AllDormList[i]->getDormName()<<endl;}
	  }  

Dorm& Menu::operator[] (int n){
	  	return *AllDormList[n];
	}

int Menu::getDormQty(void){
			return DormQty;
		}