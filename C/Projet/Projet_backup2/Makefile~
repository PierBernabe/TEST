CFLAGS= -Wall
EXEC=PROG
EXEC2=PROG2

all: PROG2


PROG2: node.o lex.yy.c logo.tab.c
	gcc -o $(EXEC2) node.o lex.yy.c logo.tab.c -lm -ll

PROG: node.o logo.o
	gcc -o $(EXEC) node.o logo.o -lm -ll

node.o: node.c node.h
	gcc -o node.o -c node.c $(CFLAGS) -lm -ll

logo.o: logo.c node.h
	gcc -o logo.o -c logo.c $(CFLAGS) -lm -ll

lex.yy.c: logo.l logo.tab.c
	flex logo.l

logo.tab.c: logo.y
	bison -d logo.y




clean:
	rm -rf *.o *.tab.c *.tab.h *.yy.c

mrproper: clean
	rm -rf $(EXEC)
