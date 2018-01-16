#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[]){
	int mat,maind;	
	float ht,ttc,taxe;		
	if(argv[2]==NULL){
		printf("\nVous devez mettre obligatoirement 2 entiers en parametre d'entrer\n");	
	}
	else{	
		mat=atoi(argv[1]);
		maind=atoi(argv[2]);
		ht=mat+maind;
		ttc=(mat+maind)*1.196;
		taxe=ttc-ht;
		printf("\nCout materiel : %d\nCout main d'oeuvre : %d\nPrix HT : %f\nTaxe : %f (taux de 19,600000)\nPrix TTC : %f\n",mat,maind,ht,taxe,ttc);
	}
return 0;
}
