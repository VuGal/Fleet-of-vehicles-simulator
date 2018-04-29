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



Proponuję jak najwięcej obiektówki, żeby móc działać w różny sposob na tych "pojazdach", działanie na plikach tekstowych jest żmudne i nieefektywne.


Można do <vector> wpakować pojazdy i wyciągać je np. vector.at(), każdy pojazd ma swoje unikalne ID, jakoś się skmini, żeby przy usuwaniu je zachowywały.
            
Chciałem zrobić aktualną prędkość i współrzędne geograficzne oparte na srandzie() [a jak inaczej xD], i alerty związane z przekroczeniem itd.

W plikach tekstowych najlepiej takie rzeczy, jak miasta początkowe i docelowe itd., żeby nie manipulować tymi plikami za wiele.


Do zrobienia na końcu:

- kolorki tła i tekstu (trywialne)
- polskie znaki ( jeszcze prostsze, ale żmudne, bo najprostszym, przez co najmniej podatnym na błędy, sposobem --> kopiowanie kodu do Notepada --> dopisywanie polskich znaków do wyrazów --> zamiana Replace'em polskich znaków na kody "ukośnikowe", np \210 --> wklejanie z powrotem do IDE ; na szczęście tego tekstu nie będzie sporo, także taki no-brain work :P)

Proszę się nie wahać ze swoimi propozycjami, ja w czasie majówki coś poklepię, także śledzcie tego GitHuba.
