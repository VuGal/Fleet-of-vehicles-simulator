#ifndef EMPLOYEELIST_H_
#define EMPLOYEELIST_H_

#include <iostream>

using namespace std;

extern int employee_choice_remote;

extern vector <Employee*> listaPracownikow;

extern void employeemenu();
extern void employeePersonalMenu(int);

void employeeList(){

	system("CLS");

	int count = 1;

	for(unsigned int i=0; i<listaPracownikow.size(); i++){
		cout << i+1 << ". ";
		listaPracownikow.at(i)->getEmployeeName();
		cout << " ";
		listaPracownikow.at(i)->getEmployeeSurname();
		cout << "\n\n";
		count++;
	}


	cout << "\n\n\n\nWybierz pracownika i nacisnij ENTER (0 - powrot) : ";

	string employee_choice_string; int employee_choice; bool poprawna = false;

	while(poprawna == false){

			cin >> employee_choice_string;

			try {
			employee_choice = stoi(employee_choice_string);
			}

			catch(invalid_argument iaex) {cout << "\n\nNiepoprawny wybor. Wybierz pracownika (0 - powrot) : "; continue;}

			if(employee_choice < count && employee_choice > -1){
				poprawna = true;
			}

			else {cout << "\n\nNiepoprawny wybor. Wybierz pracownika (0 - powrot) : "; continue;}
		}

	if (employee_choice == 0) {system("CLS"); employeemenu();}

	else {employeePersonalMenu(employee_choice-1);}
}

int employeeList(int is_int){

	system("CLS");

	string employee_choice_string; int employee_choice, count=1; bool isBusy;

	for(unsigned int i=0; i<listaPracownikow.size(); i++){

		listaPracownikow.at(i)->saveEmployeeIsBusy(&isBusy);

		if(isBusy==0){
			cout << count << ". ";
			listaPracownikow.at(i)->getEmployeeName();
			cout << " ";
			listaPracownikow.at(i)->getEmployeeSurname();
			count++;
			cout << "\n\n";
		}

	}

	bool poprawna = false;

	cout << "\n\n\n\nWybierz pracownika: ";

	while(poprawna == false){

		cin >> employee_choice_string;

		try {
		employee_choice = stoi(employee_choice_string);
		}

		catch(invalid_argument iaex) {cout << "\n\nNiepoprawny wybor. Wybierz pracownika: "; continue;}

		if(employee_choice < count && employee_choice > 0){

			poprawna = true;
			system("CLS");
			return(employee_choice);

		}

		else {cout << "\n\nNiepoprawny wybor. Wybierz pracownika: "; continue;}
	}
}

#endif /* EMPLOYEELIST_H_ */
