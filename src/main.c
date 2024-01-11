#include "dane.h"
#include "mrowka.h"
#include "inout.h"
#include "mapa.h"

int main(int argc, char** argv)
{
  setlocale(LC_ALL, "C.UTF-8");
	dane_wywolania* dane_p = czytaj_argumenty(argc, argv);
		
	if(dane_p == NULL)
		return 1;

	p_mapa map = stworz_mape(dane_p);

	if(map == NULL){
			fprintf(stderr, "%s: Blad przy alokacji lub wczytywaniu mapy z pliku!\n", argv[0]);
			return 1;
	}

  wprintf(L"Wygenerowana mapa: \n");

	wypisz_mape(map, stdout);

  wprintf(L"Wypisywanie...\n");

  int completed;

	switch((completed = mrowka_odpal(dane_p->i, map, dane_p->name)))
	{
		case 0:
			break;

		case -1:
			fprintf(stderr, "%s: Błąd przy tworzeniu nazwy pliku wyjściowego!\n", argv[0]);
      zwolnij_mape(map);
      free(dane_p);
			return 1;

		case -2:
			fprintf(stderr, "%s: Błąd przy tworzeniu pliku wyjściowego!\n", argv[0]);
      zwolnij_mape(map);
      free(dane_p);
      return 1;

	  default:
			wprintf(L"Mrowka napotkała scianę na %d iteracji!\n", completed+1);
			break;
	}

	zwolnij_mape(map);		
	return 0;

}
