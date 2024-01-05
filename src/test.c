#include "test.h"
#include "inout.h"
int test()
{
    for(int i = 4;  i < 5; i++)
    {
        dane_wywolania dane = {.m = i, .n = i, .mapa = NULL, .kier = (kierunek) 'P', .procent = -1, .name = "asd", .i = 2*i};

        p_mapa map = stworz_mape(dane);
	wypisz_mape(map, stdout);
        //mrowka_odpal(dane.i, map);

        zwolnij_mape(map);
    }
    return 0;
}
