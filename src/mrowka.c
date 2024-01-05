#include "mrowka.h"
#include "inout.h"
#include <locale.h>
int mrowka_przejdz(p_mapa map)
{
    mrowka* m = &(map->pozycja);
    switch(map->mapa[m->y][m->x])
    {
        case BIALE:
            map->mapa[m->y][m->x] = CZARNE;
            switch(m->k)
            {
                case PRAWO:
                    m->k = DOL;
                    if(++(m->y) == map->m)
                        return 1;
                    break;

                case DOL:
                    m->k = LEWO;
                    if(--(m->x) == -1)
                        return 1;
                    break;

                case LEWO:
                    m->k = GORA;
                    if(--(m->y) == -1)
                        return 1;
                    break;

                case GORA:
                    m->k = PRAWO;
                    if(++(m->x) == map->n)
                        return 1;
                    break;
            }
	    break;
        case CZARNE:
            map->mapa[m->y][m->x] = BIALE;
            switch(m->k)
            {
                case PRAWO:
                    m->k = GORA;
                    if(--(m->y) == -1)
                        return 1;
                    break;

                case DOL:
                    m->k = PRAWO;
                    if(++(m->x) == map->n)
                        return 1;
                    break;

                case LEWO:
                    m->k = DOL;
                    if(++(m->y) == map->m)
                        return 1;
                    break;

                case GORA:
                    m->k = LEWO;
                    if(--(m->x) == -1)
                        return 1;
                    break;
            }
    }
    return 0;
}

int mrowka_odpal(int i, p_mapa map)
{
	setlocale(LC_ALL, "C.UTF-8");
    for(int y = 0; y < i; y++)
    {
        if(mrowka_przejdz(map))
            return 1;
        wprintf(L"Iteracja nr: %d\n", y+1);
        wypisz_mape(map, stdout);
    }
    return 0;
}

