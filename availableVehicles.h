#ifndef AVAILABLEVEHICLES_H_
#define AVAILABLEVEHICLES_H_

#include <iostream>

using namespace std;

extern vector <Vehicle*> listaPojazdow;
extern vector <Vehicle*> wolnePojazdy;

extern void vehicleInfoMenu(int, int);

void availableVehicles(){

	system("CLS");

	int vehicle_choice;

	for(unsigned int i=0; i<wolnePojazdy.size(); i++){
		{
			cout << i+1 << ". ";
			wolnePojazdy.at(i)->getVehicleBrand();
			cout << " ";
			wolnePojazdy.at(i)->getVehicleModel();
			cout << "\n";
		}
	}

	cout << "\n\n\n\nWybierz samochod i nacisnij ENTER (0 - powrot) : ";
	cin >> vehicle_choice;

	if(vehicle_choice == 0) {system("CLS"); vehiclemenu();}
	else{vehicleInfoMenu(vehicle_choice-1, 2);}

}

int availableVehicles(int is_int){

	system("CLS");

	int vehicle_choice;

	for(unsigned int i=0; i<wolnePojazdy.size(); i++){
		{
			cout << i+1 << ". ";
			wolnePojazdy.at(i)->getVehicleBrand();
			cout << " ";
			wolnePojazdy.at(i)->getVehicleModel();
			cout << "\n";
		}
	}

	cout << "\n\n\n\nWybierz samochod: ";
	cin >> vehicle_choice;

	int id_acquired;
	string brand_acquired, model_acquired, engine_acquired, equipment_acquired;

	wolnePojazdy.at(vehicle_choice-1)->saveVehicleID(&id_acquired);
	wolnePojazdy.at(vehicle_choice-1)->saveVehicleBrand(&brand_acquired);
	wolnePojazdy.at(vehicle_choice-1)->saveVehicleModel(&model_acquired);
	wolnePojazdy.at(vehicle_choice-1)->saveVehicleEngine(&engine_acquired);
	wolnePojazdy.at(vehicle_choice-1)->saveVehicleEquipment(&equipment_acquired);

	wolnePojazdy.erase(wolnePojazdy.begin()+vehicle_choice-1);

	Vehicle* v3 = new Vehicle();

	v3->setVehicleID(id_acquired);
	v3->setVehicleBrand(brand_acquired);
	v3->setVehicleModel(model_acquired);
	v3->setVehicleEngine(engine_acquired);
	v3->setVehicleEquipment(equipment_acquired);

	uzywanePojazdy.push_back(v3);

	system("CLS");

	return(id_acquired);

}

#endif /* AVAILABLEVEHICLES_H_ */
