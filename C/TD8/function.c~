#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include "modelStruct.h"

int hauteurArbre(Arbre N){

	int a=0,b=0,max=0;
	
	if(N==NULL) return 0;
	
	a=hauteurArbre(N->filsGauche);
	b=hauteurArbre(N->filsDroit);
	
	if(a>b) max=a+1;
	else max=b+1;

	return max;
}


int equilibreArbre(Arbre N){

	int a=0,b=0;
	
	if(N==NULL) return 1;
	a=hauteurArbre(N->filsGauche);
	b=hauteurArbre(N->filsDroit);
	
	if((a==b || a==b+1 || a+1==b) && equilibreArbre(N->filsGauche) && equilibreArbre(N->filsDroit)) return 1;
	else return 0;
}
