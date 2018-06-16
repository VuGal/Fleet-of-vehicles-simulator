#ifndef TAKENVEHICLES_H_
#define TAKENVEHICLES_H_

#include <iostream>

using namespace std;

extern vector <Vehicle*> listaPojazdow;
extern vector <Vehicle*> uzywanePojazdy;

extern void vehicleInfoMenu(int, int);

void takenVehicles(){

	system("CLS");

	int count = 1;

	for(unsigned int i=0; i<uzywanePojazdy.size(); i++){
{
			cout << i+1 << ". ";
			uzywanePojazdy.at(i)->getVehicleBrand();
			cout << " ";
			uzywanePojazdy.at(i)->getVehicleModel();
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
	else{vehicleInfoMenu(vehicle_choice-1, 1);}

};

#endif /* TAKENVEHICLES_H_ */
