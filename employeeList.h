#ifndef EMPLOYEELIST_H_
#define EMPLOYEELIST_H_

#include <iostream>

using namespace std;

extern vector <Employee*> listaPracownikow;

extern void employeemenu();
extern void employeePersonalMenu(int);

void employeeList(){

	system("CLS");

	int employee_choice;

	for(unsigned int i=0; i<listaPracownikow.size(); i++){
		cout << i+1 << ". ";
		listaPracownikow.at(i)->getEmployeeName();
		cout << " ";
		listaPracownikow.at(i)->getEmployeeSurname();
		cout << "\n\n";

	}

	cout << "\n\n\n\nWybierz pracownika (0 - powrot) : ";
	cin >> employee_choice;

	if (employee_choice == 0) {system("CLS"); employeemenu();}

	else {employeePersonalMenu(employee_choice-1);}
}



#endif /* EMPLOYEELIST_H_ */
