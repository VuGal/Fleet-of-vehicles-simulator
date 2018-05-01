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

	cout << "\n\n\n\nWybierz samochod (0 - powrot) : ";
	cin >> vehicle_choice;

	if(vehicle_choice == 0) {system("CLS"); vehiclemenu();}
	else{vehicleInfoMenu(vehicle_choice-1, 2);}


};

#endif /* AVAILABLEVEHICLES_H_ */
