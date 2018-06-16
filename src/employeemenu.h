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

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "               1. Lista pracownikow\n\n\n\n\n\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "               2. Dodaj pracownika\n\n\n\n\n\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "               3. Powrot\n\n\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	cout << "Wybierz opcje: ";

	char employee_menu_choice;

		bool poprawna = false;

		while(poprawna == false){

			employee_menu_choice = getch();

			switch (employee_menu_choice){

			case '1': {poprawna = true; employeeList(); break;}

			case '2': {poprawna = true; addEmployee(); employeemenu(); break;}

			case '3': {poprawna = true; system("CLS"); mainmenu(); break;}
			}
		}
}

#endif /* EMPLOYEEMENU_H_ */
