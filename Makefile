CC = gcc
CFLAGS = -lpng -lz -O1

all: main

main: main.c computation.o image_processing.o
	$(CC) -o main computation.o image_processing.o main.c $(CFLAGS)

image_processing.o: image_processing.c
	$(CC) -c image_processing.c $(CFLAGS)
computation.o:
	$(CC) -c computation.c $(CFLAGS)

clean:
	rm -rf computation.o image_processing.o main
