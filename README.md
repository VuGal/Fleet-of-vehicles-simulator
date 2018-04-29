# Projekt
Projekt C++ - Symulator floty pojazdów - Gałecki, Przybyło, Lis

Obecna architektura programu:

Symulator.cpp (główny plik) <----------------------------- classes.h
|
|-----> startmenu.h
            |
            |-------> mainmenu.h
                         |
                         |--------> employeemenu.h
                         |
                         |---------> vehiclemenu.h
                                          |
                                          |-----------> takenVehicles.h
                                          |
                                          |-----------> availableVehicles.h
