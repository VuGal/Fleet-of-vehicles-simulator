#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>

#include "functions.h"
#include "classes.h"
#include "startmenu.h"
#include "mainmenu.h"
#include "vehiclemenu.h"
#include "employeemenu.h"
#include "availableVehicles.h"
#include "takenVehicles.h"
#include "employeeList.h"
#include "employeePersonalMenu.h"
#include "vehicleInfoMenu.h"


using namespace std;

int vehiclesCount = 0;
int employeesCount = 0;

//loaded from files
vector <Vehicle*> listaPojazdow;
vector <Employee*> listaPracownikow;
vector <Mission*> listaMisji;

//created with program start
vector <Vehicle*> wolnePojazdy;
vector <Vehicle*> uzywanePojazdy;

vector <Employee*> wolniPracownicy;
vector <Employee*> zajeciPracownicy;



int main(){

	loadVehicleList();
	loadEmployeeList();
	categorizeVehicles();

	startmenu();

	return 0;
}
