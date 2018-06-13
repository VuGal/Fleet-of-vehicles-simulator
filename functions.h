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
extern int missionsCount;

extern vector <Vehicle*> listaPojazdow;
extern vector <Employee*> listaPracownikow;
extern vector <Mission*> listaMisji;

extern vector <Vehicle*> wolnePojazdy;
extern vector <Vehicle*> uzywanePojazdy;

extern vector <Employee*> wolniPracownicy;
extern vector <Employee*> zajeciPracownicy;

extern void employeeList();
extern int employeeList(int);
extern int availableVehicles(int);

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

	string name, surname; double salary;

	v1->setEmployeeID(employeesCount);
	v1->setEmployeeIsBusy(0);

	cout << "Podaj imie pracownika: "; cin >> name; v1->setEmployeeName(name);
	cout << "Podaj nazwisko pracownika: "; cin >> surname; v1->setEmployeeSurname(surname);
	cout << "Podaj zarobki pracownika: "; cin >> salary; v1->setEmployeeSalary(salary);
	listaPracownikow.push_back(v1);

	system("CLS");
}

void categorizeVehicles(){

		bool isTaken;

		int id, type; string brand, model, engine, equipment;

		for(unsigned int i=0; i<listaPojazdow.size(); i++){

			listaPojazdow.at(i)->saveVehicleIsTaken(&isTaken);

			if(isTaken==0){

				Vehicle* v2 = new Vehicle(isTaken);

				v2->setVehicleIsTaken(0);

				listaPojazdow.at(i)->saveVehicleID(&id);
				v2->setVehicleID(id);

				listaPojazdow.at(i)->saveVehicleType(&type);
				v2->setVehicleType(type);

				listaPojazdow.at(i)->saveVehicleBrand(&brand);
				v2->setVehicleBrand(brand);

				listaPojazdow.at(i)->saveVehicleModel(&model);
				v2->setVehicleModel(model);

				listaPojazdow.at(i)->saveVehicleEngine(&engine);
				v2->setVehicleEngine(engine);

				listaPojazdow.at(i)->saveVehicleEquipment(&equipment);
				v2->setVehicleEquipment(equipment);

				wolnePojazdy.push_back(v2);
			}

			else {

				Vehicle* v2 = new Vehicle(isTaken);

				v2->setVehicleIsTaken(1);

				listaPojazdow.at(i)->saveVehicleID(&id);
				v2->setVehicleID(id);

				listaPojazdow.at(i)->saveVehicleType(&type);
				v2->setVehicleType(type);

				listaPojazdow.at(i)->saveVehicleBrand(&brand);
				v2->setVehicleBrand(brand);

				listaPojazdow.at(i)->saveVehicleModel(&model);
				v2->setVehicleModel(model);

				listaPojazdow.at(i)->saveVehicleEngine(&engine);
				v2->setVehicleEngine(engine);

				listaPojazdow.at(i)->saveVehicleEquipment(&equipment);
				v2->setVehicleEquipment(equipment);

				uzywanePojazdy.push_back(v2);
			}
		}
}


void loadMissionList(){

		bool isEmpty;

		ifstream check_if_empty("Misje.txt", ios::ate);
		check_if_empty.open("Misje.txt");
		if(check_if_empty.tellg() == 0) {isEmpty = 1;}
		else {isEmpty = 0;}
		check_if_empty.close();

		ifstream fin;
		fin.open("Misje.txt");

		if(isEmpty==0){

			int employee_id, vehicle_id; string starting_point, end_point; double distance;

			while(fin >> employee_id >> vehicle_id >> starting_point >> end_point >> distance){

				Mission* v1 = new Mission();

				v1->setMissionEmployeeID(employee_id);
				v1->setMissionVehicleID(vehicle_id);
				v1->setMissionStartingPoint(starting_point);
				v1->setMissionEndPoint(end_point);
				v1->setMissionDistance(distance);

				listaMisji.push_back(v1);
			}
		}

		fin.close();
}

void saveMissionList(){

		ofstream fout;
		fout.open("Misje.txt");

		int employee_id, vehicle_id; string starting_point, end_point; double distance;

		for(unsigned int i = 0; i < listaMisji.size(); i++){

			listaMisji.at(i)->saveMissionEmployeeID(&employee_id);
			listaMisji.at(i)->saveMissionVehicleID(&vehicle_id);
			listaMisji.at(i)->saveMissionStartingPoint(&starting_point);
			listaMisji.at(i)->saveMissionEndPoint(&end_point);
			listaMisji.at(i)->saveMissionDistance(&distance);

			fout << employee_id << " " << vehicle_id << " " << starting_point << " " << end_point << " " << distance << "\n";
		}

		fout.close();

}

void addMission(){

	system("CLS");

	Mission* v1 = new Mission();

	string starting_point, end_point; double distance;


	cout << "Wybierz pracownika: ";

	int employee_choice_remote;

	employee_choice_remote = employeeList(1);

	v1->setMissionEmployeeID(employee_choice_remote);



	cout << "Wybierz pojazd: ";

	int vehicle_choice_remote;

	vehicle_choice_remote = availableVehicles(1);

	v1->setMissionVehicleID(vehicle_choice_remote);



	cout << "\nPodaj punkt poczatkowy: "; cin >> starting_point; v1->setMissionStartingPoint(starting_point);
	cout << "Podaj punkt docelowy: "; cin >> end_point; v1->setMissionEndPoint(end_point);
	v1->setMissionDistance(100);


	listaMisji.push_back(v1);

	system("CLS");
}

void exitProgram(){
	saveVehicleList();
	saveEmployeeList();
	saveMissionList();
	exit(1);
}

#endif /* FUNCTIONS_H_ */
