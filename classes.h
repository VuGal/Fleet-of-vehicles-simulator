#ifndef CLASSES_H_
#define CLASSES_H_

#include <iostream>

using namespace std;

extern int vehiclesCount;
extern int employeesCount;

class Vehicle{

	public:
		Vehicle();
		Vehicle(int);
		Vehicle(int, bool);

		//setters
		void setVehicleID(int);
		void setVehicleType(int);
		void setVehicleBrand(string);
		void setVehicleModel(string);
		void setVehicleEngine(string);
		void setVehicleEquipment(string);
		void setVehicleIsTaken(bool);

		//getters
		void getVehicleID();
		void getVehicleIsTaken();
		void getVehicleType();
		void getVehicleBrand();
		void getVehicleModel();
		void getVehicleEngine();
		void getVehicleEquipment();

		//for saving to files
		void saveVehicleID(int*);
		void saveVehicleIsTaken(bool*);
		void saveVehicleType(int*);
		void saveVehicleBrand(string*);
		void saveVehicleModel(string*);
		void saveVehicleEngine(string*);
		void saveVehicleEquipment(string*);

	private:
		int id_;
		int type_;

		bool isTaken_;

		string brand_;
		string model_;
		string engine_;
		string equipment_;
};

void Vehicle::setVehicleID(int id){
	id_ = id;
}

void Vehicle::setVehicleType(int type){
	type_ = type;
}

void Vehicle::setVehicleBrand(string brand){
	brand_ = brand;
}

void Vehicle::setVehicleModel(string model){
	model_ = model;
}

void Vehicle::setVehicleEngine(string engine){
	engine_ = engine;
}

void Vehicle::setVehicleEquipment(string equipment){
	equipment_ = equipment;
}

void Vehicle::setVehicleIsTaken(bool isTaken){
	isTaken_ = isTaken;
}

void Vehicle::getVehicleID(){
	cout << id_ << "\n";
}

void Vehicle::getVehicleIsTaken(){
	cout << isTaken_ << "\n";
}

void Vehicle::getVehicleType(){
	cout << type_ << "\n";
}

void Vehicle::getVehicleBrand(){
	cout << brand_ << "\n";
}

void Vehicle::getVehicleModel(){
	cout << model_ << "\n";
}

void Vehicle::getVehicleEngine(){
	cout << engine_ << "\n";
}

void Vehicle::getVehicleEquipment(){
	cout << equipment_ << "\n";
}

void Vehicle::saveVehicleID(int* id){
	*id = id_;
}

void Vehicle::saveVehicleIsTaken(bool* isTaken){
	*isTaken = isTaken_;
}

void Vehicle::saveVehicleType(int* type){
	*type = type_;
}

void Vehicle::saveVehicleBrand(string* brand){
	*brand = brand_;
}

void Vehicle::saveVehicleModel(string* model){
	*model = model_;
}

void Vehicle::saveVehicleEngine(string* engine){
	*engine = engine_;
}

void Vehicle::saveVehicleEquipment(string* equipment){
	*equipment = equipment_;
}

Vehicle::Vehicle(){
	vehiclesCount++;
}


Vehicle::Vehicle(int id){
	id_ = id;
	isTaken_ = false;
	cout << "Dodano nowy pojazd do bazy.\n";
	vehiclesCount++;
}

Vehicle::Vehicle(int id, bool isTaken){
	id_ = id;
	isTaken_ = isTaken;
	vehiclesCount++;
}

class Car: public Vehicle{

	bool isEnglish;
};

class Truck: public Vehicle{

	public:
		double capacity;
};

class Employee{

	public:
		Employee();
		Employee(int);
		Employee(int, bool);

		//setters
		void setEmployeeID(int);
		void setEmployeeIsBusy(bool);
		void setEmployeeName(string);
		void setEmployeeSurname(string);
		void setEmployeeSalary(double);

		//getters
		void getEmployeeID();
		void getEmployeeIsBusy();
		void getEmployeeName();
		void getEmployeeSurname();
		void getEmployeeSalary();

		//for saving to files
		void saveEmployeeID(int*);
		void saveEmployeeIsBusy(bool*);
		void saveEmployeeName(string*);
		void saveEmployeeSurname(string*);
		void saveEmployeeSalary(double*);

	private:
		int id_;

		bool isBusy_;

		string name_;
		string surname_;

		double salary_;
};

void Employee::setEmployeeID(int id){
	id_ = id;
}

void Employee::setEmployeeIsBusy(bool isBusy){
	isBusy_ = isBusy;
}

void Employee::setEmployeeName(string name){
	name_ = name;
}

void Employee::setEmployeeSurname(string surname){
	surname_ = surname;
}

void Employee::setEmployeeSalary(double salary){
	salary_ = salary;
}



void Employee::getEmployeeID(){
	cout << id_ << "\n";
}

void Employee::getEmployeeIsBusy(){
	cout << isBusy_ << "\n";
}

void Employee::getEmployeeName(){
	cout << name_ << "\n";
}

void Employee::getEmployeeSurname(){
	cout << surname_ << "\n";
}

void Employee::getEmployeeSalary(){
	cout << salary_ << "\n";
}



void Employee::saveEmployeeID(int* id){
	*id = id_;
}

void Employee::saveEmployeeIsBusy(bool* isBusy){
	*isBusy = isBusy_;
}

void Employee::saveEmployeeName(string* name){
	*name = name_;
}

void Employee::saveEmployeeSurname(string* surname){
	*surname = surname_;
}

void Employee::saveEmployeeSalary(double* salary){
	*salary = salary_;
}



Employee::Employee(){
	employeesCount++;
}


Employee::Employee(int id){
	id_ = id;
	isBusy_ = false;
	cout << "Dodano nowego pracownika do bazy.\n";
	employeesCount++;
}

Employee::Employee(int id, bool isBusy){
	id_ = id;
	isBusy_ = isBusy;
	employeesCount++;
}


#endif /* CLASSES_H_ */
