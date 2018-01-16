#########################################################
# Makefile pour les programme du TD2 AGP
# Tanguy Risset, 2012
#########################################################
# Variables pour le compilateur et 
# l'editeur de lien (ici on utilise l'editeur de
# lien de gcc
CC            =gcc 
CFLAGS        +=  -g
# Attention quand on parle de variable 
# il s'agit de variable d'environnement 
# utilisée par make (exemple: $(CC)

#cible principales: on construit l'executable tri
# Pour tester votre programme tapez: ./tri q number.data"
all: tri 

tri: tri.c
	$(CC) $(CFLAGS)  tri.c  -o tri

#Pour nettoyer (enlever tous les fichiers générés
clean:
	-rm -rf *~ *.out tri *.o *.res html

#Pour faire la doc, génère un repetoire html
doc:	doxyfile
	doxygen doxyfile
#
# D'autre règle pour moi: créer un tar de la solution
tarSol:	dummy 
	make clean
	cd ..;tar cvf TD2_corr.tar TD2/tri_corrige.c TD2/tri.c TD2/Makefile TD2/number.data TD2/doxyfile  

#Creer l'archive que vous téléchargez
archive:dummy 
	make clean
	cd ..;tar cvf TD2init.tar  TD2/tri.c TD2/Makefile TD2/number.data TD2/doxyfile  


dummy:


