CC=gcc

all: bin/program
objects: obj/matrix.o

obj/matrix.o: src/matrix.c
	$(CC) -c src/matrix.c -o obj/matrix.o

bin/program: src/MagicSquare.c src/matrix.c
	$(CC) -o bin/program src/MagicSquare.c src/matrix.c

clean:
	rm bin/program obj/matrix.o