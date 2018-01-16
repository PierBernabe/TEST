CFLAGS= -Wall
EXEC=TP3

all: hanoi.o main.o pile.o
	gcc -o $(EXEC) hanoi.o main.o pile.o

pile.o: pile.c pile.h pile_type.h
	gcc -o pile.o -c pile.c $(CFLAGS)

hanoi.o: hanoi.c hanoi.h pile_type.h pile.h
	gcc -o hanoi.o -c hanoi.c $(CFLAGS)

main.o: main.c pile.h hanoi.h pile_type.h
	gcc -o main.o -c main.c $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
