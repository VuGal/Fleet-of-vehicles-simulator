#ifndef AVAILABLEVEHICLES_H_
#define AVAILABLEVEHICLES_H_

#include <iostream>

using namespace std;

extern vector <Vehicle*> listaPojazdow;
extern vector <Vehicle*> wolnePojazdy;

extern void vehicleInfoMenu(int, int);

extern int vehiclesCount;

void availableVehicles(){

	system("CLS");

	int count = 1;

	for(unsigned int i=0; i<wolnePojazdy.size(); i++){
		{
			cout << i+1 << ". ";
			wolnePojazdy.at(i)->getVehicleBrand();
			cout << " ";
			wolnePojazdy.at(i)->getVehicleModel();
			cout << "\n";
			count++;
		}
	}

	cout << "\n\n\n\nWybierz samochod i nacisnij ENTER (0 - powrot) : ";

	string vehicle_choice_string; int vehicle_choice; bool poprawna = false;

		while(poprawna == false){

				cin >> vehicle_choice_string;

				try {
				vehicle_choice = stoi(vehicle_choice_string);
				}

				catch(invalid_argument iaex) {cout << "\n\nNiepoprawny wybor. Wybierz samochod (0 - powrot) : "; continue;}

				if(vehicle_choice < count && vehicle_choice > -1){
					poprawna = true;
				}

				else {cout << "\n\nNiepoprawny wybor. Wybierz samochod (0 - powrot) : "; continue;}
			}

	if(vehicle_choice == 0) {system("CLS"); vehiclemenu();}
	else{vehicleInfoMenu(vehicle_choice-1, 2);}

}

int availableVehicles(int is_int){

	system("CLS");

	int count = 1;

	for(unsigned int i=0; i<wolnePojazdy.size(); i++){
		{
			cout << i+1 << ". ";
			wolnePojazdy.at(i)->getVehicleBrand();
			cout << " ";
			wolnePojazdy.at(i)->getVehicleModel();
			cout << "\n";
			count++;
		}
	}

	cout << "\n\n\n\nWybierz samochod: ";

	string vehicle_choice_string; int vehicle_choice; bool poprawna = false;

			while(poprawna == false){

					cin >> vehicle_choice_string;

					try {
					vehicle_choice = stoi(vehicle_choice_string);
					}

					catch(invalid_argument iaex) {cout << "\n\nNiepoprawny wybor. Wybierz samochod: "; continue;}

					if(vehicle_choice < count && vehicle_choice > 0){
						poprawna = true;
					}

					else {cout << "\n\nNiepoprawny wybor. Wybierz samochod: "; continue;}
				}

	int id_acquired, type_acquired;
	string brand_acquired, model_acquired, engine_acquired, equipment_acquired;

	wolnePojazdy.at(vehicle_choice-1)->saveVehicleID(&id_acquired);
	wolnePojazdy.at(vehicle_choice-1)->saveVehicleType(&type_acquired);
	wolnePojazdy.at(vehicle_choice-1)->saveVehicleBrand(&brand_acquired);
	wolnePojazdy.at(vehicle_choice-1)->saveVehicleModel(&model_acquired);
	wolnePojazdy.at(vehicle_choice-1)->saveVehicleEngine(&engine_acquired);
	wolnePojazdy.at(vehicle_choice-1)->saveVehicleEquipment(&equipment_acquired);

	wolnePojazdy.erase(wolnePojazdy.begin()+vehicle_choice-1);

	for(unsigned int j=0; j<listaPojazdow.size(); j++)
				{
					int id_acquired_2;

					listaPojazdow.at(j)->saveVehicleID(&id_acquired_2);

					if (id_acquired == id_acquired_2){

						listaPojazdow.erase(listaPojazdow.begin()+j);
						vehiclesCount--;

					}
				}

	Vehicle* v3 = new Vehicle();

	v3->setVehicleID(id_acquired);
	v3->setVehicleType(type_acquired);
	v3->setVehicleIsTaken(1);
	v3->setVehicleBrand(brand_acquired);
	v3->setVehicleModel(model_acquired);
	v3->setVehicleEngine(engine_acquired);
	v3->setVehicleEquipment(equipment_acquired);

	uzywanePojazdy.push_back(v3);
	listaPojazdow.push_back(v3);

	system("CLS");

	return(id_acquired);

}

#endif /* AVAILABLEVEHICLES_H_ */
