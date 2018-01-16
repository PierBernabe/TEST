CFLAGS= -Wall
EXEC=PROG

all: $(EXEC)

PROG: main.o mediane.o
	gcc -o $(EXEC) main.o mediane.o

main.o: main.c mediane.h
	gcc -o main.o -c main.c $(CFLAGS)

mediane.o: mediane.c mediane.h
	gcc -o mediane.o -c mediane.c $(CFLAGS)

clean:
	rm -rf *.o 

mrproper: clean
	rm -rf $(EXEC)
