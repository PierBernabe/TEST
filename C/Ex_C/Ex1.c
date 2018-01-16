#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[]){
	int n,i,somme;
	n=atoi(argv[1]);	
	for(i=1;i<n+1;i++){
		somme+=2*i-1;
	}
	printf("Le resultat est %d\n",somme);
	return 0;
}
