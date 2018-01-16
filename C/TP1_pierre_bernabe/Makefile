CFLAGS= -Wall
EXEC=TP1

all: TP1_function.o main.o
	gcc -o TP1 TP1_function.o main.o

TP1_function.o: TP1_function.c TP1_function.h
	gcc -o TP1_function.o -c TP1_function.c $(CFLAGS)

main.o: main.c TP1_function.h
	gcc -o main.o -c main.c $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
