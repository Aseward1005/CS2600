CC=gcc
CFLAGS=-L. -lmathFuncDLL
DLLFLAGS=-fPIC --shared

ifeq ($(OS), Windows_NT)
	DELETE=del
else
	DELETE=rm
	ifeq ($(UNAME_S), Darwin)
		CFLAGS += -D OSX
	else
	endif
endif

all: mathProgram

mathFuncMain.o: mathFuncMain.c 
	$(CC) gcc -c mathFuncMain.c -o mathFuncMain.o

mathFunc.o: mathFunc.c 
	$(CC) -c mathFunc.c

mathFuncDLL.dll: mathFunc.c
	$(CC) $(DLLFLAGS) -o mathFuncDLL.dll mathFunc.c

mathProgram: mathFuncDLL.dll mathFuncMain.c
	$(CC) $(CFLAGS) -c mathFuncMain.c -o mathProgram

clean:
	del mathProgram *.o *.a