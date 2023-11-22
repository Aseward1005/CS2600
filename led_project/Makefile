CC=gcc

all: bin/program
objects: obj/button.o

obj/button.o: src/button.c
	$(CC) -c src/button.c -o obj/button.o

bin/program: src/button.c
	$(CC) -o bin/program src/button.c -lmosquitto

clean:
	rm bin/program obj/button.o 