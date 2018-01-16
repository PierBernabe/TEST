CFLAGS= -Wall
EXEC=PROG

all: $(EXEC)

PROG: arbre.o 
	gcc -o $(EXEC) arbre.o

arbre.o: arbre.c 
	gcc -o arbre.o -c arbre.c $(CFLAGS)


clean:
	rm -rf *.o 

mrproper: clean
	rm -rf $(EXEC)
