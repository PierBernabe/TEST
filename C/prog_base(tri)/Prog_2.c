#include<stdio.h>
int main(){
	int i,fact=1,n;
	printf("Saisir un nombre\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		fact*=i;
	}
	printf("La factorielle de %d est %d\n",n,fact);
	return 0;
}




