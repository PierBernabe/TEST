CFLAGS= -g -Wall -DDEBUG
EXEC=PROG

all: PROG

PROG: node.o lex.yy.c logo.tab.c node.c node.h
	gcc -o $(EXEC) node.c lex.yy.c logo.tab.c $(CFLAGS) -lm -ll

lex.yy.c: logo.l logo.tab.c
	flex logo.l

logo.tab.c: logo.y
	bison -d logo.y


clean:
	rm -rf *.o *.tab.c *.tab.h *.yy.c

mrproper: clean
	rm -rf $(EXEC)
