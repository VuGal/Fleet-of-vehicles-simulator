#ifndef CLASSES_H_
#define CLASSES_H_

#include <iostream>

using namespace std;

extern int vehiclesCount;
extern int employeesCount;
extern int missionsCount;

class Vehicle{

	public:
		Vehicle();
		Vehicle(int);
		Vehicle(bool);
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

		//sending private variables to other variables in program
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

// ----------------------------------------------------------

void Vehicle::getVehicleID(){
	cout << id_;
}

void Vehicle::getVehicleIsTaken(){
	cout << isTaken_;
}

void Vehicle::getVehicleType(){
	cout << type_;
}

void Vehicle::getVehicleBrand(){
	cout << brand_;
}

void Vehicle::getVehicleModel(){
	cout << model_;
}

void Vehicle::getVehicleEngine(){
	cout << engine_ << "\n";
}

void Vehicle::getVehicleEquipment(){
	cout << equipment_ << "\n";
}

// ----------------------------------------------------------

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

// ----------------------------------------------------------

Vehicle::Vehicle(){
	vehiclesCount++;
}

Vehicle::Vehicle(bool isTaken){} //for categorizeVehicles() - it shouldn't increment count


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

		//sending private variables to other variables in program
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

// ----------------------------------------------------------

void Employee::getEmployeeID(){
	cout << id_;
}

void Employee::getEmployeeIsBusy(){
	cout << isBusy_;
}

void Employee::getEmployeeName(){
	cout << name_;
}

void Employee::getEmployeeSurname(){
	cout << surname_;
}

void Employee::getEmployeeSalary(){
	cout << salary_ ;
}

// ----------------------------------------------------------

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

// ----------------------------------------------------------

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





class Mission {

public:

	Mission();

	//setters
	void setMissionEmployeeID(int);
	void setMissionVehicleID(int);
	void setMissionStartingPoint(string);
	void setMissionEndPoint(string);
	void setMissionDistance(double);

	//getters
	void getMissionEmployeeID();
	void getMissionVehicleID();
	void getMissionStartingPoint();
	void getMissionEndPoint();
	void getMissionDistance();

	//sending private variables to other variables in program
	void saveMissionEmployeeID(int*);
	void saveMissionVehicleID(int*);
	void saveMissionStartingPoint(string*);
	void saveMissionEndPoint(string*);
	void saveMissionDistance(double*);

private:

	int employee_id_;
	int vehicle_id_;

	string starting_point_;
	string end_point_;

	double distance_;
};

void Mission::setMissionEmployeeID(int employee_id){
	employee_id_ = employee_id;
}

void Mission::setMissionVehicleID(int vehicle_id){
	vehicle_id_ = vehicle_id;
}

void Mission::setMissionStartingPoint(string starting_point){
	starting_point_ = starting_point;
}

void Mission::setMissionEndPoint(string end_point){
	end_point_ = end_point;
}

void Mission::setMissionDistance(double distance){
	distance_ = distance;
}

// ----------------------------------------------------------

void Mission::getMissionEmployeeID(){
	cout << employee_id_;
}

void Mission::getMissionVehicleID(){
	cout << vehicle_id_;
}

void Mission::getMissionStartingPoint(){
	cout << starting_point_;
}

void Mission::getMissionEndPoint(){
	cout << end_point_;
}

void Mission::getMissionDistance(){
	cout << distance_ ;
}

// ----------------------------------------------------------

void Mission::saveMissionEmployeeID(int* employee_id){
	*employee_id = employee_id_;
}

void Mission::saveMissionVehicleID(int* vehicle_id){
	*vehicle_id = vehicle_id_;
}

void Mission::saveMissionStartingPoint(string* starting_point){
	*starting_point = starting_point_;
}

void Mission::saveMissionEndPoint(string* end_point){
	*end_point = end_point_;
}

void Mission::saveMissionDistance(double* distance){
	*distance = distance_;
}

// ----------------------------------------------------------

Mission::Mission(){
	missionsCount++;
}



#endif /* CLASSES_H_ */
