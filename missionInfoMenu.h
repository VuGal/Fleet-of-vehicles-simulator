#ifndef MISSIONINFOMENU_H_
#define MISSIONINFOMENU_H_

#include <iostream>

using namespace std;

extern int mission_choice;
extern int from_which_menu; // 1-vehicleInfoMenu    2-employeePersonalMenu

extern vector <Employee*> listaPracownikow;
extern vector <Vehicle*> listaPojazdow;

extern void currentMissions();
extern void vehicleInfoMenu(int, int);
extern void employeePersonalMenu(int);

//from currentMissions()
void missionInfoMenu(int mission_choice){

	system("CLS");

	int function_employee_id, function_vehicle_id;

	listaMisji.at(mission_choice)->saveMissionEmployeeID(&function_employee_id);
	listaMisji.at(mission_choice)->saveMissionVehicleID(&function_vehicle_id);


	cout << "===============================================\n";
	cout << "                 DANE     MISJI";
	cout << "\n===============================================\n\n";

	cout << "Pracownik wykonujacy misje: ";
	listaPracownikow.at(function_employee_id-1)->getEmployeeName();
	cout << " ";
	listaPracownikow.at(function_employee_id-1)->getEmployeeSurname();

	cout << "\nUzywany pojazd: ";
	listaPojazdow.at(function_vehicle_id-1)->getVehicleBrand();
	cout << " ";
	listaPojazdow.at(function_vehicle_id-1)->getVehicleModel();

	cout << "\n\n\nZ: ";
	listaMisji.at(mission_choice)->getMissionStartingPoint();
	cout << "\nDo: ";
	listaMisji.at(mission_choice)->getMissionEndPoint();
	cout << "\n\n\nOdleglosc: ";
	listaMisji.at(mission_choice)->getMissionDistance();


	cout << "\n\n0. Powrot";

	int choice;

	cin >> choice;
	cout << "\n";

	bool poprawna = false;

	while(poprawna == false){

		switch (choice){

			case 0: {poprawna = true; system("CLS"); currentMissions(); break;}

			default: {cout << "Wybrano niepoprawna opcje.\n\nWybierz opcje: "; cin >> choice; cout << "\n";}
		}
	}
}



void missionInfoMenu(int mission_choice, int from_which_menu, int function_employee_id, int function_vehicle_id){

	system("CLS");

	cout << "===============================================\n";
	cout << "                 DANE     MISJI";
	cout << "\n===============================================\n\n";

	cout << "Pracownik wykonujacy misje: ";
	listaPracownikow.at(function_employee_id)->getEmployeeName();
	cout << " ";
	listaPracownikow.at(function_employee_id)->getEmployeeSurname();

	cout << "\nUzywany pojazd: ";
	listaPojazdow.at(function_vehicle_id)->getVehicleBrand();
	cout << " ";
	listaPojazdow.at(function_vehicle_id)->getVehicleModel();

	cout << "\n\n\nZ: ";
	listaMisji.at(mission_choice)->getMissionStartingPoint();
	cout << "\nDo: ";
	listaMisji.at(mission_choice)->getMissionEndPoint();
	cout << "\n\n\nOdleglosc: ";
	listaMisji.at(mission_choice)->getMissionDistance();


	cout << "\n\n0. Powrot";

	int choice;

	cin >> choice;
	cout << "\n";

	bool poprawna = false;

	while(poprawna == false){

		switch (choice){

		case 0: {

			if(from_which_menu==1){

				poprawna = true;
				system("CLS");

				int id_acquired;
				int id_wanted;

				listaPojazdow.at(function_vehicle_id)->saveVehicleID(&id_acquired);

				for (unsigned int i=0; i < uzywanePojazdy.size(); i++){

					uzywanePojazdy.at(i)->saveVehicleID(&id_wanted);

					if (id_acquired == id_wanted) {id_wanted = i; break;}

				}

				vehicleInfoMenu(id_wanted, 1);
				break;
			}

			else {poprawna = true; system("CLS"); employeePersonalMenu(function_employee_id); break;}
		}
		default: {cout << "Wybrano niepoprawna opcje.\n\nWybierz opcje: "; cin >> choice; cout << "\n";}

		}
	}
}



#endif /* MISSIONINFOMENU_H_ */
