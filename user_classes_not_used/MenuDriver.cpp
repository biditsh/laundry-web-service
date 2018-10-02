#include <iostream>

#include "menu.h"
#include "user.h"
#include "helpers.h"
using namespace std;

int main(){
		  	/*ifstream dormstream;
		dormstream.open("dormlist.dat");
		int dormQty;
		dormstream>>dormQty;
		cout<<dormQty ;
			
			for (int i=0; i<dormQty; i++){
			string name;                                //this will take the fisrt string which is the form of ell-02-123-l 
			dormstream >> name;
			cout<<name<<endl;
			string id; 
			dormstream>>id; 
			cout<<id<<endl;

}*/


	Menu m1;
	User u1;
	cout<<m1.getDormQty()<<endl;
	m1.showDormList(cout);
	+















































































































































	
	m1[0].showFloorList(cout);
	m1[0][2].showMachineList(cout);
	cout<<u1.getUserMachineId()<<endl;
}