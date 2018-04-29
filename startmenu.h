#ifndef STARTMENU_H_
#define STARTMENU_H_

#include <iostream>

using namespace std;

extern int start_menu_choice;

extern void mainmenu();

void startmenu(){

	cout << "-------------------------------------------------------------------------------\n";
	cout << "-------------------    SYMULATOR FLOTY POJAZDOW v. 0.3      -------------------\n";
	cout << "-------------------------------------------------------------------------------\n";
	cout << "-------------------------------------------------------------------------------\n";
	cout << "--------    Autorzy: Galecki Wojciech, Lis Monika, Przybylo Wojciech    -------\n";
	cout << "-------------------------------------------------------------------------------\n";
	cout << "-------------------------------------------------------------------------------\n\n";

	cout << "          1. Uruchom program\n\n";
	cout << "          2. O projekcie\n\n";
	cout << "          3. Wyjscie\n\n\n\n";

	cout << "Wybierz opcje: ";
	cin >> start_menu_choice;
	cout << "\n";

	bool poprawna = false;

	while(poprawna == false){

		switch (start_menu_choice){

		case 1: {poprawna = true; system("CLS"); mainmenu(); break;}

		case 2:
		{poprawna = true;
		system("CLS");
		cout << "Projekt symuluje dzialanie systemu kontrolujacego flote pojazdow.\n\nNacisnij dowolny klawisz, aby powrocic do menu glownego.";
		getch();
		system("CLS");
		startmenu();
		break;}

		case 3: {exit(1);}

		default: {cout << "Wybrano niepoprawna opcje.\n\nWybierz opcje: "; cin >> start_menu_choice; cout << "\n";}
		}
	}
}

#endif /* STARTMENU_H_ */
