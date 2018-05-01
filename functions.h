#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include "classes.h"

using namespace std;

extern int vehiclesCount;
extern int employeesCount;

extern vector <Vehicle*> listaPojazdow;
extern vector <Employee*> listaPracownikow;

void loadVehicleList(){

	bool isEmpty;

	ifstream check_if_empty("Pojazdy.txt",ios::ate);
	check_if_empty.open("Pojazdy.txt");
	if(check_if_empty.tellg() == 0) {isEmpty = 1;}
	else {isEmpty = 0;}
	check_if_empty.close();

	ifstream fin;
	fin.open("Pojazdy.txt");

	if(isEmpty==0){

		int id, type; bool isTaken; string brand, model, engine, equipment;

		while(fin >> id >> isTaken >> type >> brand >> model >> engine >> equipment){

			Vehicle* v1 = new Vehicle(id, isTaken);

			v1->setVehicleType(type);
			v1->setVehicleBrand(brand);
			v1->setVehicleModel(model);
			v1->setVehicleEngine(engine);
			v1->setVehicleEquipment(equipment);

			listaPojazdow.push_back(v1);
		}
	}

	fin.close();

}

void saveVehicleList(){

	ofstream fout;
	fout.open("Pojazdy.txt");

	if(fout.is_open()) {cout << "Otwarto plik.\n";}

	int id, type; bool isTaken; string brand, model, engine, equipment;

	for(unsigned int i = 0; i < listaPojazdow.size(); i++){

		listaPojazdow.at(i)->saveVehicleID(&id);
		listaPojazdow.at(i)->saveVehicleType(&type);
		listaPojazdow.at(i)->saveVehicleIsTaken(&isTaken);
		listaPojazdow.at(i)->saveVehicleBrand(&brand);
		listaPojazdow.at(i)->saveVehicleModel(&model);
		listaPojazdow.at(i)->saveVehicleEngine(&engine);
		listaPojazdow.at(i)->saveVehicleEquipment(&equipment);

		fout << id << " " << isTaken << " " << type << " " << brand << " " << model << " " << engine << " " << equipment << "\n";
	}

	fout.close();

}

void addVehicle(){

	system("CLS");

	Vehicle* v1 = new Vehicle();

	int type; string brand, model, engine, equipment;

	v1->setVehicleID(vehiclesCount);
	v1->setVehicleIsTaken(0);

	cout << "Okresl typ pojazdu (1-osobowy; 2-ciezarowy): "; cin >> type; v1->setVehicleType(type);
	cout << "Podaj marke pojazdu: "; cin >> brand; v1->setVehicleBrand(brand);
	cout << "Podaj model pojazdu: "; cin >> model; v1->setVehicleModel(model);
	cout << "Podaj silnik: "; cin >> engine; v1->setVehicleEngine(engine);
	cout << "Podaj wyposazenie pojazdu: "; cin >> equipment; v1->setVehicleEquipment(equipment);

	listaPojazdow.push_back(v1);

	system("CLS");
}

void loadEmployeeList(){

	bool isEmpty;

	ifstream check_if_empty("Pracownicy.txt",ios::ate);
	check_if_empty.open("Pracownicy.txt");
	if(check_if_empty.tellg() == 0) {isEmpty = 1;}
	else {isEmpty = 0;}
	check_if_empty.close();

	ifstream fin;
	fin.open("Pracownicy.txt");

	if(isEmpty==0){

		int id; bool isBusy; string name, surname; double salary;

		while(fin >> id >> isBusy >> name >> surname >> salary) {

			Employee* v1 = new Employee(id, isBusy);

			v1->setEmployeeName(name);
			v1->setEmployeeSurname(surname);
			v1->setEmployeeSalary(salary);

			listaPracownikow.push_back(v1);
		}
	}

	fin.close();
}

void saveEmployeeList(){

	ofstream fout;
	fout.open("Pracownicy.txt");

	if(fout.is_open()) {cout << "Otwarto plik.\n";}

	int id; bool isBusy; string name, surname; double salary;

	for(unsigned int i = 0; i < listaPracownikow.size(); i++){

		listaPracownikow.at(i)->saveEmployeeID(&id);
		listaPracownikow.at(i)->saveEmployeeIsBusy(&isBusy);
		listaPracownikow.at(i)->saveEmployeeName(&name);
		listaPracownikow.at(i)->saveEmployeeSurname(&surname);
		listaPracownikow.at(i)->saveEmployeeSalary(&salary);

		fout << id << " " << isBusy << " " << name << " " << surname << " " << salary << "\n";
	}

	fout.close();

}

void addEmployee(){

	system("CLS");

	Employee* v1 = new Employee();

	int id; bool isBusy; string name, surname; double salary;

	v1->setEmployeeID(employeesCount);
	v1->setEmployeeIsBusy(0);

	cout << "Podaj imie pracownika: "; cin >> name; v1->setEmployeeName(name);
	cout << "Podaj nazwisko pracownika: "; cin >> surname; v1->setEmployeeSurname(surname);
	cout << "Podaj zarobki pracownika: "; cin >> salary; v1->setEmployeeSalary(salary);
	listaPracownikow.push_back(v1);

	system("CLS");
}


void exitProgram(){
	saveVehicleList();
	saveEmployeeList();
	exit(1);
}

#endif /* FUNCTIONS_H_ */
