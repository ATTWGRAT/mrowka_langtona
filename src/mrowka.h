#ifndef _MROWKA_
#define _MROWKA_

typedef enum k{
    PRAWO = 'P',
    LEWO = 'L',
    GORA = 'G',
    DOL = 'D'
}kierunek;

typedef struct mr{
    int x;
    int y; //Pozycja (x, y) mrówki na mapie
    kierunek k;
}mrowka;

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

#endif
