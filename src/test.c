#include "test.h"
//CAŁY PLIK TESTOWY
int test()
{
    for(int i = 2; i < 25; i++)
    {
        dane_wywolania dane = {.m = i, .n = i, .mapa = NULL, .kier = (kierunek) 'P', .procent = -1, .name = "asd", .i = 5*i};

        p_mapa map = stworz_mape(dane);
        mrowka_odpal(dane.i, map);

        zwolnij_mape(map);
    }
    return 0;
}