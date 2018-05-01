#ifndef EMPLOYEEMENU_H_
#define EMPLOYEEMENU_H_

#include <iostream>
#include <cstdio>

using namespace std;

extern void mainmenu();
extern void employeeList();

void employeemenu(){

	cout << "================================================\n";
	cout << "=========== ZARZADZANIE PRACOWNIKAMI ===========\n";
	cout << "================================================\n\n";

	cout << "               1. Lista pracownikow\n\n\n\n\n\n";


	cout << "               2. Dodaj pracownika\n\n\n\n\n\n";


	cout << "               3. Powrot\n\n\n\n";

	cout << "Wybierz opcje: ";

	int employee_menu_choice;

	cin >> employee_menu_choice;
	cout << "\n";

		bool poprawna = false;

		while(poprawna == false){

			switch (employee_menu_choice){

			case 1: {poprawna = true; employeeList(); break;}

			case 2: {poprawna = true; addEmployee(); employeemenu(); break;}

			case 3: {poprawna = true; system("CLS"); mainmenu(); break;}

			default: {cout << "Wybrano niepoprawna opcje.\n\nWybierz opcje: "; cin >> employee_menu_choice; cout << "\n";}
			}
		}
}

#endif /* EMPLOYEEMENU_H_ */
