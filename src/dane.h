#ifndef MROWKA_LANGTONA_DANE_H
#define MROWKA_LANGTONA_DANE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>
#include <math.h>
#include <time.h>

typedef struct{
    int m; //liczba wierszy
    int n; //liczba kolumn
    int i; //liczba iteracji
    char* name; //przedrostek nazwy pliku wyjściowego
    kierunek kier; //JEDNA Z LITER: L, P, G, D - ODPOWIEDNIO LEWO PRAWO GÓRA DÓŁ. Implementacja za pomocą enuma (argument 'P' odpowiada wartości stałej PRAWO w strukturze).
    FILE* mapa; //Opcjonalny plik z mapą. W przypadku braku podanego w argumentach ustawić na NULL;
    double procent; //Procentowe wypełnienie mapy. W przypadku nie podania argumentu ustawić na -1;
}dane_wywolania;

#endif
