SRCDIR   = ../src/
BINDIR   = ../bin/

all:$(BINDIR)serveur1-celerite $(BINDIR)serveur2-celerite $(BINDIR)serveur3-celerite

$(BINDIR)serveur1-celerite: serveur1-celerite.o
	gcc -Wall -o $(BINDIR)serveur1-celerite serveur1-celerite.o -lm -g
	
$(BINDIR)serveur2-celerite: serveur2-celerite.o
	gcc -Wall -o $(BINDIR)serveur2-celerite serveur2-celerite.o -lm -g
	
$(BINDIR)serveur3-celerite: serveur3-celerite.o
	gcc -Wall -o $(BINDIR)serveur3-celerite serveur3-celerite.o -lm -g


serveur1-celerite.o: serveur1-celerite.c
	gcc -Wall -c serveur1-celerite.c -o serveur1-celerite.o -g
	
serveur2.o: serveur2-celerite.c
	gcc -Wall -c serveur2-celerite.c -o serveur2-celerite.o -g	

serveur3.o: serveur3-celerite.c
	gcc -Wall -c serveur3-celerite.c -o serveur3-celerite.o -g

clean:
	rm *.o $(BINDIR)/copy_*

