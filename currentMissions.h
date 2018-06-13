#ifndef CURRENTMISSIONS_H_
#define CURRENTMISSIONS_H_

#include <iostream>

using namespace std;

extern vector <Mission*> listaMisji;

extern void missionmenu();
extern void missionInfoMenu(int);

void currentMissions(){

	system("CLS");

	int mission_choice;

	for(unsigned int i=0; i<listaMisji.size(); i++){
		cout << i+1 << ". ";
		listaMisji.at(i)->getMissionEmployeeID();
		cout << " ";
		listaMisji.at(i)->getMissionVehicleID();
		cout << " ";
		listaMisji.at(i)->getMissionStartingPoint();
		cout << " ";
		listaMisji.at(i)->getMissionEndPoint();
		cout << " ";
		listaMisji.at(i)->getMissionDistance();
		cout << "\n\n";

	}

	cout << "\n\n\n\nWybierz misje i nacisnij ENTER (0 - powrot) : ";
	cin >> mission_choice;

	if (mission_choice == 0) {system("CLS"); missionmenu();}

	else {missionInfoMenu(mission_choice-1);}
}



#endif /* CURRENTMISSIONS_H_ */
