#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <windows.h>
#include <time.h>

#include "functions.h"
#include "classes.h"
#include "startmenu.h"
#include "mainmenu.h"
#include "vehiclemenu.h"
#include "employeemenu.h"
#include "missionmenu.h"
#include "availableVehicles.h"
#include "takenVehicles.h"
#include "employeeList.h"
#include "employeePersonalMenu.h"
#include "vehicleInfoMenu.h"
#include "currentMissions.h"
#include "missionInfoMenu.h"


using namespace std;

int vehiclesCount = 0;
int employeesCount = 0;
int missionsCount = 0;

//loaded from files
vector <Vehicle*> listaPojazdow;
vector <Employee*> listaPracownikow;
vector <Mission*> listaMisji;

//created with program start
vector <Vehicle*> wolnePojazdy;
vector <Vehicle*> uzywanePojazdy;
vector <Employee*> wolniPracownicy;
vector <Employee*> zajeciPracownicy;



int main() {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	loadVehicleList();
	loadEmployeeList();
	loadMissionList();
	categorizeVehicles();
	categorizeEmployees();

	startmenu();

	system("Pause");

	return 0;
}
