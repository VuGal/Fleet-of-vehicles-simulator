#ifndef TAKENVEHICLES_H_
#define TAKENVEHICLES_H_

#include <iostream>

using namespace std;

extern vector <Vehicle*> listaPojazdow;
extern vector <Vehicle*> uzywanePojazdy;

extern void vehicleInfoMenu(int, int);

void takenVehicles(){

	system("CLS");

	int vehicle_choice;

	for(unsigned int i=0; i<uzywanePojazdy.size(); i++){
{
			cout << i+1 << ". ";
			uzywanePojazdy.at(i)->getVehicleBrand();
			cout << " ";
			uzywanePojazdy.at(i)->getVehicleModel();
			cout << "\n";
		}
	}

	cout << "\n\n\n\nWybierz samochod (0 - powrot) : ";
	cin >> vehicle_choice;

	if(vehicle_choice == 0) {system("CLS"); vehiclemenu();}
	else{vehicleInfoMenu(vehicle_choice-1, 1);}


};

#endif /* TAKENVEHICLES_H_ */
