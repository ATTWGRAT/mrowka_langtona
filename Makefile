all:
	mkdir -p bin
	gcc -Wall -lm --pedantic src/*.c -o bin/mrowka.exe
test: all

