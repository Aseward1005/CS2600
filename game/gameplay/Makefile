CC=gcc

all: bin/program
objects: obj/play.o

obj/play.o: src/play.c
	$(CC) -c src/play.c -o obj/play.o

bin/program: src/play.c
	$(CC) -o bin/program src/play.c -lmosquitto -lc

clean:
	rm bin/program obj/button.o 