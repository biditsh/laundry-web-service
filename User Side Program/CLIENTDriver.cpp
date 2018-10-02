#include "CLIENT.h"

int main(){
	CLIENT client1 ("rns203-13.cs.stolaf.edu", 25276, "LINE1 ell-02-123-l.txt" ); 
	cout << client1.returnMachineStatus() << endl; 
	cout << client1.returnMachineTimer() << endl; 
}
