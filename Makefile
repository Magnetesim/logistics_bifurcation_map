CC = gcc

all: main

main: main.c computation.o
	gcc -o main computation.o main.c

computation.o:
	gcc -c computation.c

clean:
	rm -rf computation.o main
