#include "inout.h"

int wczytaj_mape_z_pliku(FILE* plik, int n, int m, mapa_tab mapa, mrowka* mrow)
{
    if(fscanf(plik, "%d", &(mrow->x)) == 0)
        return 1;

    if(fscanf(plik, "%d", &(mrow->y)) == 0)
        return 1;

    for(int i = 0; i < m; i++)
    {
        for(int y = 0; y < n; y++)
        {
            int temp;

            if(fscanf(plik, "%d", &temp) == 0)
                return 1;

            if(temp != 0 && temp != 1)
                return 1;

            mapa[i][y] = (pole) temp;

        }

    }

    return 0;
}