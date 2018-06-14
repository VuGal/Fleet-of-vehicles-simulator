#ifndef EMPLOYEELIST_H_
#define EMPLOYEELIST_H_

#include <iostream>

using namespace std;

extern int employee_choice_remote;
extern int employeesCount;

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

	string employee_choice_string; int employee_choice, count=1;

	for(unsigned int i=0; i<wolniPracownicy.size(); i++){

			cout << count << ". ";
			wolniPracownicy.at(i)->getEmployeeName();
			cout << " ";
			wolniPracownicy.at(i)->getEmployeeSurname();
			count++;
			cout << "\n\n";

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

			int id_acquired; string name_acquired, surname_acquired; double salary_acquired;

			wolniPracownicy.at(employee_choice-1)->saveEmployeeID(&id_acquired);
			wolniPracownicy.at(employee_choice-1)->saveEmployeeName(&name_acquired);
			wolniPracownicy.at(employee_choice-1)->saveEmployeeSurname(&surname_acquired);
			wolniPracownicy.at(employee_choice-1)->saveEmployeeSalary(&salary_acquired);

			wolniPracownicy.erase(wolniPracownicy.begin()+(employee_choice-1));

			for(unsigned int j=0; j<listaPracownikow.size(); j++)
			{
				int id_acquired_2;

				listaPracownikow.at(j)->saveEmployeeID(&id_acquired_2);

				if (id_acquired == id_acquired_2){
					listaPracownikow.erase(listaPracownikow.begin()+j);
					employeesCount--;
				}
			}


			Employee* v3 = new Employee();

			v3->setEmployeeID(id_acquired);
			v3->setEmployeeIsBusy(1);
			v3->setEmployeeName(name_acquired);
			v3->setEmployeeSurname(surname_acquired);
			v3->setEmployeeSalary(salary_acquired);

			zajeciPracownicy.push_back(v3);
			listaPracownikow.push_back(v3);

			system("CLS");
			return(id_acquired);

		}

		else {cout << "\n\nNiepoprawny wybor. Wybierz pracownika: "; continue;}
	}
}

#endif /* EMPLOYEELIST_H_ */
