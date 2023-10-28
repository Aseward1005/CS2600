CC=gcc

all: bin/program
objects: obj/employeeTable.o obj/employeeTwo.o

obj/employeeTable.o: src/employeeTable.c 
	$(CC) -c src/employeeTable.c -o obj/employeeTable.o

obj/employeeTwo.o: src/employeeTwo.c
	$(CC) -c src/employeeTwo.c -o obj/employeeTwo.o

bin/program: src/employeeMain.c src/employeeTable.c src/employeeTwo.c
	$(CC) -o bin/program src/employeeMain.c src/employeeTable.c src/employeeTwo.c

clean:
	rm bin/program obj/employeeTable.o obj/employeeTwo.o