#include <stdio.h>
#include <stdlib.h>

typedef struct cell{
	int val;
	struct cell *fDroit;
	struct cell *fGauche;
}CELL;

typedef CELL *ARBRE;

ARBRE creerABR(int val, ARBRE gauche, ARBRE droit){
	ARBRE abr;
	abr=(ARBRE)malloc(sizeof(CELL));
	abr->val=val;
	abr->fDroit=droit;
	abr->fGauche=gauche;

	return abr;
}

int affichage(ARBRE root){
	if(root==NULL) return 0;
	printf("\n%d",root->val);

	if((root->fGauche)!=NULL){
		
		affichage(root->fGauche);
	}

	if((root->fDroit)!=NULL){
		affichage(root->fDroit);
	}
	return 0;
}

void detruireABR(ARBRE root){
	
	



	
}
/*
void insererABR(ARBRE root,int val){
	if(root==NULL){
		ARBRE new;
		new=(ARBRE) malloc(sizeof(CELL));
		new->val=1;
		ARBRE->
	}
	else{
		if(val<root->val)){
			insererABR(root->fGauche,val);	
		}
		else{
			insererABR(root->fDroit,val);	

		}
	}
	
}*/

int main(void){
	
	//ARBRE A1;
	//A1=(ARBRE) malloc(sizeof(CELL));
	//A1->val=1;

	ARBRE A11;
	A11=(ARBRE) malloc(sizeof(CELL));
	A11->val=5;

	ARBRE A12;
	A12=(ARBRE) malloc(sizeof(CELL));
	A12->val=15;
	
	//A1->fDroit=A11;
	//A1->fGauche=A12;

	ARBRE A1=creerABR(10,A11,A12);

	affichage(A1);

	return 0;
}
