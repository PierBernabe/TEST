#include<stdio.h>
int estPremier(int nb){
	int i,som;
	som=0;
	for(i=1;i<nb;i++){
		if((nb%i)==0)				
			som++;
	}
	if(som>1)return 0;
	else return 1;	
}

int main(){
	int nb,total,j,res;
	total=0;
	printf("Saisir un nombre entier :\n");
	scanf("%d",&nb);
	res=estPremier(nb);
	if(res==0)printf("%d n'est pas premier\n",nb);
	else printf("%d est premier\n",nb);
	for(j=1;j<nb;j++){
		total+=estPremier(j);
	}
	printf("Il y a %d nombre premier avant %d\n",total,nb);
	return 0;
}
