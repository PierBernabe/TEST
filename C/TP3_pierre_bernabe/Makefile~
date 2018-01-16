CFLAGS= -Wall
EXEC=PROG

all: function.o main.o
	gcc -o $(EXEC) function.o main.o

TP1_function.o: function.c function.h modelStruct.h
	gcc -o function.o -c function.c $(CFLAGS)

main.o: main.c function.h modelStruct.h
	gcc -o main.o -c main.c $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
