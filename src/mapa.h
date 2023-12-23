#ifndef MROWKA_LANGTONA_MAPA_H
#define MROWKA_LANGTONA_MAPA_H

#include "mrowka.h"
#include "dane.h"

typedef enum p{
    /* Enum reprezentujący pojedyncze pole.
     * mapa_tab to dwuwymiarowa tablica reprezuntująca mapę.
     * Jeśli mapa_tab[x][y] == CZARNE lub 1, to pole o koordynatach (x, y), jest czarne.
     * Analogicznie dla białego.
     * */

    CZARNE = 1,
    BIALE = 0,

}**mapa_tab, pole;

typedef struct m{
    /* Struktura reprezentująca mapę z rozmiarami.
     * mapa - tablica pól.
     * m - szerokość mapy.
     * n - wysokość mapy.
     * */

    mrowka pozycja;
    mapa_tab mapa;
    int m;
    int n;

}*p_mapa;

p_mapa stworz_mape(dane_wywolania dane);


#endif