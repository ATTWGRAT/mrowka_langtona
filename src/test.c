#include "test.h"
//CAŁY PLIK TESTOWY
#include "inout.h"
int test()
{
    for(int i = 35;  i < 36; i++)
    {
        dane_wywolania dane = {.m = 12, .n = 12, .mapa = NULL, .kier = (kierunek) 'P', .procent = -1, .name = "out/asd", .i = 2*i};

        p_mapa map = stworz_mape(dane);
	    wypisz_mape(map, stdout);
        mrowka_odpal(dane.i, map, dane.name);

        zwolnij_mape(map);
    }
    return 0;
}
