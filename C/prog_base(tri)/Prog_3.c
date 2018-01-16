#include<stdio.h>
int factoriel(int);
int main(){
	int i,fact=1,n;
	printf("Saisir un nombre\n");
	scanf("%d",&n);
	fact=factoriel(n);
	printf("La factoriel de %d est %d\n",n,fact);
	return 0;
}
int factoriel(int n){
	if (n==0 || n==1)
		return 1;
	else
		n*=factoriel(n-1);
	return n;
}
