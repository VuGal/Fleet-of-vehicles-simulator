#ifndef MISSIONMENU_H_
#define MISSIONMENU_H_

#include <iostream>
#include <cstdio>

using namespace std;

extern void currentMissions();
extern void addMission();
extern void mainmenu();

void missionmenu(){

	cout << "================================================\n";
	cout << "==================  MENU MISJI  ================\n";
	cout << "================================================\n\n";

	cout << "                   1. Obecne misje\n\n";

	cout << "                   2. Dodaj misje\n\n\n\n\n\n";

	cout << "                   3. Powrot\n\n\n\n";

	cout << "Wybierz opcje: ";

	int choice;

	cin >> choice;
	cout << "\n";

		bool poprawna = false;

		while(poprawna == false){

			switch (choice){

			case 1: {poprawna = true; system("CLS"); currentMissions(); break;}

			case 2: {poprawna = true; system("CLS"); addMission(); break;}

			case 3: {poprawna = true; system("CLS"); mainmenu(); break;}

			default: {cout << "Wybrano niepoprawna opcje.\n\nWybierz opcje: "; cin >> choice; cout << "\n";}
			}
		}
}



#endif /* MISSIONMENU_H_ */
