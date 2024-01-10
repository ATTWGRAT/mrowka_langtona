#include <stdio.h>
#include "mrowka.h"
#include "inout.h"
#include "dane.h"
#include "mapa.h"

int main(int argc, char** argv)
{
    dane_wywolania* dane_p = czytaj_argumenty(argc, argv);
    
    if(dane_p == NULL)
	    return 1;

    p_mapa map = stworz_mape(*dane_p);

    if(map == NULL)
	    fprintf(stderr, "%s: Blad przy wczytywaniu mapy z pliku!\n", argv[0]);

    switch(mrowka_odpal(dane_p->i, map, dane_p->name)){
	case 0:
	        break;
        case 1:
		wprintf(L"Mrowka napotkała scianę!\n");
		break;
	case 2:
		fprintf(stderr, "%s: Błąd przy tworzeniu nazwy pliku wyjściowego!\n", argv[0]);
		break;
	case 3:
		fprintf(stderr, "%s: Błąd przy tworzeniu pliku wyjściowego!\n", argv[0]);
		break;
    }

    zwolnij_mape(map);    

    return 0;
}
