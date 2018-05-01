#ifndef EMPLOYEEPERSONALMENU_H_
#define EMPLOYEEPERSONALMENU_H_

#include <iostream>

using namespace std;

bool isBusy;

void employeePersonalMenu(int employee_choice){

	system("CLS");

	cout << "===============================================\n";
	cout << "           ";
	listaPracownikow.at(employee_choice)->getEmployeeName();
	cout << "      ";
	listaPracownikow.at(employee_choice)->getEmployeeSurname();
	cout << "\n===============================================\n\n";

	cout << "Zarobki: "; listaPracownikow.at(employee_choice)->getEmployeeSalary();

	cout << "\nAKTUALNIE W TRASIE: ";

	listaPracownikow.at(employee_choice)->saveEmployeeIsBusy(&isBusy);

	if (isBusy == 0) {cout << "Nie";}
	else {cout << "Tak";}

	cout << "\n\n\n\n";

	cout << "1. Powrot\n\n";

	int choice;

	cin >> choice;
		cout << "\n";

			bool poprawna = false;

			while(poprawna == false){

				switch (choice){

				case 1: {poprawna = true; system("CLS"); employeeList(); break;}

				default: {cout << "Wybrano niepoprawna opcje.\n\nWybierz opcje: "; cin >> choice; cout << "\n";}
				}
			}

}



#endif /* EMPLOYEEPERSONALMENU_H_ */
