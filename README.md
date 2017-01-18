# AAL
Projekt z analizy algorytmów - implementacja skip listy.
Projekt na przedmiot AAL

Autor: Aleksander Brzozowski

1. WYMAGANIA
=============

Do skompilowania projektu niezbędne są:

- CMake w wersji co najmniej 3.6
- W przypadku systemu Linux niezbędny jest program make
- Kompilator C++ (VS, g++, etc.)

2. PRZYGOTOWANIE
================

Instalacja CMake:
--------------------

- Należy pobrać CMake ze strony projektu https://cmake.org/download/
oraz zainstalować go zgodnie z załączoną doń instrukcją.

3. INSTALACJA
=============

Instalacja polega na wywołaniu programu CMake podając jako
argument ścieżkę do folderu w którym znajduje się projekt.

W przypadku systemu z rodziny Linux, lub Windows korzystającego ze środowiska 
MinGW, polecenie to wygeneruje plik Makefile. Wywołanie komendy 'make' 
skompiluje projekt i wygeneruje plik wykonywalny 'AAL'.

W przypadku systemu Windows, korzystającego z kompilatora Visual Studio
wygenerowany zostanie projekt Visual Studio, który należy skompilować
odpowiednim kompilatorem.

4. INSTALACJA KROK PO KROKU
===========================


Zakłada się spełnienie warunków z punktu 1.
oraz że znajdujemy się w katalogu z projektem


Systemy z rodziny Linux
-----------------------

W terminalu:
* mkdir build && cd build  # stworzenie i przejście do katalogu build
* cmake ../  # uruchomienie CMake
* make  # kompilacja i konsolidacja projektu
* ./AAL  # uruchomienie programu

Systemy Windows
---------------------------------------
UWAGA!
W miejsce $GENERATOR należy wstawić jakim kompilatorem będzie kompilowany
projekt. Przykładową wartością w to miejsce
może być "Visual Studio 14 2015 Win64".

W środowisku Power Shell:
* mkdir build # stworzenie katalogu build
* cd build # przejście do katalogu build
* cmake -G "$GENERATOR" ../ # uruchomienie CMake
* cmake --build . # wywołanie kompilatora za pośrednictwem CMake

