#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include "classes.h"

using namespace std;

extern vector <Vehicle*> listaPojazdow;

void loadVehicleList(){
	ifstream fin("Pojazdy.txt");

	    while(!fin.eof())
	    {
	        int id, type; bool isTaken; string brand, model, engine, equipment;

	        fin >> id >> isTaken >> type >> brand >> model >> engine >> equipment;

	        Vehicle* v1 = new Vehicle(id, isTaken);

	        v1->setVehicleType(type);
	        v1->setVehicleBrand(brand);
	        v1->setVehicleModel(model);
	        v1->setVehicleEngine(engine);
	        v1->setVehicleEquipment(equipment);

	        listaPojazdow.push_back(v1);
	    }
}

#endif /* FUNCTIONS_H_ */
