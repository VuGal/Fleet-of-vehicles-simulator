# Projekt
Projekt C++ - Symulator floty pojazdów - Gałecki, Przybyło, Lis

Obecna architektura programu (odpalcie w trybie Raw, żeby poprawnie zobaczyć):

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




Chciałem zrobić aktualną prędkość i współrzędne geograficzne oparte na srandzie() [a jak inaczej xD], i alerty związane z przekroczeniem itd.

W plikach tekstowych:
- miasta poczatkowe i docelowe


Do zrobienia na końcu:

- kolorki tła i tekstu (trywialne)
- polskie znaki ( jeszcze prostsze, ale żmudne, bo najprostszym, przez co najmniej podatnym na błędy, sposobem --> kopiowanie kodu do Notepada --> dopisywanie polskich znaków do wyrazów --> zamiana Replace'em polskich znaków na kody "ukośnikowe", np \210 --> wklejanie z powrotem do IDE ; na szczęście tego tekstu nie będzie sporo, także taki no-brain work :P)

EDIT. W sumie przy wpisywaniu nowych pojazdów/pracowników do bazy i tak nie będzie można użyć polskich znaków, może całkiem zrezygnować?

Informatyka >> EiT
