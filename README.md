# mrowka_langtona
Kompilacja:
make build - Tworzy folder bin i w nim plik mrowka.exe
make test - robi to co make build i wykonuje testy


Sposób Korzystania:
Po skompilowaniu uruchamiemy go z opcjami wywołania z których obowiązkowych jest 5:

-m -> Odpowiadający za ilość wierszy tworzonej planszy (obszaru poruszania się mrówki) 
    Oczekiwana: liczba natrualna; 1,2,3,4...

-n -> Odpowiadający za ilość kolumn tworzonej planszy (obszaru poruszania się mrówki)
    Oczekiwana: liczba natrualna; 1,2,3,4...

-i -> Ilczba iteracji (ruchów mrówki)
    Oczekiwana: liczba natrualna; 1,2,3,4...

-o -> Nazwa pliku wyjściowego (jak nazywały się będą pliki w których zapisywane będą kolejne iteracje mrówki)
    Oczekiwana: nazwa; np. paczka

-k -> Kierunek w którym będzie skierowana mrówka na początku
    Oczekiwana: L, P, G, D; mrówka będzie skierowana w: L - lewo; P - prawo; G - górę; D - dół

Bez tych opcji program nie zadziała. Pozostałe dwie opcje są opcjonalne:

-f -> Nazwa pliku z mapą po której ma się pruszać mrówka
    Oczekiwana: nazwa; np. test2

-p -> Procent mapy który ma być wypełnione
    Oczekiwana: liczba rzeczywista z przedziału (0, 100); np. 72.1

Bez tych opcji program zadziała.

Przykładowy sposób wywołania:

bin/mrowka.exe -m 72 -n 98 -i 2000 -o kartka -k L -p 72.3


