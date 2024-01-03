#include "mrowka.h"

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
    for(int y = 0; y < i; y++)
    {
        if(mrowka_przejdz(map))
            return 1;
#ifdef TEST
        for(int k = 0; k < map->n; k++)
        {
            for(int h = 0; h < map->m; h++)
                printf("%d", map->mapa[k][h]);
            printf("\n");
        }
        printf("Done\n");
#endif
    }
    return 0;
}

