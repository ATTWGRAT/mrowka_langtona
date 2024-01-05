all:
	mkdir -p bin
	gcc -Wall --pedantic src/*.c -lm -o bin/mrowka.exe
	bin/mrowka.exe
test: all

