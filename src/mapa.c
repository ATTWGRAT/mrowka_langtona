#include "mapa.h"
#include "inout.h"

void generuj_mape_losowo(int n, int m, double procent, mapa_tab tablica)
{
    int pola = n * m;
    int czarne = floor((procent/100)*pola);

    srand(time(NULL));

    for(int i = 0; i < czarne; i++)
    {
        int num = rand()%pola;

        while(tablica[num/n][num%n] == CZARNE)
            num = rand()%pola;

        tablica[num/n][num%n] = CZARNE;
    }
}

void zwolnij_mape(p_mapa mapa)
{
    for(int i = 0; i<mapa->m; i++)
        free(mapa->mapa[i]);
    free(mapa);
}

p_mapa stworz_mape(dane_wywolania dane)
{
    p_mapa mapa = malloc(sizeof *mapa);

    mapa->m = dane.m;
    mapa->n = dane.n;

    mapa_tab tablica = malloc(dane.m * sizeof *tablica);

    for(int i = 0; i < dane.m; i++)
        tablica[i] = calloc(dane.n, sizeof *tablica[i]);


    mapa->mapa = tablica;

    if(dane.procent != -1)
        generuj_mape_losowo(dane.n, dane.m, dane.procent, tablica);


    mrowka mrow;

    if(dane.mapa != NULL)
    {
        if(wczytaj_mape_z_pliku(dane.mapa, dane.n, dane.m, tablica, &mrow) == 1)
        {
            zwolnij_mape(mapa);
            return NULL;
        }

    } else {
        mrow.x = dane.n/2;
        mrow.y = dane.m % 2 == 1 ? dane.m / 2 + 1 : dane.m / 2;
    }

    mrow.k = dane.kier;
    mapa->pozycja = mrow;

    return mapa;
}

