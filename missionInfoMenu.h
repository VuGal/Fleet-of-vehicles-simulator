#ifndef MISSIONINFOMENU_H_
#define MISSIONINFOMENU_H_

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

extern int mission_choice;
extern int from_which_menu; // 1-vehicleInfoMenu    2-employeePersonalMenu

extern vector <Employee*> listaPracownikow;
extern vector <Vehicle*> listaPojazdow;

extern void currentMissions();
extern void vehicleInfoMenu(int, int);
extern void employeePersonalMenu(int);

//from currentMissions()
void missionInfoMenu(int mission_choice){

	system("CLS");

	int mission_employee_id, mission_vehicle_id, employee_id_found, vehicle_id_found, employee_number, vehicle_number;

	listaMisji.at(mission_choice)->saveMissionEmployeeID(&mission_employee_id);
	listaMisji.at(mission_choice)->saveMissionVehicleID(&mission_vehicle_id);


	for(unsigned int i = 0; i < listaPracownikow.size(); i++){

			listaPracownikow.at(i)->saveEmployeeID(&employee_id_found);

			if(mission_employee_id == employee_id_found) {

				employee_number = i;
				break;

			}

		}

	for(unsigned int i = 0; i < listaPojazdow.size(); i++){

				listaPojazdow.at(i)->saveVehicleID(&vehicle_id_found);

				if(mission_vehicle_id == vehicle_id_found) {

					vehicle_number = i;
					break;}

			}

	cout << "===============================================\n";
	cout << "                 DANE     MISJI";
	cout << "\n===============================================\n\n";

	cout << "Pracownik wykonujacy misje: ";

	listaPracownikow.at(employee_number)->getEmployeeName();
	cout << " ";
	listaPracownikow.at(employee_number)->getEmployeeSurname();

	cout << "\nUzywany pojazd: ";
	listaPojazdow.at(vehicle_number)->getVehicleBrand();
	cout << " ";
	listaPojazdow.at(vehicle_number)->getVehicleModel();

	cout << "\n\n\nZ: ";
	listaMisji.at(mission_choice)->getMissionStartingPoint();
	cout << "\nDo: ";
	listaMisji.at(mission_choice)->getMissionEndPoint();


	int speed = rand()%200;

	cout << "\n\nAktualna predkosc: ";

	if (speed<50) {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);}
	else if (speed>50 && speed<90) {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);}
	else {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);}

	cout << speed << " km/h";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);


	cout << "\n\n\nOdleglosc: ";
	listaMisji.at(mission_choice)->getMissionDistance();
	cout << " km";


	cout << "\n\n0. Powrot";

	char choice;

	bool poprawna = false;

	while(poprawna == false){

		choice = getch();

		switch (choice){

			case '0': {poprawna = true; system("CLS"); currentMissions(); break;}
		}
	}
}



void missionInfoMenu(int mission_choice, int from_which_menu, int function_employee_id, int function_vehicle_id){

	system("CLS");

	cout << "===============================================\n";
	cout << "                 DANE     MISJI";
	cout << "\n===============================================\n\n";

	cout << "Pracownik wykonujacy misje: ";
	listaPracownikow.at(function_employee_id)->getEmployeeName();
	cout << " ";
	listaPracownikow.at(function_employee_id)->getEmployeeSurname();

	cout << "\nUzywany pojazd: ";
	listaPojazdow.at(function_vehicle_id)->getVehicleBrand();
	cout << " ";
	listaPojazdow.at(function_vehicle_id)->getVehicleModel();

	cout << "\n\n\nZ: ";
	listaMisji.at(mission_choice)->getMissionStartingPoint();
	cout << "\nDo: ";
	listaMisji.at(mission_choice)->getMissionEndPoint();


	int speed = rand()%200;

	cout << "\n\nAktualna predkosc: ";

	if (speed<50) {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);}
	else if (speed>50 && speed<90) {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);}
	else {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);}

	cout << speed << " km/h";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	cout << "\n\n\nOdleglosc: ";
	listaMisji.at(mission_choice)->getMissionDistance();
	cout << " km";


	cout << "\n\n0. Powrot";

	char choice;

	bool poprawna = false;

	while(poprawna == false){

		choice = getch();

		switch (choice){

		case '0': {

			if(from_which_menu==1){

				poprawna = true;
				system("CLS");

				int id_acquired;
				int id_wanted;

				listaPojazdow.at(function_vehicle_id)->saveVehicleID(&id_acquired);

				for (unsigned int i=0; i < uzywanePojazdy.size(); i++){

					uzywanePojazdy.at(i)->saveVehicleID(&id_wanted);

					if (id_acquired == id_wanted) {id_wanted = i; break;}

				}

				vehicleInfoMenu(id_wanted, 1);
				break;
			}

			else {poprawna = true; system("CLS"); employeePersonalMenu(function_employee_id); break;}
		}

		}
	}
}



#endif /* MISSIONINFOMENU_H_ */
