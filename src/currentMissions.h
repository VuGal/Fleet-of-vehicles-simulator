#ifndef CURRENTMISSIONS_H_
#define CURRENTMISSIONS_H_

#include <iostream>

using namespace std;

extern vector <Mission*> listaMisji;

extern void missionmenu();
extern void missionInfoMenu(int);

void currentMissions(){

	system("CLS");

	int count = 1;

	for(unsigned int i=0; i<listaMisji.size(); i++){
		cout << i+1 << ". ";
		/*listaMisji.at(i)->getMissionEmployeeID();
		cout << " ";
		listaMisji.at(i)->getMissionVehicleID();
		cout << " ";*/
		listaMisji.at(i)->getMissionStartingPoint();
		cout << " - ";
		listaMisji.at(i)->getMissionEndPoint();
		//cout << " ";
		//listaMisji.at(i)->getMissionDistance();
		cout << "\n\n";
		count++;
	}

	cout << "\n\n\n\nWybierz misje i nacisnij ENTER (0 - powrot) : ";

	string mission_choice_string; int mission_choice; bool poprawna = false;

			while(poprawna == false){

					cin >> mission_choice_string;

					try {
					mission_choice = stoi(mission_choice_string);
					}

					catch(invalid_argument iaex) {cout << "\n\nNiepoprawny wybor. Wybierz misje (0 - powrot) : "; continue;}

					if(mission_choice < count && mission_choice > -1){
						poprawna = true;
					}

					else {cout << "\n\nNiepoprawny wybor. Wybierz misje (0 - powrot) : "; continue;}
				}

	if (mission_choice == 0) {system("CLS"); missionmenu();}

	else {missionInfoMenu(mission_choice-1);}
}



#endif /* CURRENTMISSIONS_H_ */
