#ifndef CLASSES_H_
#define CLASSES_H_

#include <iostream>

using namespace std;

extern int vehiclesCount;

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
		void getVehicleType();
		void getVehicleBrand();
		void getVehicleModel();
		void getVehicleEngine();
		void getVehicleEquipment();

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



#endif /* CLASSES_H_ */
