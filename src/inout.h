#ifndef MROWKA_LANGTONA_INOUT_H
#define MROWKA_LANGTONA_INOUT_H

#include "mapa.h"
#include "dane.h"

dane_wywolania czytaj_argumenty(int argc, char** argv);
/* Funkcja ma tworzyć strukturę dane_wywolania (po prostu "dane_wywolania nazwa").
 * Następnie korzystając z funkcji getopt wpakować je do struktury zgodnie z zasadami
 * zdefiniowanymi powyżej.*/

void wypisz_mape(p_mapa map, FILE* wyjscie);


int wczytaj_mape_z_pliku(FILE* plik, int n, int m, mapa_tab mapa, mrowka* mrow);
#endif
