CFLAGS= -Wall
EXEC=PROG
EXEC2=PROG2

all: $(EXEC)

PROG: node.o
	gcc -o $(EXEC) node.o logo.tab.c lex.yy.c

PROG2: node.o logo.o
	gcc -o $(EXEC2) node.o logo.o

node.o: node.c node.h
	gcc -o node.o -c node.c $(CFLAGS)

logo.o: logo.c node.h
	gcc -o logo.o -c logo.c $(CFLAGS)

logo.tab.c: logo.y
	bison -d logo.y

lex.yy.c: logo.l
	flex logo.l

clean:
	rm -rf *.o expr.tab.* lex.yy.c

mrproper: clean
	rm -rf $(EXEC)
