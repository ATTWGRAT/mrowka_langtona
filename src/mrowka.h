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



#endif
