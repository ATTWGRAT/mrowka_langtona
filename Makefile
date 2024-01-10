all:
	mkdir -p bin
	gcc -Wall --pedantic src/*.c -lm -o bin/mrowka.exe
	bin/mrowka.exe -m 8 -n 12 -i 50 -k P
test: all

