#ifndef _MROWKA_
#define _MROWKA_

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
	 * x - szerokość mapy.
	 * y - wysokość mapy.
	 * */

	mapa_tab mapa;
	int x;
	int y;

}*p_mapa;

#endif
