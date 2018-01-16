#include<stdio.h>
#include <stdlib.h>
void test1(char* c){
		if(c=='b') printf("Bonjour ");
		else if(c=='m') printf("Merci ");
		else if(c=='a') printf("au revoir ");
		else printf("Mot inconnu ");	
}
void test2(char* c, int i){
	int j;
	for(j=0;j<i;j++){
		if(c=='b') printf("Bonjour ");
		else if(c=='m') printf("Merci ");
		else if(c=='a') printf("au revoir ");
		else printf("Mot inconnu ");		
	}	
}

