#ifndef MAINMENU_H_
#define MAINMENU_H_

#include <iostream>
#include <cstdlib>
using namespace std;

extern int main_menu_choice;

extern void startmenu();
extern void vehiclemenu();
extern void employeemenu();

void mainmenu(){

	cout << "================================================\n";
	cout << "============ PANEL ZARZADZANIA FLOTA ===========\n";
	cout << "================================================\n\n";

	cout << "               1. POJAZDY\n\n";
	cout << "               2. PRACOWNICY\n\n\n\n\n\n";
	cout << "               3. Powrot\n\n\n\n";

	cout << "Wybierz opcje: ";
	cin >> main_menu_choice;

	cout << "\n";

		bool poprawna = false;

		while(poprawna == false){

			switch (main_menu_choice){

			case 1: {poprawna = true; system("CLS"); vehiclemenu(); break;}

			case 2: {poprawna = true; system("CLS"); employeemenu(); break;}

			case 3: {poprawna = true; system("CLS"); startmenu(); break;}

			default: {cout << "Wybrano niepoprawna opcje.\n\nWybierz opcje: "; cin >> main_menu_choice; cout << "\n";}
			}
		}
}

#endif /* MAINMENU_H_ */
