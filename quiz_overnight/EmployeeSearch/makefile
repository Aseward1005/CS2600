CC=gcc

all: program

employeeTable.o: employeeTable.c 
	$(CC) -c src/employeeTable.c -o obj/employeeTable.o

employeeTwo.o: employeeTwo.c
	$(CC) -c src/employeeTwo.c -o obj/employeeTwo.o

program: employeeMain.c employeeTable.c employeeTwo.c
	$(CC) -o bin/program src/employeeMain.c src/employeeTable.c src/employeeTwo.c

clean:
	rm bin/program obj/employeeTable.o obj/employeeTwo.o