#ifndef AVAILABLEVEHICLES_H_
#define AVAILABLEVEHICLES_H_

#include <iostream>

using namespace std;

extern vector <Vehicle*> listaPojazdow;

void availableVehicles(){

	system("CLS");

	bool isTaken;
	int count = 1;
	int vehicle_choice;

	for(unsigned int i=0; i<listaPojazdow.size(); i++){

		listaPojazdow.at(i)->saveVehicleIsTaken(&isTaken);

		if(isTaken==0){
			cout << count << ". ";
			listaPojazdow.at(i)->getVehicleBrand();
			cout << " ";
			listaPojazdow.at(i)->getVehicleModel();
			cout << "\n";
			count++;
		}
	}

	cout << "\n\n\n\nWybierz samochod: ";
	cin >> vehicle_choice;

};

#endif /* AVAILABLEVEHICLES_H_ */
