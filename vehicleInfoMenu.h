#ifndef VEHICLEINFOMENU_H_
#define VEHICLEINFOMENU_H_

#include <iostream>

using namespace std;

extern int vehicle_choice;
extern int from_which_menu; // 1-takenVehicles; 2-availableVehicles

extern vector <Vehicle*> wolnePojazdy;
extern vector <Vehicle*> uzywanePojazdy;

bool isTaken;

void vehicleInfoMenu(int vehicle_choice, int from_which_menu){

	system("CLS");

	if(from_which_menu == 1){

		cout << "===============================================\n";
		cout << "           ";
		uzywanePojazdy.at(vehicle_choice)->getVehicleBrand();
		cout << "      ";
		uzywanePojazdy.at(vehicle_choice)->getVehicleModel();
		cout << "\n===============================================\n\n";

		cout << "\nAKTUALNIE W TRASIE: Tak\n\n";

		cout << "1. Powrot";

		int choice;

		cin >> choice;
		cout << "\n";

		bool poprawna = false;

		while(poprawna == false){

			switch (choice){

			case 1: {poprawna = true; system("CLS"); takenVehicles(); break;}

			default: {cout << "Wybrano niepoprawna opcje.\n\nWybierz opcje: "; cin >> choice; cout << "\n";}
			}
		}
	}

	if(from_which_menu == 2){
		cout << "===============================================\n";
		cout << "           ";
		wolnePojazdy.at(vehicle_choice)->getVehicleBrand();
		cout << "      ";
		wolnePojazdy.at(vehicle_choice)->getVehicleModel();
		cout << "\n===============================================\n\n";

		cout << "\nAKTUALNIE W TRASIE: Nie\n\n";

		cout << "1. Powrot\n\n";

		int choice;

		cin >> choice;
		cout << "\n";

		bool poprawna = false;

		while(poprawna == false){

			switch (choice){

			case 1: {poprawna = true; system("CLS"); availableVehicles(); break;}

			default: {cout << "Wybrano niepoprawna opcje.\n\nWybierz opcje: "; cin >> choice; cout << "\n";}
			}
		}
	}
}



#endif /* VEHICLEINFOMENU_H_ */
