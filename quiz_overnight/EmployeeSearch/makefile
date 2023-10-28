CC=gcc

all: bin/program
objects: obj/employeeTable.o obj/employeeOne.o

obj/employeeTable.o: src/employeeTable.c 
	$(CC) -c src/employeeTable.c -o obj/employeeTable.o

obj/employeeOne.o: src/employeeOne.c
	$(CC) -c src/employeeTwo.c -o obj/employeeOne.o

bin/program: src/employeeMain.c src/employeeTable.c src/employeeOne.c
	$(CC) -o bin/program src/employeeMain.c src/employeeTable.c src/employeeOne.c

clean:
	rm bin/program obj/employeeTable.o obj/employeeTwo.o