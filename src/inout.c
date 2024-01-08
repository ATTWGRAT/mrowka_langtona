#include <locale.h>
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

void wypisz_mape(p_mapa map, FILE* wyjscie)
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

    setlocale(LC_ALL, "C.UTF-8");

    fwprintf(wyjscie, L"%ls", LINE_DOWN_RIGHT);

    for(int x = 0; x < map->n; x++)
        fwprintf(wyjscie, L"%ls", LINE_HORIZONTAL);

    fwprintf(wyjscie, L"%ls", LINE_DOWN_LEFT);    

    for(int i = 0; i < map->m ; i++)
    {   
        fwprintf(wyjscie, L"\n%ls", LINE_VERTICAL);

        for(int j = 0; j < map->n; j++)
        {
            if(map->pozycja.y == i && map->pozycja.x == j)
            {
                switch(map->pozycja.k){
                    case PRAWO:
                        switch(map->mapa[i][j]){
                            case 1:
                                fwprintf(wyjscie, L"%ls", ARROW_EAST_BLACK);
                                break;
                            case 0:
                                fwprintf(wyjscie, L"%ls", ARROW_EAST_WHITE);
			       	break;         
                        }
                        break;
                    case LEWO:
                        switch(map->mapa[i][j]){
                            case 1:
                                fwprintf(wyjscie, L"%ls", ARROW_WEST_BLACK);
                                break;
                            case 0:
                                fwprintf(wyjscie, L"%ls", ARROW_WEST_WHITE);
                                break;         
                        }
                        break;
                    case DOL:
                        switch(map->mapa[i][j]){
                            case 1:
                                fwprintf(wyjscie, L"%ls", ARROW_SOUTH_BLACK);
                                break;
                            case 0:
                                fwprintf(wyjscie, L"%ls", ARROW_SOUTH_WHITE);
                                break;         
                        }
                        break;
                    case GORA:
                        switch(map->mapa[i][j]){
                            case 1:
                                fwprintf(wyjscie, L"%ls", ARROW_NORTH_BLACK);
                                break;
                            case 0:
                                fwprintf(wyjscie, L"%ls", ARROW_NORTH_WHITE);
                                break;         
                        }
                        break;
                }
            }
	        else
            {
                switch(map->mapa[i][j]){
                    case 1:
                        fwprintf(wyjscie, L"%ls", SQUARE_BLACK);
                        break;
                    case 0:
                        fwprintf(wyjscie, L"%ls", SQUARE_WHITE);
                        break;         
                    }
            }
        }
	    fwprintf(wyjscie, L"%ls", LINE_VERTICAL);
    }
    fwprintf(wyjscie, L"\n");
        
    fwprintf(wyjscie, L"%ls", LINE_UP_RIGHT);

    for(int j = 0; j < map->n; j++)
        fwprintf(wyjscie, L"%ls", LINE_HORIZONTAL);

    fwprintf(wyjscie, L"%ls", LINE_UP_LEFT);
    
    fwprintf(wyjscie, L"\n");

    return 0;

}

dane_wywolania* czytaj_argumenty(int argc, char** argv)
{
    dane_wywolania* dane = malloc(sizeof *dane);

    int opt;

    dane->m = -1;
    dane->n = -1;
    dane->i = -1;
    dane->name = NULL;
    dane->kier = 'Z';
    dane->mapa = NULL;
    dane-> procent = -1;


    while((opt = getopt(argc, argv, ":m:n:i:o:k:f:p:")) != -1)
    {
        switch(opt){
            case 'm':
                if(atoi(optarg) < 1 || strchr(optarg, '.') != NULL)
                {
                    fprintf(stderr, "Ten Input jest nieprawidlowy \n");
                    free(dane);
                    return NULL;
                }else {
                    dane->m = atoi(optarg);
                }
                break;

            case 'n':
                if(atoi(optarg) < 1 || strchr(optarg, '.') != NULL)
                {
                    fprintf(stderr, "Ten Input jest nieprawidlowy \n");
                    free(dane);
                    return NULL;
                }else {
                    dane->n = atoi(optarg);
                }
                break;

            case 'i':
                if(atoi(optarg) < 1 || strchr(optarg, '.') != NULL)
                {
                    fprintf(stderr, "Ten Input jest nieprawidlowy \n");
                    free(dane);
                    return NULL;
                }else {
                    dane->i = atoi(optarg);
                }
                break;

            case 'o':
                dane->name = optarg;
                break;

            case 'k':
                if(*optarg == 'P' || *optarg == 'L'|| *optarg == 'G'|| *optarg == 'D'
                   *optarg == 'p' || *optarg == 'l'|| *optarg == 'g'|| *optarg == 'd')
                {
                    dane->kier = toupper(*optarg); 
                } else{
                    fprintf(stderr, "Ten Input jest nieprawidlowy \n"); 
                    free(dane);
                    return NULL;                 
                }
                break;

            case 'f':
                FILE *file =  fopen(optarg, "r");

                if(file == NULL)
                {
                    fprintf(stderr, "Blad przy otwieraniu pliku\n");
                }else{
                    dane->mapa = file;
                }

                break;

            case 'p':
                if (atof(optarg) < 0 || atof(optarg) > 100)
                {
                    fprintf(stderr, "Ten Input jest nieprawidlowy \n");
                    free(dane);
                    return NULL;   
                } else{
                    dane->procent = atof(optarg);
                }
                break;

            case '?':
                fprintf(stderr, "Nieznana opcja: %c\n", optopt); 
                free(dane);
                return NULL; 

            case ':':
                fprintf(stderr, "Opcja %c wymaga wartosci \n", optopt); 
                free(dane);
                return NULL;   
        }
    }

    if(dane->m == -1)
    {
        fprintf(stderr, "Opcja m jest wymagana \n");
        free(dane);
        return NULL;
    }

    if(dane->n == -1)
    {
        fprintf(stderr, "Opcja n jest wymagana \n");
        free(dane);
        return NULL;
    }

    if(dane->i == -1)
    {
        fprintf(stderr, "Opcja i jest wymagana \n");
        free(dane);
        return NULL;
    }

    if(dane->name == NULL)
    {
        fprintf(stderr, "Opcja o jest wymagana \n");
        free(dane);
        return NULL;
    }

    if(dane->kier == 'Z')
    {
        fprintf(stderr, "Opcja k jest wymagana \n");
        free(dane);
        return NULL;
    }

    return dane;
}
