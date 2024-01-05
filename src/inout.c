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

int wypisz_mape(p_mapa map, FILE* wyjscie)
{
    wchar_t*  LINE_VERTICAL = L"│";
    wchar_t* LINE_HORIZONTAL = L"─";
    wchar_t* LINE_DOWN_RIGHT = L"┌";
    wchar_t* LINE_DOWN_LEFT = L"┐";
    wchar_t* LINE_UP_RIGHT = L"└";
    wchar_t* LINE_UP_LEFT = L"┘";
    wchar_t* SQUARE_WHITE = L" ";
    wchar_t* SQUARE_BLACK = L"█";
    wchar_t* ARROW_NORTH_WHITE = L"△";
    wchar_t* ARROW_NORTH_BLACK = L"▲";
    wchar_t* ARROW_EAST_WHITE = L"▷";
    wchar_t* ARROW_EAST_BLACK = L"▶";
    wchar_t* ARROW_SOUTH_WHITE = L"▽";
    wchar_t* ARROW_SOUTH_BLACK = L"▼";
    wchar_t* ARROW_WEST_WHITE = L"◁";
    wchar_t* ARROW_WEST_BLACK = L"◀";

    fwprintf(wyjscie, L"%ls\n", LINE_DOWN_LEFT);

    for(int x = 0; x < map->n; x++)
        fwprintf(wyjscie, L"%ls", LINE_HORIZONTAL);

    fwprintf(wyjscie, L"%ls", LINE_DOWN_LEFT);    

    for(int i = 0; i < map->m ; i++)
    {   
        fprintf(wyjscie, "\n");

        for(int j = 0; j < map->n; j++)
        {
            if(map->pozycja.x == i && map->pozycaj.y == j)
            {
                switch(map->pozycja.k){
                    case PRAWO:
                        switch(map->mapa[i][j]){
                            case 1:
                                fwprintf(wyjscie, L"%s%s", LINE_HORIZONTAL, ARROW_EAST_BLACK);
                                break;
                            case 0:
                                fwprintf(wyjscie, L"%s%s", LINE_HORIZONTAL, ARROW_EAST_WHITE);
                                break;         
                    }
                        break;
                    case LEWO:
                        switch(map->mapa[i][j]){
                            case 1:
                                fwprintf(wyjscie, L"%s%s", LINE_HORIZONTAL, ARROW_WEST_BLACK);
                                break;
                            case 0:
                                fwprintf(wyjscie, L"%s%s", LINE_HORIZONTAL, ARROW_WEST_WHITE);
                                break;         
                    }
                        break;
                    case DOL:
                        switch(map->mapa[i][j]){
                            case 1:
                                fwprintf(wyjscie, L"%s%s", LINE_HORIZONTAL, ARROW_SOUTH_BLACK);
                                break;
                            case 0:
                                fwprintf(wyjscie, L"%s%s", LINE_HORIZONTAL, ARROW_SOUTH_WHITE);
                                break;         
                    }
                        break;
                    case GORA
                        switch(map->mapa[i][j]){
                            case 1:
                                fwprintf(wyjscie, L"%s%s", LINE_HORIZONTAL, ARROW_NORTH_BLACK);
                                break;
                            case 0:
                                fwprintf(wyjscie, L"%s%s", LINE_HORIZONTAL, ARROW_NORTH_WHITE);
                                break;         
                    }
                        break;
                }
            }else
            {
                switch(map->mapa[i][j]){
                    case 1:
                        fwprintf(wyjscie, L"%s%s", LINE_HORIZONTAL, SQUARE_BLACK);
                        break;
                    case 0:
                        fwprintf(wyjscie, L"%s%s", LINE_HORIZONTAL, SQUARE_WHITE);
                        break;         
                    }
            }
        }

        fwprintf(wyjscie, L"%ls\n", LINE_VERTICAL);
        
        if(i == map->m)
        {
             fwprintf(wyjscie, L"%ls", LINE_UP_RIGHT);
        } else
            fwprintf(wyjscie, L"%ls", LINE_VERTICAL);

        for(int j = 0; j < map->n; j++)
            fwprintf(wyjscie, L"%ls", LINE_HORIZONTAL);

        if(i == map->m)
        {
             fwprintf(wyjscie, L"%ls", LINE_UP_LEFT);
        } else
            fwprintf(wyjscie, L"%ls", LINE_VERTICAL);
    }

}