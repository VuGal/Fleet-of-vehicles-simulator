#ifndef MAINMENU_H_
#define MAINMENU_H_

#include <iostream>
#include <cstdlib>
using namespace std;

extern char main_menu_choice;

extern void startmenu();
extern void vehiclemenu();
extern void employeemenu();
extern void missionmenu();

void mainmenu(){

	cout << "================================================\n";
	cout << "============ PANEL ZARZADZANIA FLOTA ===========\n";
	cout << "================================================\n\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "               1. POJAZDY\n\n";
	cout << "               2. PRACOWNICY\n\n\n\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "               3. MISJE\n\n\n\n\n\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "               4. Powrot\n\n\n\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "Wybierz opcje: ";

	char main_menu_choice;

		bool poprawna = false;

		while(poprawna == false){

			main_menu_choice = getch();

			switch (main_menu_choice){

			case '1': {poprawna = true; system("CLS"); vehiclemenu(); break;}

			case '2': {poprawna = true; system("CLS"); employeemenu(); break;}

			case '3': {poprawna = true; system("CLS"); missionmenu(); break;}

			case '4': {poprawna = true; system("CLS"); startmenu(); break;}
			}
		}
}

#endif /* MAINMENU_H_ */
