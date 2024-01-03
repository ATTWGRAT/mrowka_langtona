#include "test.h"

int test()
{
    for(int i = 2; i < 50; i++)
    {
        dane_wywolania dane = {.m = i, .n = i, .mapa = NULL, .kier = (kierunek) 'P', .procent = -1, .name = "asd", .i = 5};

        p_mapa map = stworz_mape(dane);
        mrowka_odpal(dane.i, map);

        zwolnij_mape(map);
    }
    return 0;
}