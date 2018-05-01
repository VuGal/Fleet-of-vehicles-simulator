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


using namespace std;

int vehiclesCount = 0;
int employeesCount = 0;

vector <Vehicle*> listaPojazdow;
vector <Employee*> listaPracownikow;
vector <Mission*> listaMisji;

int main(){

	loadVehicleList();
	loadEmployeeList();

	startmenu();

	return 0;
}
