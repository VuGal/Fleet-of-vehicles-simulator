#ifndef VEHICLEMENU_H_
#define VEHICLEMENU_H_

#include <iostream>
#include <cstdio>

using namespace std;

extern int vehicle_menu_choice;

extern void availableVehicles();
extern void takenVehicles();

void vehiclemenu(){

	cout << "================================================\n";
	cout << "================= MENU POJAZDOW ================\n";
	cout << "================================================\n\n";

	cout << "                   1. Pojazdy w uzyciu\n\n";
	cout << "                   2. Pojazdy dostepne do uzycia\n\n\n\n";
	cout << "                   3. Dodaj pojazd\n\n\n\n\n\n";
	cout << "                   4. Powrot\n\n\n\n";

	cout << "Wybierz opcje: ";

	cin >> vehicle_menu_choice;
	cout << "\n";

		bool poprawna = false;

		while(poprawna == false){

			switch (vehicle_menu_choice){

			case 1: {poprawna = true; system("CLS"); availableVehicles(); break;}

			case 2: {poprawna = true; system("CLS"); takenVehicles(); break;}

			case 3: {cout << "Dodano nowy pojazd."; break;}

			case 4: {poprawna = true; system("CLS"); mainmenu(); break;}

			default: {cout << "Wybrano niepoprawna opcje.\n\nWybierz opcje: "; cin >> vehicle_menu_choice; cout << "\n";}
			}
		}
}


#endif /* VEHICLEMENU_H_ */
