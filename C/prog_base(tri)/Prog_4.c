#include<stdio.h>
int main(){
	int a=1,tmp,tab[10]={5,6,8,4,2,6,9,4,7,5},i;

	while(a>0){
		a=0;
		for(i=1;i<10;i++){
			if(tab[i-1]>tab[i]){
				tmp=tab[i];
				tab[i]=tab[i-1];
				tab[i-1]=tmp;
				a++;
			} 
		}
	}
	


	printf("\n\n");
	for(i=0;i<10;i++){
		printf("\n%d",tab[i]);
	}

return 0;
}
