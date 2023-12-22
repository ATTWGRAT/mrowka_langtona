#ifndef MROWKA_LANGTONA_INOUT_H
#define MROWKA_LANGTONA_INOUT_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>

#include "mrowka.h"

typedef struct{
    int m; //liczba wierszy
    int n; //liczba kolumn
    int i; //liczba iteracji
    char* name; //przedrostek nazwy pliku wyjściowego
    char kierunek; //JEDNA Z LITER: L, P, G, D - ODPOWIEDNIO LEWO PRAWO GÓRA DÓŁ
    FILE* mapa; //Opcjonalny plik z mapą. W przypadku braku podanego w argumentach ustawić na NULL;
    double procent; //Procentowe wypełnienie mapy. W przypadku nie podania argumentu ustawić na -1;
}dane_wywolania;


// <<<<<<<<<<<<<<<<< ANGELIKA
dane_wywolania czytaj_argumenty(int argc, char** argv);
/* Funkcja ma tworzyć strukturę dane_wywolania (po prostu "dane_wywolania nazwa").
 * Następnie korzystając z funkcji getopt wpakować je do struktury zgodnie z zasadami
 * zdefiniowanymi powyżej.*/


// <<<<<<<<<<<<<<<<< PIOTRUŚ
void wypisz_mape(p_mapa map, FILE* wyjscie);
/* Funkcja ma wypisać do wyjscia mapę włącznie z lokalizacją mrówki i jej kierunkiem.
 * Niech korzysta z funkcji fprintf, to będzie można też pisać do stdout
 * poniżej znaki, które możesz użyć.
 * PAMIĘTAJ, ŻE TE ZNAKI TO JEST TYP wchar_t, A NIE ZWYKŁY CHAR*/
// LINE_VERTICAL:│
// LINE_HORIZONTAL:─
// LINE_DOWN_RIGHT:┌
// LINE_DOWN_LEFT:┐
// LINE_UP_RIGHT:└
// LINE_UP_LEFT:┘
// SQUARE_WHITE:
// SQUARE_BLACK:█
// ARROW_NORTH_WHITE:△
// ARROW_NORTH_BLACK:▲
// ARROW_EAST_WHITE:▷
// ARROW_EAST_BLACK:▶
// ARROW_SOUTH_WHITE:▽
// ARROW_SOUTH_BLACK:▼
// ARROW_WEST_WHITE:◁
// ARROW_WEST_BLACK:◀

// Implementacją opcjonalnych części zajmiemy się później.
#endif
