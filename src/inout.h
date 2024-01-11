#ifndef MROWKA_LANGTONA_INOUT_H
#define MROWKA_LANGTONA_INOUT_H

#include "mapa.h"
#include "dane.h"

#define LINE_VERTICAL L"│"
#define LINE_HORIZONTAL L"─"
#define LINE_DOWN_RIGHT L"┌"
#define LINE_DOWN_LEFT L"┐"
#define LINE_UP_RIGHT L"└"
#define LINE_UP_LEFT L"┘"
#define SQUARE_WHITE L" "
#define SQUARE_BLACK L"█"
#define ARROW_NORTH_WHITE L"△"
#define ARROW_NORTH_BLACK L"▲"
#define ARROW_EAST_WHITE L"▷"
#define ARROW_EAST_BLACK L"▶"
#define ARROW_SOUTH_WHITE L"▽"
#define ARROW_SOUTH_BLACK L"▼"
#define ARROW_WEST_WHITE L"◁"
#define ARROW_WEST_BLACK L"◀"

dane_wywolania* czytaj_argumenty(int argc, char** argv);

void wypisz_mape(p_mapa map, FILE* wyjscie);


int wczytaj_mape_z_pliku(FILE* plik, int n, int m, mapa_tab mapa, mrowka* mrow);
#endif
