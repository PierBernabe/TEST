CC=gcc

boutisme: boutisme.c 
	$(CC) -o $@ $< 

tableau: tableau.c 
	$(CC) -o $@ $< 

addition: addition.c
	$(CC) -g -o $@ $<

matrice: matrice.c
	$(CC) -o $@ $<

bombeswap: bombeswap.c
	$(CC) -o $@ $<

tas: tas.c
	$(CC) -o $@ $<

pile: pile.c
	$(CC) -o $@ $<

fibdyn: fib.c 
	$(CC) -o $@ $<

fibstat: fib.c 
	$(CC) -static -o $@ $<

vulnerable: vulnerable.c
	$(CC) -g -m64 $< -z execstack -fno-stack-protector  -o $@

clean: 
	rm *~ boutisme tableau addition matrice bombeswap tas pile fibdyn fibstat vulnerable
