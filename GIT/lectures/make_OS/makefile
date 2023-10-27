CC=gcc 
CFLAGS=-Wall

ifeq ($(OS), Windows_NT)
	ARFLAGS=-rc
	DYLIB=-fPIC --shared
	DELETE=del
	STATICB=-L. -lmathFunc
	EXT=.exe
	DEXT=.dll
else
	UNAME_S:=$(shell uname -s)
	ifeq ($(UNAME_S), Darwin)
		ARFLAGS=rcs
		DYLIB=-dynamiclib -fPIC
		DELETE=rm -fPIC
		STATICB=libMathFunc.a
		EXT=.out
		DEXT=.dylib
endif

#build program
all: dynamicbuild

#build with static library
staticbuild: liba mathMain.c
	$(CC) $(CFLAGS) -o mathProgramStatic$(EXT) mathMain.c $(STATICB) 

#build with Dynamic Library 
dynamicbuild: $(DLIB) mathMain.c 
	$(CC) -o mathProgramDynamic$(EXT) mathMain.c $(DLIB)  

#build all object files 
objects: mathMain.o mathFunc.o 

#build static libraries 
liba: libMathFunc.a 

#build dynamiclibraries 
#windows/mac 
libd: libMathFunc$(DEXT) 

#linux 
libso: 
#OBJECTS 
mathMain.o: mathMain.c 
	$(CC) -c mathMain.c -o mathMain.o 

mathFunc.o: mathFunc.c 
	$(CC) -c mathFunc.c -o mathFunc.o 

#ARCHIVE 
libMathFunc.a: mathFunc.o 
	ar $(ARFLAGS) libMathFunc.a mathFunc.o 

#DYNAMIC LIBRARIES/SHARED OBJECT 
libMathFunc$(DEXT): mathFunc.o 
	$(CC) $(DYLIB) -o libMathFunc$(DEXT) mathFunc.o 

clean: 
	$(DELETE) *.o *.a *.so *$(DEXT) *$(EXT) 
	