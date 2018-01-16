#include <stdio.h>
#include <stdlib.h>
#include "mediane.h"

double mediane(int tab[], int size){
	int a=1,i=0,tmp;
	while(a>0){
		a=0;
		for(i=1;i<size-1;i++){
			if(tab[i-1]>tab[i]){
				tmp=tab[i-1];
				tab[i-1]=tab[i];
				tab[i]=tmp;
				a++;
			}
		}
	}

	for(i=0;i<size;i++){
		printf("tab[%d] = %d\n",i,tab[i]);
	}	
	
	return tab[(size-1)/2];
}
