#include "test.h"
#include "inout.h"
int test()
{
    for(int i = 35;  i < 36; i++)
    {
        dane_wywolania dane = {.m = i, .n = i, .mapa = NULL, .kier = (kierunek) 'P', .procent = 25, .name = "asd", .i = 2*i};

        p_mapa map = stworz_mape(dane);
	wypisz_mape(map, stdout);
        //mrowka_odpal(dane.i, map);

        zwolnij_mape(map);
    }
    return 0;
}
