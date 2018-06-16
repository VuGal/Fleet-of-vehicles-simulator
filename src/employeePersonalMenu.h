#ifndef EMPLOYEEPERSONALMENU_H_
#define EMPLOYEEPERSONALMENU_H_

#include <iostream>
#include "classes.h"

using namespace std;

extern void missionInfoMenu(int, int, int, int);

extern vector <Mission*> listaMisji;

bool isBusy;

void employeePersonalMenu(int employee_choice){

	system("CLS");

	listaPracownikow.at(employee_choice)->saveEmployeeIsBusy(&isBusy);

	if (isBusy == 0){

	cout << "===============================================\n";
	cout << "           ";
	listaPracownikow.at(employee_choice)->getEmployeeName();
	cout << "      ";
	listaPracownikow.at(employee_choice)->getEmployeeSurname();
	cout << "\n===============================================\n\n";

	cout << "Zarobki: "; listaPracownikow.at(employee_choice)->getEmployeeSalary();

	cout << "\nAKTUALNIE W TRASIE: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "NIE";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);


	cout << "\n\n\n\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED| FOREGROUND_INTENSITY);
	cout << "1. Powrot\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	char choice;

			bool poprawna = false;

			while(poprawna == false){

				choice = getch();

				switch (choice){

				case '1': {poprawna = true; system("CLS"); employeeList(); break;}
				}
			}
	}


	else {

	cout << "===============================================\n";
	cout << "           ";
	listaPracownikow.at(employee_choice)->getEmployeeName();
	cout << "      ";
	listaPracownikow.at(employee_choice)->getEmployeeSurname();
	cout << "\n===============================================\n\n";

	cout << "Zarobki: "; listaPracownikow.at(employee_choice)->getEmployeeSalary();

	cout << "\nAKTUALNIE W TRASIE: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "TAK";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	cout << "\n\n\n\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "1. Wyswietl dane aktualnej misji\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "2. Powrot";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	char choice;

			bool poprawna = false;

			while(poprawna == false){

				choice = getch();

				switch (choice){

				case '1': {
					poprawna = true;

					int mission_choice_remote;
					int function_employee_id_remote;
					int function_vehicle_id_remote;

					if(listaMisji.size() !=0){
						for (unsigned int i=0; i<listaMisji.size(); i++){
							listaMisji.at(i)->saveMissionEmployeeID(&function_employee_id_remote);

							if((function_employee_id_remote-1) == employee_choice) {

								function_employee_id_remote = employee_choice;
								mission_choice_remote = i; break;

							}
						}

						listaMisji.at(mission_choice_remote)->saveMissionVehicleID(&function_vehicle_id_remote);

						missionInfoMenu(mission_choice_remote, 2, function_employee_id_remote, function_vehicle_id_remote-1);
						break;
					}

					else {cout << "Pusta lista misji (nie powinno tak byc)."; break;}
				}


				case '2': {poprawna = true; system("CLS"); employeeList(); break;}
				}
			}
	}
}



#endif /* EMPLOYEEPERSONALMENU_H_ */
