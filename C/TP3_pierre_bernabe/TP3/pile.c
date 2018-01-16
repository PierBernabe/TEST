#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "pile_type.h"

int error1(char *message){
	fprintf(stderr,"Error : %s",message);
	exit(-1);
}

PILE InitPile(){
	PILE pile;
	//pile=(PILE)malloc(sizeof(ELEMPILE)); 
	//pile->elem=0;
	//pile->suivant=0;
	pile=0;
	return pile;
}

int Empiler (PILE* ppile, int valeur){
	PILE newelem;
	newelem=(PILE)malloc(sizeof(ELEMPILE));
	if(newelem==0){error1("AjouterElem : plus de place mémoire");}
	
	newelem->elem=valeur;	
	newelem->suivant=*ppile;
	*ppile=newelem;
	
	return 0;
}

int Depiler(PILE* ppile){
	*ppile=(*ppile)->suivant;
	return 0;
}

void afficherPile (PILE pile){
	PILE tmp;
	tmp=pile;
	while(tmp!=0){
		fprintf(stdout,"|%d|",tmp->elem);
		tmp=tmp->suivant;
	}
	fprintf(stdout,"|--\n");
}
