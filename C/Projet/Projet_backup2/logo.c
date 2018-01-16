#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(void){

	LOGO L0=creerNODE(2,90,0,0);
	LOGO F0=creerNODE(1,50,L0,0);
	LOGO F1=creerNODE(1,100,0,0);
	LOGO R0=creerNODE(4,4,0,F0);
	LOGO Racine=creerNODE(1,100,R0,0);

	afficherNode(Racine,0);





	return 0;
}
