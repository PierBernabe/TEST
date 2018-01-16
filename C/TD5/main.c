#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include "modelStruct.h"

int main(void){
    
//Définition de l'arbre----------------------------------------
	Arbre A1;
	A1=(Arbre) malloc(sizeof(NOEUD));
	A1->val=10;

	Arbre A11;
	A11=(Arbre) malloc(sizeof(NOEUD));
	A11->val=10;

	Arbre A111;
	A111=(Arbre) malloc(sizeof(NOEUD));
	A111->val=10;

	Arbre A112;
	A112=(Arbre) malloc(sizeof(NOEUD));
	A112->val=10;

	Arbre A1111;
	A1111=(Arbre) malloc(sizeof(NOEUD));
	A1111->val=10;

	Arbre A1112;
	A1112=(Arbre) malloc(sizeof(NOEUD));
	A1112->val=10;

	Arbre A1121;
	A1121=(Arbre) malloc(sizeof(NOEUD));
	A1121->val=10;

	Arbre A1122;
	A1122=(Arbre) malloc(sizeof(NOEUD));
	A1122->val=10;

	Arbre A12;
	A12=(Arbre) malloc(sizeof(NOEUD));
	A12->val=10;

	Arbre A121;
	A121=(Arbre) malloc(sizeof(NOEUD));
	A121->val=10;

	Arbre A122;
	A122=(Arbre) malloc(sizeof(NOEUD));
	A122->val=10;

	Arbre A1211;
	A1211=(Arbre) malloc(sizeof(NOEUD));
	A1211->val=10;

	Arbre A1221;
	A1221=(Arbre) malloc(sizeof(NOEUD));
	A1221->val=10;

	A1->filsGauche=A11;
	A1->filsDroit=A12;

	A11->filsGauche=A111;
	A11->filsDroit=A112;

	A111->filsGauche=A1111;
	A111->filsDroit=A1112;

	A112->filsGauche=A1121;
	A112->filsDroit=A1122;
	
	A12->filsDroit=A121;
	A12->filsDroit=A122;

	A121->filsGauche=A1211;
	A122->filsGauche=A1221;
//-------------------------------------------------------------	
	
int hauteur=hauteurArbre(A1);	
	printf("\nHauteur = %d \n",hauteur);

	if (equilibreArbre(A1)==1) printf("\nEquilibré");
	else printf("\nNon equilibré");

    return 0;
}
