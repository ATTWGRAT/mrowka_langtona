#ifndef MROWKA_LANGTONA_INOUT_H
#define MROWKA_LANGTONA_INOUT_H

#include "mapa.h"
#include "dane.h"

dane_wywolania czytaj_argumenty(int argc, char** argv);
/* Funkcja ma tworzyć strukturę dane_wywolania (po prostu "dane_wywolania nazwa").
 * Następnie korzystając z funkcji getopt wpakować je do struktury zgodnie z zasadami
 * zdefiniowanymi powyżej.*/

int wypisz_mape(p_mapa map, FILE* wyjscie); //Funkcja zwraca 0 jeśli sukces w wypisywaniu i 1 jeśli fail
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


int wczytaj_mape_z_pliku(FILE* plik, int n, int m, mapa_tab mapa, mrowka* mrow);
#endif
