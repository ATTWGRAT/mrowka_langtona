clean:
	rm -r bin
	rm -r testout
all: clean
	mkdir -p bin
	gcc -Wall --pedantic src/*.c -lm -o bin/mrowka.exe
test: all
	mkdir -p testout
	mkdir -p testout/test1
	mkdir -p testout/test2
	mkdir -p testout/test3
	mkdir -p testout/test4
	mkdir -p testout/test5
	bin/mrowka.exe -m 8 -n 12 -k 'P' -o testout/test1/t1 -i 50 -f pliki_testowe/test1
	bin/mrowka.exe -m 17 -n 22 -k 'L' -o testout/test2/t2 -i 112 -f pliki_testowe/test2
	bin/mrowka.exe -m 20 -n 39 -k 'D' -o testout/test3/t3 -i 300 -f pliki_testowe/test3
	bin/mrowka.exe -m 30 -n 30 -k 'P' -o testout/test4/t4 -i 1000 -p 50
	bin/mrowka.exe -m 100 -n 100 -k 'G' -o testout/test5/t5 -i 15000 
